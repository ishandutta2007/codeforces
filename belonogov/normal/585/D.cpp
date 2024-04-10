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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 111;
const int INF = 1e9 + 19;
long long shift = 5e8;
long long BASE = 1e9;

int n;
int a[N][3];
//unordered_map < pair < int, int >, int > q;
unordered_map < long long, int > q;
unordered_map < long long, vector < int > > how;
vector < int > path;
int answer;




bool exist;
vector < int > ser;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
}

pair < int, int > calcD(vector < int > b) {
    return mp(b[1] - b[0], b[2] - b[1]);
}

long long code(pair < int, int > f) {
    f.fr += shift;
    f.sc += shift;
    return f.fr * BASE + f.sc;
}

//pair < int, int > decode(long long r) {
    //int y = r % BASE; 
    //int x = r / BASE;
    //x -= shift; 
    //y -= shift;
    //return mp(x, y);
//}

void rec1(int cur, int all, vector < int > b) {
    if (cur == all) {
        auto tmp = calcD(b);
        long long h = code(tmp);
        if (q.count(h) == 0) {
            q[h] = b[0];
            how[h] = path;
        }
        if (q[h] < b[0]) {
            q[h] = b[0];
            how[h] = path;
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        auto c = b;
        for (int j = 0; j < 3; j++) {
            if (i != j)
                c[j] += a[cur][j];
        }
        path.pb(i);
        rec1(cur + 1, all, c);
        path.pop_back();
    }

}

void rec2(int cur, int all, vector < int > b) {
    if (cur == all) {
        auto tmp = calcD(b); 
        tmp.fr *= -1;
        tmp.sc *= -1;
        long long h = code(tmp);
        if (q.count(h) == 1) {
            if (!exist || answer < q[h] + b[0]) {
                answer = q[h] + b[0];
                exist = 1;
                ser = how[h];
                for (auto x: path)
                    ser.pb(x);
            }
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        auto c = b;
        for (int j = 0; j < 3; j++) {
            if (i != j)
                c[j] += a[cur][j];
        }
        path.pb(i);
        rec2(cur + 1, all, c);
        path.pop_back();
    }

}


void solve() {
    exist = 0;
    rec1(0, n / 2, vector < int > (3));
    assert(path.empty());
    rec2(n / 2, n, vector < int > (3));
    if (!exist) {
        puts("Impossible");
    }
    else {
        for (auto x: ser) {
            if (x == 0) puts("MW");
            if (x == 1) puts("LW");
            if (x == 2) puts("LM");
        }
        //db(answer);
    }
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}