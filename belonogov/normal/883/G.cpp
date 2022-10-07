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
const int N = 3e5 +10;
const int INF = 1.01e9;
typedef vector<int> vi;


struct Edge {
    int u, id;
    char ch;
};

vector<int> e[N];
vector<Edge> g[N];
string ans1;
string ans2;
int r1, r2;
vector<int> use;

void dfs1(int v) {
    use[v] = 1;
    r1++;
    for (auto u: e[v]) {
        if (!use[u]) {
            dfs1(u);
        }
    }

    for (auto x: g[v]) {
        int u = x.u;
        if (!use[u]) {
            ans1[x.id] = x.ch;
            dfs1(u);
        }
    }
}

void dfs2(int v) {
    use[v] = 1;
    r2++;
    for (auto u: e[v]) {
        if (!use[u]) {
            dfs2(u);
        }
    }
}

vector<pair<int,int>> ee;

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m, s; 
    scanf("%d%d%d", &n, &m, &s); s--;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        int t, v, u;
        scanf("%d%d%d", &t, &v, &u); v--; u--;
        if (t == 1) {
            e[v].pb(u);            
        } 
        else {
            g[v].pb({u, cur, '+'});
            g[u].pb({v, cur, '-'});
            ee.pb({v, u});
            cur++;
        }
    }
    ans1.assign(cur, '-');
    use.assign(n, 0);
    dfs1(s);
    //db(r1);

    use.assign(n, 0);
    dfs2(s);
    //for (auto x: ee) {
    for (int i = 0; i < sz(ee); i++) {
        auto x = ee[i];
        if (use[x.F] != use[x.S]) {
            if (use[x.F]) {
                ans2.pb('-'); 
            }
            else {
                ans2.pb('+'); 
            }
        }
        else {
            ans2.pb('-');
        }
    }
    //db(r1);

    cout << r1 << endl; 
    cout << ans1 << endl;

    cout << r2 << endl; 
    cout << ans2 << endl;
    
    

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}