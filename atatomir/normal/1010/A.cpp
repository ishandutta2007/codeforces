#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 1024;

int n, i;
double m;
double a[maxN], b[maxN];

bool check(double fuel) {
    int i;
    double act;

    act = fuel + m;
    for (i = 1; i <= n; i++) {
        act -= act / a[i];
        if (act < m) return false;
        act -= act / b[i + 1];
        if (act < m) return false;
    }

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 1; i <= n; i++) cin >> b[i];

    a[n + 1] = a[1];
    b[n + 1] = b[1];


    int steps = 60;
    double lo, hi, mid;
    lo = 0.00; hi = 1000000000.00;

    if (!check(hi + 10.00)) {
        printf("-1");
        return 0;
    }

    while (steps-- > 0) {
        mid = (lo + hi) / 2.00;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }

    mid = (lo + hi) / 2.00;
    printf("%.10lf", mid);

    return 0;
}