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
    int n;
    scanf("%d", &n);   
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    int st;
    scanf("%d", &st); st--;
    k[st]++;
    vector<ll> dp(n);
    vector<ll> remk(n);

    function<void(int, int)> dfs = [&](int v, int p) {
        remk[v] = k[v];
        remk[v]--;
        dp[v]++;
        vector<pair<ll,ll>> ch;
        for (auto u: e[v]) {
            if (u == p) continue;
            dfs(u, v);
            ch.pb({dp[u], remk[u]});
        }
        sort(all(ch));
        reverse(all(ch));
        for (auto& x: ch) {
            if (remk[v] > 0) {
                dp[v] += x.F;
                dp[v]++;
                remk[v]--;
            }
        }

        for (auto& x: ch) {
            ll c = min(remk[v], x.S); 
            remk[v] -= c;
            dp[v] += c * 2;
            x.S -= c;
        }

    };

    dfs(st, -1);
    //for (int i = 0; i < n; i++) {
        //db3(i, dp[i], remk[i]);
    //}
    cout << dp[st] - 1 << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}