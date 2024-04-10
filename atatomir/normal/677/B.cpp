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

#define maxN 100011

ll n, h, k, i;
ll dim[maxN];
ll ans, act;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &h, &k);
    for (i = 1; i <= n; i++) scanf("%lld", &dim[i]);
    dim[n + 1] = h;

    i = 0; act = 0;
    while (i < n) {
        while (i < n && act + dim[i + 1] <= h) act += dim[++i];

        int dif = dim[i + 1] - (h - act);
        int need = (dif + k - 1) / k;

        ans += need;
        act -= k * need; act = max(act, 0LL);
    }

    printf("%lld", ans);


    return 0;
}