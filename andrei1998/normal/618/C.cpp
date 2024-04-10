#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

struct point {
    int x, y;
    int pos;
} points[100005];

bool operator<(const point &a, const point &b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

lint ccw(const point &a, const point &b, const point &c) {
    return 1ll * (a.x - b.x) * (c.y - b.y) - 1ll * (a.y - b.y) * (c.x - b.x);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin >> points[i].x >> points[i].y;
        points[i].pos = i;
    }
    sort(points + 1, points + n + 1);

    for (int i = 3; i <= n; ++ i)
        if (ccw(points[1], points[2], points[i])) {
            cout << points[1].pos << ' ' << points[2].pos << ' ' << points[i].pos << '\n';
            return 0;
        }

    return 0;
}