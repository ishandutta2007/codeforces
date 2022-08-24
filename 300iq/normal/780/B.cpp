#include <bits/stdc++.h>

using namespace std;

const int N = 6e4 + 1;

int x[N], v[N];
int n;

double f(double y)
{
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, abs(x[i] - y) / v[i]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    double l = -1e9, r = 1e9;
    int it = 200;
    while (it--)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) > f(m2))
        {
            l = m1;
        }
        else
        {
            r = m2;
        }
    }
    cout << fixed << setprecision(20) << f(l) << '\n';
}