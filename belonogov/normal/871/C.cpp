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
const int MOD = 1e9 + 7;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> x(n);
    vector<int> y(n);
    map<int, vector<int>> X;
    map<int, vector<int>> Y; 
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        X[x[i]].pb(i);
        Y[y[i]].pb(i);
    }
    vector<int> p;
    vector<int> sz;
    sz.assign(n, 1);
    for (int i = 0; i < n; i++) {
        p.pb(i);
    }

    function<int(int)> getId = [&](int v) {
        return p[v] == v? v: p[v] = getId(p[v]);
    };
    
    auto merge = [&](int v, int u) {
        //if (v == u
        v = getId(v);
        u = getId(u);
        if (v == u) return;
        p[v] = u;
        sz[u] += sz[v];
    };

    for (int tt = 0; tt < 2; tt++) {
        for (auto q: X) {
            auto f = q.S;
            for (auto val: f) {
                merge(val, f[0]);
            }
        }
        swap(X, Y);
    }



    vector<int> deg;
    deg.pb(1);
    for (int i = 0; i < n + 3; i++) {
        deg.pb(deg.back() * 2 % MOD);
    }

    ll answer = 1;
    for (int i = 0; i < n; i++) {
        if (p[i] == i) {
                   }
    }
    vector<vector<int>> e(n);
    for (int i = 0; i < n; i++) {
        if (p[i] != i) {
            e[p[i]].pb(i);
        }
    }

    set<int> allx;
    set<int> ally;
    //db("!!!");
    function<void(int)> dfs3 = [&](int v) {
        allx.insert(x[v]);
        ally.insert(y[v]);
        for (auto u: e[v]) {
            dfs3(u);
        }
    };

    for (int i = 0; i < n; i++) {
        if (i == p[i]) {
            allx.clear();
            ally.clear();
            dfs3(i);
            int comb = allx.size() + ally.size();
            //db(comb);
            bool flag = sz[i] >= comb;
            if (flag) {
                answer = (answer * deg[comb]) % MOD;
            } 
            else {
                answer = (answer * (deg[comb] - 1 + MOD)) % MOD;
            }
        
        }
    }




    cout << answer << endl;
    //dbv(p);



    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}