#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


int n;
double a, d;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    cin >> n >> a >> d;
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        double t, v;
        cin >> t >> v;
        double x = min(v / a, sqrt(d * 2 / a));
        t += x + (d - a * x * x / 2) / v;
        res = max(t, res);
        printf("%.7lf\n", res);
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}