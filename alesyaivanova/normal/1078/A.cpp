#include <bits/stdc++.h>

using namespace std;

#define int long double

struct point
{
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {};

    point operator-(point b)
    {
        return {x - b.x, y - b.y};
    }
};

int mod(point p)
{
    return hypot(abs(p.x), abs(p.y));
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    point p1, p2;
    cin >> a >> b >> c >> p1.x >> p1.y >> p2.x >> p2.y;
    cout.precision(20);
    if (a == 0 || b == 0)
    {
        cout << fixed << abs(p1.x - p2.x) + abs(p1.y - p2.y);
        return 0;
    }
    point k1(p1.x, -(a * p1.x + c) / b);
    point k2(-(b * p1.y + c) / a, p1.y);
    point k3(p2.x, -(a * p2.x + c) / b);
    point k4(-(b * p2.y + c) / a, p2.y);
    int ans = abs(p1.y - k1.y) + mod(k3 - k1) + abs(p2.y - k3.y);
    ans = min(ans, abs(p1.x - k2.x) + mod(k3 - k2) + abs(p2.y - k3.y));
    ans = min(ans, abs(p1.y - k1.y) + mod(k4 - k1) + abs(p2.x - k4.x));
    ans = min(ans, abs(p1.x - k2.x) + mod(k4 - k2) + abs(p2.x - k4.x));
    ans = min(ans, abs(p1.x - p2.x) + abs(p1.y - p2.y));
    cout << fixed << ans;
}