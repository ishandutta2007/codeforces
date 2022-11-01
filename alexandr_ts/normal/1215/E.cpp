#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e15 + 10;
const ld EPS = 1e-8;
const ld PI = acos(-1);
const int M = 20;
const int N = 1e6 + 10;

int a[N];
vector<int> g[M];
ll cnt[M][M];
ll dp[1 << M];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        g[a[i] - 1].push_back(i);
    }

    for (int c1 = 0; c1 < M; ++c1) {
        for (int c2 = 0; c2 < M; ++c2) {
            if (c1 == c2) {
                continue;
            }
            int cur = 0;
            for (int i = 0; i < (int)g[c1].size(); ++i) {
                while ((int)g[c2].size() > cur && g[c2][cur] < g[c1][i]) {
                    cur++;
                    cnt[c1][c2] += ((int)g[c1].size() - i);
                }
            }
        }
    }

    fill(dp + 1, dp + (1 << M), INF);
    for (int mask = 0; mask < (1 << M); ++mask) {
        for (int color = 0; color < M; ++color) {
            if (mask & (1 << color)) {
                continue;
            }
            ll add = 0;
            for (int i = 0; i < M; ++i) {
                if (mask & (1 << i)) {
                    add += cnt[i][color];
                }
            }
            dp[mask | (1 << color)] = min(dp[mask | (1 << color)], dp[mask] + add);
        }
    }

    cout << dp[(1 << M) - 1] << "\n";

}

int main() {
    //freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}