#include <bits/stdc++.h>
using namespace std;
struct ban
{
    long double x, y;
    ban()
    {
        x = y = 0;
    }
    ban(long double x, long double y)
    {
        this->x = x;
        this->y = y;
    }
};

long double a, b, c;

long double xx(long double y)
{
    return -1.0 * (b * y + c) / a;
}
long double yy(long double x)
{
    return -1.0 * (a * x + c) / b;
}
long double dist(ban a, ban b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ban t1, t2;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    cin >> a >> b >> c;
    cin >> t1.x >> t1.y >> t2.x >> t2.y;

    ban ht1[2];
    ht1[0] = ban(t1.x, yy(t1.x));
    ht1[1] = ban(xx(t1.y), t1.y);

    ban ht2[2];
    ht2[0] = ban(t2.x, yy(t2.x));
    ht2[1] = ban(xx(t2.y), t2.y);

    long double ans = abs(t1.x - t2.x) + abs(t1.y - t2.y);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            ans = min(ans, dist(t1, ht1[i]) + dist(ht1[i], ht2[j]) + dist(ht2[j], t2));
        }
    }

    cout << ans << endl;
    return 0;
}