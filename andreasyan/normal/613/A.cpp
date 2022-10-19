#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n;
pair<long double, long double> p;
pair<long double, long double> a[N];

long double mind, maxd;

long double dist(pair<long double, long double> t1, pair<long double, long double> t2)
{
    return sqrt((t1.first - t2.first) * (t1.first - t2.first) + (t1.second - t2.second) * (t1.second - t2.second) + 0.0);
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    cin >> n >> p.first >> p.second;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;

    mind = dist(a[0], p);
    maxd = mind;
    for (int i = 1; i < n; ++i)
    {
        mind = min(mind, dist(p, a[i]));
        maxd = max(maxd, dist(p, a[i]));
    }

    for (int i = 0; i < n; ++i)
    {
        long double x0 = p.first;
        long double y0 = p.second;
        long double x1 = a[i].first;
        long double y1 = a[i].second;
        long double x2 = a[(i + 1) % n].first;
        long double y2 = a[(i + 1) % n].second;

        long double k;
        long double b;

        if (x1 != x2 && y1 != y2)
        {
            k = (y2 - y1) / (x2 - x1);
            b = y1 - k * x1;
        }

        long double k1;
        long double b1;

        if (x1 != x2 && y1 != y2)
        {
            k1 = (-1 / k);
            b1 = (y0 - k1 * x0);
        }

        long double x;
        long double y;

        if (x1 != x2 && y1 != y2)
        {
            x = (b1 - b) / (k - k1);
            y = k * x + b;
        }
        else
        {
            if (x1 == x2)
            {
                x = x1;
                y = y0;
            }
            else
            {
                x = x0;
                y = y1;
            }
        }

        if (min(x1, x2) <= x && x <= max(x1, x2) && min(y1, y2) <= y && y <= max(y1, y2))
            mind = min(mind, dist(p, m_p(x, y)));
    }
    cout << acos(-1) * maxd * maxd - acos(-1) * mind * mind << endl;
    return 0;
}