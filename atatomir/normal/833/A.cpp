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

ll n, i, a, b, x;

bool check() {
    ll i, j, R;

    x = a * b;
    for (R = max(0LL, llround(cbrt(x)) - 2); R * R * R < x; R++);
    if (R * R * R != x) return false;

    if (a % R != 0) return false;
    if (b % R != 0) return false;
    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &a, &b);
        if (check())
            printf("Yes\n");
        else
            printf("No\n");
    }


    return 0;
}