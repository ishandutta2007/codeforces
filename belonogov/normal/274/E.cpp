#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 5e5;
const long long INF = 1e9 + 19;

struct pnt {
    int x, y;
    pnt() { }
    pnt(int x, int y) : x(x), y(y) { }
    bool operator < (const pnt & A) const {
        return x < A.x || (x == A.x && y < A.y);
    }
    bool operator == (pnt A) {
        return x == A.x && y == A.y;
    }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    int len() {
        assert(abs(x) == abs(y));
        return abs(x);
    }
};

int n, m, k;
vector < pnt > blocked;
set < pnt > b;
set < int > q1[N];
set < int > q2[N];
pnt st;
pnt v;
map < pair < pnt, pnt >, long long > history;

void read() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        blocked.pb(pnt(x, y));
    }
    int x, y;
    scanf("%d%d", &x, &y); x--; y--;
    st = pnt(x, y);
    string s;
    cin >> s;
   // NE, NW, SE  SW.     (-1,1), (-1,-1), (1,1), (1,-1).
    if (s == "NE")
        v = pnt(-1, 1);
    else if (s == "NW")
        v = pnt(-1, -1);
    else if (s == "SE")
        v = pnt(1, 1);
    else if (s == "SW")
        v = pnt(1, -1);
}

int get1(pnt O) {
    return O.x + O.y;
}

int get2(pnt O) {
    return n - 1 - O.x + O.y;
}

pnt getPoint(int p1, int p2) {
    int y = p1 + p2 - (n - 1);
    assert(y % 2 == 0);
    y /= 2;
    int x = p1 - p2 + (n - 1);
    assert(x % 2 == 0);
    x /= 2;
    return pnt(x, y);
}

bool inRange(int x) {
    return 0 <= x && x < n + m - 1;
}

long long solve() {
    for (int i = -1; i <= n; i++) {
        blocked.pb(pnt(i, -1));
        blocked.pb(pnt(i, m));
    }
    for (int i = 0; i < m; i++) {
        blocked.pb(pnt(-1, i));
        blocked.pb(pnt(n, i));
    }

    for (auto x: blocked)
        b.insert(x);

    for (auto p: blocked) {
        int p1 = get1(p);
        int p2 = get2(p);
        if (inRange(p1))
            q1[p1].insert(p2);
        if (inRange(p2))
            q2[p2].insert(p1);
    }
    long long answer = 0;
    bool flag = 0;
    for (;;) {
        //cerr << endl;
        //db2(st.x, st.y);
        //db2(v.x, v.y);
        //db(answer);
        if (history.count(mp(st, v))) {
            long long dist = answer - history[mp(st, v)];
            if (flag) {
                assert(dist % 2 == 0);
                dist /= 2;
            }
            return dist;
        }
        history[mp(st, v)] = answer;
        int p1 = get1(st);
        int p2 = get2(st);
        if (v == pnt(1, 1)) {
            auto it = q2[p2].lower_bound(p1);
            assert(it != q2[p2].end());
            pnt A = getPoint(*it, p2);
            answer += (A - st).len();
            assert(b.count(A) == 1);
            if (b.count(A + pnt(0, -1)) == b.count(A + pnt(-1, 0)))  {
                //db("here");
                //db2(A.x, A.y);
                st = A + pnt(-1, -1);
                v = pnt(-1, -1);
                flag = 1;
            }
            else if (b.count(A + pnt(0, -1)) == 1) {
                st = A + pnt(-1, 0);
                v = pnt(-1, 1);
            }
            else {
                st = A + pnt(0, -1);
                v = pnt(1, -1);
            }
        }
        else if (v == pnt(-1, -1)) {
            auto it = q2[p2].lower_bound(p1);
            assert(it != q2[p2].begin());
            it--;
            pnt A = getPoint(*it, p2);
            answer += (A - st).len();
            assert(b.count(A) == 1);
            if (b.count(A + pnt(1, 0)) == b.count(A + pnt(0, 1))) {
                st = A + pnt(1, 1);
                v = pnt(1, 1);
                flag = 1;
            }
            else if (b.count(A + pnt(0, 1)) == 1) {
                st = A + pnt(1, 0);
                v = pnt(1, -1);
            }
            else {
                st = A + pnt(0, 1);
                v = pnt(-1, 1);
            }
        }
        else if (v == pnt(-1, 1)) {
            auto it = q1[p1].lower_bound(p2);
            assert(it != q1[p1].end());
            pnt A = getPoint(p1, *it);
            answer += (A - st).len();
            assert(b.count(A) == 1);
            if (b.count(A + pnt(0, -1)) == b.count(A + pnt(1, 0))) {
                st = A + pnt(1, -1);
                v = pnt(1, -1); 
                flag = 1;
            }
            else if (b.count(A + pnt(0, -1)) == 1) {
                st = A + pnt(1, 0);
                v = pnt(1, 1);
            }
            else {
                st = A + pnt(0, -1);
                v = pnt(-1, -1);
            }
        }
        else if (v == pnt(1, -1)) {
            auto it = q1[p1].lower_bound(p2);
            assert(it != q1[p1].begin());
            it--;
            pnt A = getPoint(p1, *it);
            answer += (A - st).len();
            assert(b.count(A) == 1);
            if (b.count(A + pnt(-1, 0)) == b.count(A + pnt(0, 1)))  {
                st = A + pnt(-1, 1);
                v = pnt(-1, 1);
                flag = 1;
            }
            else if (b.count(A + pnt(-1, 0)) == 1) {
                st = A + pnt(0, 1);
                v = pnt(1, 1);
            }
            else if (b.count(A + pnt(0, 1)) == 1) {
                st = A + pnt(-1, 0);
                v = pnt(-1, -1);
            }
        }
    }

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            long long res = solve();
            cout << res << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}