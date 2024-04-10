#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int64_t LINF = 1LL << 62;

struct Point {
    int x, y;
    bool operator<(const Point& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

inline int64_t cross(const Point& o, const Point& a, const Point& b) {
    return (a.x - o.x) * (int64_t) (b.y - o.y) -
           (a.y - o.y) * (int64_t) (b.x - o.x);
}


int64_t solve(vector<Point> a, int m) {
    int n = SZ(a);
    Point o = a[0];
    sort(a.begin() + 1, a.end(), [o](const Point& a, const Point& b) {
        return cross(o, a, b) > 0;
    });
    vector<vector<int>> works(n);
    vector<vector<vector<int64_t>>> dp(n);
    works[0] = {0};
    dp[0] = vector<vector<int64_t>>(1, vector<int64_t>(m + 1, -LINF));
    dp[0][0][1] = 0;
    int64_t ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j > 0; --j) {
            if (works[i].empty() || cross(a[i], a[works[i].back()], a[j]) < 0) {
                works[i].push_back(j);
            }
        }
        works[i].push_back(0);
        reverse(works[i].begin(), works[i].end());
        dp[i] = vector<vector<int64_t>>(SZ(works[i]), vector<int64_t>(m + 1, -LINF));
        for (int j = 0; j < SZ(works[i]); ++j) {
            int prev = works[i][j];
            int pos = 0, step = 1;
            while (step < SZ(works[prev])) {
                step *= 2;
            }
            for (; step > 0; step /= 2) {
                if (pos + step < SZ(works[prev]) &&
                        cross(a[i], a[prev], a[works[prev][pos + step]]) <= 0) {
                    pos += step;
                }
            }
            for (int k = 2; k <= m; ++k) {
                dp[i][j][k] = max(j == 0 ? -LINF: dp[i][j - 1][k],
                        dp[prev][pos][k - 1] + cross(o, a[prev], a[i]));
            }
        }
        ans = max(ans, dp[i].back().back());
    }
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(), a.end());
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, solve(vector<Point>(a.begin() + i, a.end()), m));
    }
    cout << ans / 2;
    if (ans % 2 == 0) {
        cout << ".00\n";
    } else {
        cout << ".50\n";
    }
}