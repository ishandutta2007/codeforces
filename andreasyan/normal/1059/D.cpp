#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;
const long long INF = 100005000000009;
struct ban
{
    long double x, y;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n;
ban a[N];

bool stg(long double r)
{
    long double y0;
    if (a[1].y > 0)
    {
        y0 = r;
    }
    else
    {
        y0 = -r;
    }
    long double l1 = -INF * 10, r1 = INF * 10;
    for (int i = 1; i <= n; ++i)
    {
        if (2 * y0 * a[i].y - a[i].y * a[i].y < 0)
            return false;
        long double l2 = -sqrt(2 * y0 * a[i].y - a[i].y * a[i].y) + a[i].x;
        long double r2 = sqrt(2 * y0 * a[i].y - a[i].y * a[i].y) + a[i].x;
        if (r1 > r2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        if (r1 < l2)
            return false;
        if (l1 < l2)
        {
            l1 = l2;
        }
    }
    return true;
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
    bool z = (a[1].y > 0);
    for (int i = 1; i <= n; ++i)
    {
        if ((a[i].y > 0) != z)
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    long double l = 0, r = INF;
    for (int ii = 0; ii < 500; ++ii)
    {
        long double m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }
    cout << l << endl;
    return 0;
}