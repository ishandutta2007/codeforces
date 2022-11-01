#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 5005;

vector<pair<int, int>> G[NMAX];
int dp[NMAX][NMAX];
bool solved[NMAX];

void solve(int node, int n) {
    if (solved[node]) {
        return;
    }
    solved[node] = true;
    for (const pair<int, int>& p: G[node]) {
        int to = p.first;
        int cost = p.second;
        solve(to, n);
        for (int i = 1; i <= n; ++i) {
            dp[node][i] = min(dp[node][i], dp[to][i - 1] + cost);
        }
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int INF = 0x3f3f3f3f;

    int n, m, T;
    cin >> n >> m >> T;

    for (int i = 0; i < m; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        x--; y--;
        G[x].push_back(make_pair(y, t));
    }

    memset(dp, INF, sizeof dp);
    dp[n - 1][1] = 0;
    solved[n - 1] = true;

    solve(0, n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[0][i] <= T) {
            ans = i;
        }
    }
    cout << ans << '\n';
    for (int node = 0, cnt = ans; node != n - 1; ) {
        cout << node + 1 << ' ';
        for (const pair<int, int>& p: G[node]) {
            int to = p.first;
            int cost = p.second;
            if (dp[node][cnt] == dp[to][cnt - 1] + cost) {
                node = to;
                cnt--;
                break;
            }
        }
    }
    cout << n << '\n';
}