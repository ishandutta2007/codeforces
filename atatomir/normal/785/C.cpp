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

ll n, m;

ll solve(ll n, ll m) {
    ll k = sqrt(2 * (n - m));
    while (k * (k + 1) < 2 * (n - m)) k++;
    return m + k;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &m);

    if (n <= m + 1) {
        printf("%lld", n);
        return 0;
    }

    printf("%lld", solve(n, m));




    return 0;
}