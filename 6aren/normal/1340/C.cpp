#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int INF = 1000000000;
const int N = 10005;

int dp[N][1005];
int d[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> d[i];
    int g, r; cin >> g >> r;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < g; j++) dp[i][j] = INF;
    }
    sort(d + 1, d + m + 1);
    dp[1][0] = 0;
    deque<ii> dq;
    dq.push_front({1, 0});
    while (!dq.empty()) {
        auto u = dq.front(); dq.pop_front();
        int id = u.x;
        int dis = u.y;
        if (id > 1) {
            int foo = dis + d[id] - d[id - 1];
            if (foo > g) {}
            else if (foo == g) {
                if (dp[id - 1][0] == INF) {
                    dp[id - 1][0] = dp[id][dis] + 1;
                    dq.push_back({id - 1, 0});
                }
            } else {
                if (dp[id - 1][foo] == INF) {
                    dp[id - 1][foo] = dp[id][dis];
                    dq.push_front({id - 1, foo});
                }
            }
        }
        if (id < m) {
            int foo = dis + d[id + 1] - d[id];
            if (foo > g) {}
            else if (foo == g) {
                if (dp[id + 1][0] == INF) {
                    dp[id + 1][0] = dp[id][dis] + 1;
                    dq.push_back({id + 1, 0});
                }
            } else {
                if (dp[id + 1][foo] == INF) {
                    dp[id + 1][foo] = dp[id][dis];
                    dq.push_front({id + 1, foo});
                }
            }
        }
    }
    // cout << dp[2][3] << endl;
    int period = g + r;
    long long ans = 1e18;
    bool ok = 0;
    for (int i = 1; i <= m; i++) {
        if (d[m] - d[i] <= g) {
            ans = min(ans, 1LL * dp[i][0] * period + d[m] - d[i]);
            if (dp[i][0] != INF) ok = 1;
        }
    }
    cout << (ok ? ans : -1);
    return 0;
}