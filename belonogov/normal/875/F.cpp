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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;

struct Girl {
    int w, v, u;
};


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Girl> g;
    for (int i = 0; i < m; i++) {
        int w, v, u;
        scanf("%d%d%d", &v, &u, &w); v--; u--;
        g.pb({w, v, u});
    }
    sort(all(g), [](Girl A, Girl B) {
            return A.w > B.w;
            });
    vector<int> p(n);
    vector<int> type(n, 0);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    function<int(int)> getId = [&](int v) {
        return p[v] == v? v: p[v] = getId(p[v]);
    };
    ll answer = 0;
    for (auto x: g) {
        //db(x.w);
        int vv = getId(x.v);
        int uu = getId(x.u);
        if (vv == uu) {
            if (type[vv] == 0) {
                type[vv] = 1;
                answer += x.w;
            }
        }
        else {
            int sum = type[vv] + type[uu];
            if (sum < 2) {
                p[vv] = uu;
                type[uu] = sum;
                answer += x.w;
            }
        }
    }
    cout << answer << endl;

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}