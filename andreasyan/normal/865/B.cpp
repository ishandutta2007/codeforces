#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    long long s, a, b;
};
bool operator<(const ban& a, const ban& b)
{
    return (a.a - a.b) > (b.a - b.b);
}

int n;
long long s;
ban a[N];
long long sum;

long long ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].s >> a[i].a >> a[i].b;
        sum += a[i].s;
    }
    sort(a, a + n);

    //////////////////////////////////////////////////

    long long t = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].a - a[i].b > 0)
            t += a[i].s;
    }

    long long yans = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i].a - a[i].b > 0)
            yans += (a[i].a * a[i].s);

    }

    long long tt = (((sum / s) + !!(sum % s)) - ((t / s) + !!(t % s))) * s;

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i].a - a[i].b <= 0)
        {
            if (tt > a[i].s)
            {
                tt -= a[i].s;
                yans += (a[i].b * a[i].s);
            }
            else
            {
                yans += (a[i].b * tt);
                yans += (a[i].a * (a[i].s - tt));
                tt = 0;
            }
        }
    }

    ans = yans;

    //////////////////////////////////////////////////

    t = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i].b - a[i].a > 0)
            t += a[i].s;
    }

    yans = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i].b - a[i].a > 0)
            yans += (a[i].b * a[i].s);
    }

    tt = (((sum / s) + !!(sum % s)) - ((t / s) + !!(t % s))) * s;

    for (int i = 0; i < n; ++i)
    {
        if (a[i].b - a[i].a <= 0)
        {
            if (tt > a[i].s)
            {
                tt -= a[i].s;
                yans += (a[i].a * a[i].s);
            }
            else
            {
                yans += (a[i].a * tt);
                yans += (a[i].b * (a[i].s - tt));
                tt = 0;
            }
        }
    }

    ans = max(ans, yans);

    cout << ans << endl;
    return 0;
}