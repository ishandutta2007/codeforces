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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;

int n, x, y;
int deg[N];
vector < int > e[N];
int dp[N][2];
bool use[N];

void read() {
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);  v--; u--;
        e[v].pb(u);
        e[u].pb(v);
        deg[v]++;
        deg[u]++;
    }
}

void dfs(int v) {
    use[v] = 1;
    int sum0 = 0;
    int cnt = 0;
    for (auto u: e[v]) {
        if (!use[u]) {
            dfs(u);
            sum0 += dp[u][0];
            assert(dp[u][0] <= dp[u][1] && dp[u][1] <= dp[u][0] + 1);
            cnt += dp[u][0] == dp[u][1];
        }
    }
    //cerr << "v sum cnt: " << v << " " << sum0 << " " << cnt << endl;
    dp[v][1] = min(dp[v][1], sum0 + 1);
    if (cnt >= 1)
        dp[v][1] = min(dp[v][1], sum0);



    dp[v][0] = min(dp[v][0], sum0 + 1);
    if (cnt >= 1)
        dp[v][0] = min(dp[v][0], sum0);

    if (cnt >= 2)
        dp[v][0] = min(dp[v][0], sum0 - 1);


}

void solve() {
    if (y < x) {
        bool flag = 0;
        for (int i = 0; i < n; i++)
            flag |= deg[i] == n - 1;
        long long answer = y * 1ll * (n - 1);
        if (flag)
            answer = answer - y + x; 
        cout << answer << endl;
        return;
    }
    memset(dp, 63, sizeof(dp));
    dfs(0); 
    //for (int i = 0; i < n; i++)
        //cerr << dp[i][0] << " " << dp[i][1] << endl;

    cout << y * 1ll * (dp[0][0] - 1) + x * 1ll * (n - 1 - (dp[0][0] - 1)) << endl;


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
        }
    }
    else {
        stress();
    }

    return 0;
}