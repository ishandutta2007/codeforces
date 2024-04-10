#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200007;
const double EPS = 1e-10;

int n;
double l, v1, v2;
double a[MAXN];
double ans[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    cin >> n >> l >> v1 >> v2;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        a[i + n] = a[i] + 2 * l;
    a[n + n] = 1e+20;

    double d = l / (v1 + v2) * v2;
    double last = 0;

    l *= 2;
    for (int i = 0, j = 0; last + EPS < l; )
    {
        while (a[j] <= last + d + EPS) j++;
        double x = min(min(a[j] - (last + d), a[i] - last), l - last);
        ans[j - i] += x;
        last += x;
        while (fabs(last - a[i]) < EPS) i++;
    }

    for (int i = 0; i <= n; i++)
        printf("%.11lf\n", (double)(ans[i] / l));
    return 0;
}