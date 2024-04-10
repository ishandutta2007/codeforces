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



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);   
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    vector<vector<pair<int,int>>> e(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb({u, i});
        e[u].pb({v, i});
    }

    vector<int> odd; 
    vector<int> color(n, -1);
    int V = -1;
    vector<pair<int,int>> st;
    function<void(int, int, int)> dfs0 = [&](int v, int eid, int cc) {
        st.pb({v, eid});
        color[v] = cc;
        for (auto x: e[v]) {
            int u = x.F;
            if (color[u] == -1) {
                dfs0(u, x.S, cc ^ 1);
                if (!odd.empty()) return;
            }
            else {
                if (color[u] != (cc ^ 1)) {
                    odd.pb(x.S); 
                    for (int j = st.size() - 1; st[j].F != u; j--) {
                        odd.pb(st[j].S);
                    }
                    V = u;
                    return;
                }
            }
        }
        st.pop_back();
    };

    dfs0(0, -1, 0);

    vector<ll> answer(m);
    
    vector<int> used(n);
    function<void(int)> dfs1 = [&](int v) {
        used[v] = 1;
        for (auto x: e[v]) {
            int u = x.F;
            if (!used[u]) {
                dfs1(u);            
                ll y = c[u];
                c[v] -= y;
                c[u] -= y;
                answer[x.S] += y;
            }
        }
    };
    //db(odd.size());
    
    if (V == -1) {
        V = 0;
    }
    
    dfs1(V);
    if (c[V] != 0) {
        if (odd.empty()) {
            puts("NO");
            return 0;
        }
        //db(c[V]);
        assert(c[V] % 2 == 0);
        assert(odd.size() % 2 == 1);
        ll add = c[V] / 2;
        for (int i = 0; i < sz(odd); i++) {
            if (i % 2 == 1) {
                answer[odd[i]] -= add;
            } 
            else {
                answer[odd[i]] += add;
            }
        }
    }

    puts("YES");
    for (auto x: answer) {
        printf("%lld\n", x);
    }





    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}