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
#define forn(i, n) for (int i = 0; i < (n); i++)
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
    vector<int> p(n * 2, -1);
    vector<vector<int>> e(n * 2);
    forn(i, n) {
        int v, u;
        scanf("%d%d", &v, &u);
        v--; u--;
        p[v] = u;
        e[u].pb(v);
    }
    int cnt = 0;

    vector<int> use(n * 2);
    function<void(int)> dfs = [&](int v) {
        cnt++;
        use[v] = 1;
        for (auto u: e[v]) {
            if (!use[u])
                dfs(u);
        }
    };

    ll answer = 1;
    forn(i, n * 2) {
        if (p[i] == -1) {
            cnt = 0;
            dfs(i);
            answer = (answer * cnt) % MOD;
        }
        if (p[i] == i) {
            dfs(i);
        }
    }
    vector<int> par(n * 2);
    forn(i, n * 2) {
        par[i] = i;
    }
    function<int(int)> getId = [&](int v) {
        return (par[v] == v)? v: par[v] = getId(par[v]);
    };
    //forn(i, n * 2) {
        //db2(use[i], p[i]);
    //}

    forn(i, n * 2) {
        if (p[i] != -1 && !use[i]) {
            int v = i;
            int u = p[i];
            v = getId(v);
            u = getId(u);
            if (v == u) {
                answer = (answer * 2) % MOD;
            }
            else {
                par[v] = u;
            }
            //int v = i;
            //int cc = 0;
            //for (;!use[v]; v = p[v]) {
                //use[v] = 1;
                //cc++;
            //}
            //if (cc > 1)
        }
    }



    cout << answer << endl;
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}