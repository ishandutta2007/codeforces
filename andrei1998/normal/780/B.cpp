#include <bits/stdc++.h>

using namespace std;

const int NMAX = 60000 + 5;

int N;
int xs[NMAX];
int v[NMAX];

double getCost(double x) {
    double ans = 0;
    for (int i = 1; i <= N; ++ i)
        ans = max(ans, 1.0 * fabs(x - xs[i]) / v[i]);
    return ans;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> xs[i];
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    double l = 0;
    double r = 1000000000;
    for (int s = 0; s < 100; ++ s) {
        const double mid1 = (2 * l + r) / 3;
        const double mid2 = (l + 2 * r) / 3;
        if (getCost(mid1) < getCost(mid2))
            r = mid2;
        else
            l = mid1;
    }

    cout << fixed << setprecision(12) << getCost(l) << endl;
    return 0;
}