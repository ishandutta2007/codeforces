#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int64_t INF = 1LL << 40;

struct Point {
    int64_t x, y;

    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Point> points(n + 2);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;

        points[i].x = x + y;
        points[i].x *= 2;
        points[i].y = x - y;
        points[i].y *= 2;
    }
    points[0].x = -INF;
    points[n + 1].x = INF;

    sort(points.begin() + 1, points.end() - 1);
    vector<int64_t> minyl(n + 2), maxyl(n + 2);
    vector<int64_t> minyr(n + 2), maxyr(n + 2);

    minyl[0] = INF;
    maxyl[0] = -INF;
    for (int i = 1; i <= n; ++i) {
        minyl[i] = min(minyl[i - 1], points[i].y);
        maxyl[i] = max(maxyl[i - 1], points[i].y);
    }

    minyr[n + 1] = INF;
    maxyr[n + 1] = -INF;
    for (int i = n; i > 0; --i) {
        minyr[i] = min(minyr[i + 1], points[i].y);
        maxyr[i] = max(maxyr[i + 1], points[i].y);
    }

    int64_t ans = 1LL << 48;
    for (int64_t step = 1LL << 48; step > 0; step /= 2) {
        if (ans - step < 0) continue;

        int64_t mdist = ans - step;
        bool can = false;
        for (int i = 1, j = 1; i <= n; ++i) {
            while (j <= n && (points[j].x - points[i].x) <= 2 * mdist) {
                j++;
            }
            int64_t miny = min(minyl[i - 1], minyr[j]);
            int64_t maxy = max(maxyl[i - 1], maxyr[j]);
            if (maxy - miny <= 2 * mdist) {
                can = true;
                break;
            }
        }

        if (can) {
            ans -= step;
        }
    }

    cout << ans / 2;
    if (ans % 2 == 1) cout << ".5";
    cout << '\n';
}