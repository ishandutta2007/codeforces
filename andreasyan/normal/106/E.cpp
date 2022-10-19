#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102, M = 10004;
const long double EPS = 0.0000001;
struct ban
{
    int x, y, z;
};

int n;
ban a[N];

double stggg(double x, double y, double z)
{
    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, (x - a[i].x) * (x - a[i].x) + (y - a[i].y) * (y - a[i].y) + (z - a[i].z) * (z - a[i].z));
    }
    return ans;
}

pair<double, double> stgg(double x, double y)
{
    double l = -M, r = M;
    for (int ii = 0; ii < 70; ++ii)
    {
        double m1 = l + (r - l) / 2.1;
        double m2 = r - (r - l) / 2.1;
        if (stggg(x, y, m1) > stggg(x, y, m2))
            l = m1;
        else
            r = m2;
    }
    return m_p(l, stggg(x, y, l));
}

pair<pair<double, double>, double> stg(double x)
{
    double l = -M, r = M;
    for (int ii = 0; ii < 70; ++ii)
    {
        double m1 = l + (r - l) / 2.1;
        double m2 = r - (r - l) / 2.1;
        if (stgg(x, m1).second > stgg(x, m2).second)
            l = m1;
        else
            r = m2;
    }
    pair<double, double> u = stgg(x, l);
    return m_p(m_p(l, u.first), u.second);
}

void solv()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    double l = -M, r = M;
    for (int ii = 0; ii < 70; ++ii)
    {
        double m1 = l + (r - l) / 2.1;
        double m2 = r - (r - l) / 2.1;
        if (stg(m1).second > stg(m2).second)
            l = m1;
        else
            r = m2;
    }
    pair<pair<double, double>, double> u = stg(l);
    cout << l << ' ' << u.first.first << ' ' << u.first.second << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}