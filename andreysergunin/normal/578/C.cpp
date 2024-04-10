#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

const int MAXN = 300000;

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int a[MAXN];
    double b[MAXN], p[MAXN];
    double ma, mi;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double l = -10000.0, r = 10000.0;
    double eps = 1e-12;
    while (r - l > eps)
    {
        double x1 = (2 * l + r) / 3;
        for (int i = 0; i < n; i++)
            b[i] = (double)a[i] - x1;
        p[0] = 0;
        for (int i = 0; i < n; i++)
            p[i + 1] = p[i] + b[i];
        ma = -1e9 - 1, mi = 1e9 + 1;
        for (int i = 0; i <= n; i++)
        {
            ma = max(ma, p[i]);
            mi = min(mi, p[i]);
        }
        double ans1 = ma - mi;
        
        double x2 = (l + 2 * r) / 3;
        for (int i = 0; i < n; i++)
            b[i] = (double)a[i] - x2;
        p[0] = 0;
        for (int i = 0; i < n; i++)
            p[i + 1] = p[i] + b[i];
        ma = -1e9 - 1, mi = 1e9 + 1;
        for (int i = 0; i <= n; i++)
        {
            ma = max(ma, p[i]);
            mi = min(mi, p[i]);
        }
        double ans2 = ma - mi;
        if (ans1 < ans2)
            r = (l + 2 * r) / 3;
        else
            l = (2 * l + r) / 3;
    }
    double ans = l;
    
    for (int i = 0; i < n; i++)
        b[i] = (double)a[i] - ans;
    p[0] = 0;
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + b[i];
    ma = -1e9 - 1, mi = 1e9 + 1;
    for (int i = 0; i <= n; i++)
    {
        ma = max(ma, p[i]);
        mi = min(mi, p[i]);
    }
    printf("%.9lf", ma - mi);
    
    return 0;
}