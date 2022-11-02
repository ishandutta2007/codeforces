#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 509;
int f[maxn][maxn];
int inf = 1e18;
int d[maxn][maxn];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int find_dist(int x, int y) {
    for (int i = 0; i < 2 * n; i++) {
        for (int e = 0; e < 2 * n; e++) {
            d[i][e] = inf;
        }
    }
    d[x][y] = f[x][y];
    priority_queue<pair<int, pii> > q;
    q.emplace(-d[x][y], mp(x, y));
    while (!q.empty()) {
        int cur_d = -q.top().ff;
        int x = q.top().ss.ff;
        int y = q.top().ss.ss;
        q.pop();
        if (cur_d != d[x][y]) {
            continue;
        }
        for (int j = 0; j < 4; j++) {
            int x1 = (x + dx[j] + 2 * n) % (2 * n);
            int y1 = (y + dy[j] + 2 * n) % (2 * n);
            if (d[x1][y1] > d[x][y] + f[x1][y1]) {
                d[x1][y1] = d[x][y] + f[x1][y1];
                q.emplace(-d[x1][y1], mp(x1, y1));
            }
        }
    }
    int mi = inf;
    for (int i = n; i < 2 * n; i++) {
        for (int e = n; e < 2 * n; e++) {
            mi = min(mi, d[i][e]);
        }
    }
    return mi;
}

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int e = 0; e < 2 * n; e++) {
            cin >> f[i][e];
            if (i >= n && e >= n) {
                sum += f[i][e];
                f[i][e] = 0;
            }
        }
    }
    int mi = inf;
    mi = min(mi, find_dist(0, n));
    mi = min(mi, find_dist(0, 2 * n - 1));
    mi = min(mi, find_dist(n - 1, n));
    mi = min(mi, find_dist(n - 1, 2 * n - 1));
    mi = min(mi, find_dist(n, 0));
    mi = min(mi, find_dist(n, n - 1));
    mi = min(mi, find_dist(2 * n - 1, 0));
    mi = min(mi, find_dist(2 * n - 1, n - 1));
    sum += mi;
    cout << sum << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}