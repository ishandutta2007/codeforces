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
#define sz(a) (int)a.size()

#define equal equalll
#define less lesss
const int N = 3e5 + 10;
const long long INF = 1e12 + 19;
typedef long long ll;
//const int dx[4] = {1, -1, -1, 1};
//const int dy[4] = {1, 1, -1, -1};

struct pt {
    int x, y;
    pt () { }
    pt (int x, int y):x(x), y(y) { }
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    pt operator * (int k) {
        return pt(x * k, y * k);
    }
    int len() {
        assert(abs(x) == abs(y));
        return abs(x);
    }
    void Epr() {
        cerr << "x y: " << x << " " << y << endl;
    }
};

int n, m, k;
ll answer[N];
vector<int> xpy[N];
vector<int> xmy[N];
pt p[N];
int shift;

void read() {
    scanf("%d%d%d", &n, &m, &k);
    shift = max(n, m) + 2;
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = pt(x, y);
        xpy[x + y].pb(i);
        xmy[x - y + shift].pb(i);
    }
}

bool inside(pt A) {
    return 0 <= A.x && A.x <= n && 0 <= A.y && A.y <= m;
}

void solve() {
    pt O(0, 0);
    memset(answer, 63, sizeof(answer));
    pt v(1, 1);
    ll tmr = 0;
    for (;;) {
        vector<int> upd;
        if (v.x + v.y == 0) 
            upd = xpy[O.x + O.y];
        else
            upd = xmy[O.x - O.y + shift];
        for (auto id: upd)
            answer[id] = min(answer[id], (O - p[id]).len() + tmr);
            

        int l = 0;     
        int r = shift;
        //db(shift);
        while (r - l > 1) {
            pt A = O + v * ((l + r) / 2);
            if (inside(A))
                l = (l + r) / 2;
            else
                r = (l + r) / 2;
        }    
        //O.Epr();
        //v.Epr();
        //pt A = O + v * 2;
        //A.Epr();
        //db(inside(A));
        //db2(l, r);
        //if (l == 1) exit(0);
        
        O = O + v * l;
        if (O.x == n && O.y == m) break;
        if (O.x == 0 && O.y == m) break;
        if (O.x == n && O.y == 0) break;
        if (O.x == 0 && O.y == 0) break;
        
        if (O.x != 0 && O.x != n)
            v.y *= -1;
        else
            v.x *= -1;
        //db(l);
        //O.Epr();
        //v.Epr();
        //cerr << endl;
        assert(l > 0);
        tmr += l;
        //db(tmr);
    }

    for (int i = 0; i < k; i++)
        if (answer[i] < INF)
            printf("%lld\n", answer[i]);
        else
            puts("-1");

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
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}