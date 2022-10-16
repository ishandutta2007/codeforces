#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int NMAX = 300 + 5;

int N;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0):
        x(_x), y(_y) {}
} points[NMAX];

int ccw(const Point &a, const Point &rf, const Point &b) {
    return (a.x - rf.x) * (b.y - rf.y) - (a.y - rf.y) * (b.x - rf.x);
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> points[i].x >> points[i].y;

    int ans = -1;
    for (int i = 1; i <= N; ++ i)
        for (int j = i + 1; j <= N; ++ j) {
            int best1 = -1;
            for (int k = 1; k <= N; ++ k)
                if (k != i && k != j && ccw(points[i], points[j], points[k]) < 0)
                    best1 = max(best1, -ccw(points[i], points[j], points[k]));

            int best2 = -1;
            for (int k = 1; k <= N; ++ k)
                if (k != i && k != j && ccw(points[i], points[j], points[k]) > 0)
                    best2 = max(best2, ccw(points[i], points[j], points[k]));

            if (best1 > 0 && best2 > 0)
                ans = max(ans, best1 + best2);
        }

    cout << fixed << setprecision(6) << ans * 0.5 << '\n';
    return 0;
}