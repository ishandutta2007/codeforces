#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100 + 1;
double px[N], py[N], pz[N];
int n;
double eps = 1e-6;

struct terp
{
    double x, y, z;
    double res;
    terp(double a, double b, double c, double d): res(a), x(b), y(c), z(d) {}
    terp() {}
};

double sqr(double x)
{
    return x * x;
}

terp get(double x, double y, double z)
{
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, sqrt(sqr(px[i] - x) + sqr(py[i] - y) + sqr(pz[i] - z)));
    }
    return {ans, x, y, z};
}

terp get(double x, double y)
{
    double l = -1e4 - 7, r = 1e4 + 7;
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (get(x, y, m1).res < get(x, y, m2).res)
        {
            r = m2;
        }
        else
        {
            l = m1;
        }
    }
    return get(x, y, l);
}

terp get(double x)
{
    double l = -1e4 - 7, r = 1e4 + 7;
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (get(x, m1).res < get(x, m2).res)
        {
            r = m2;
        }
        else
        {
            l = m1;
        }
    }
    return get(x, l);
}

terp get()
{
    double l = -1e4 - 7, r = 1e4 + 7;
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (get(m1).res < get(m2).res)
        {
            r = m2;
        }
        else
        {
            l = m1;
        }
    }
    return get(l);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> px[i] >> py[i] >> pz[i];
    }
    auto a = get();
    cout << fixed << setprecision(20) << a.x << ' ' << a.y << ' ' << a.z << '\n';
}