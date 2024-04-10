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
const int N = 1e5 + 10;
const int INF = 1.01e9;
typedef vector<int> vi;
const int MOD = 1e9 + 7;
const int M = 11;


ll dp[N][M][3];
ll dpT[M][3];

void upd(ll& A, ll B) {
    A = (A + B) % MOD;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    } 
    int k, x;
    scanf("%d%d", &k, &x);

    vector<int> use(n);

    function<void(int)> dfs = [&](int v) {
        use[v] = 1;
        dp[v][1][0] = 1;
        dp[v][0][2] = 1;
        for (auto u: e[v]) {
            if (!use[u]) {
                dfs(u);
                memset(dpT, 0, sizeof dpT);
                //for (int i = x; i >= 0; i--) { // me 
                for (int i = 0; i <= x; i++) {
                    //for (int j = x - i; j >= 0; j--) { // child
                    for (int j = 0; j <= x - i; j++) {
                        upd(dpT[i + j][0], (dp[u][j][1] + dp[u][j][2]) * dp[v][i][0] % MOD * (k - 1));

                        upd(dpT[i + j][1], (dp[u][j][0] * dp[v][i][1]) % MOD);
                        upd(dpT[i + j][1], (dp[u][j][0] * dp[v][i][2]) % MOD);

                        upd(dpT[i + j][1], (dp[u][j][1] * dp[v][i][1]) % MOD * (k - 1));

                        upd(dpT[i + j][1], (dp[u][j][2] * dp[v][i][1]) % MOD * (m - 1));
                    
                        upd(dpT[i + j][2], (dp[u][j][2] * dp[v][i][2]) % MOD * (m - 1));
                        upd(dpT[i + j][2], (dp[u][j][1] * dp[v][i][2]) % MOD * (k - 1));
                    }
                }
                memcpy(dp[v], dpT, sizeof dpT);
            }
        }
        //for (int i = 0; i <= x; i++) {
            //upd(dp[v][i][1], dp[v][i][2]);
        //}
    };
    dfs(0);
    //for (int i = 0; i < n; i++, cerr << endl) {
        //for (int j = 0; j <= x; j++, cerr << endl) {
            //for (int t = 0; t <= 3; t++) {
                //cerr << dp[i][j][t] << " ";
            //}
        //}
    //}

    ll answer = 0;
    for (int i = 0; i <= x; i++) {
        upd(answer, dp[0][i][0] + dp[0][i][1] * (k - 1) + dp[0][i][2] * (m - 1));
    } 
    cout << answer << endl;
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}