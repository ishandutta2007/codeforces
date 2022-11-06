#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 200011

int n, k, x, i;
long long vv[maxN];
long long le[maxN], ri[maxN];
long long mult, aux, ans;

int main()
{
    //freopen("input.in","r",stdin);

    scanf("%d%d%d", &n, &k, &x);
    mult = 1;
    for (i = 1; i <= k; i++) mult *= 1LL * x;
    for (i = 1; i <= n; i++) scanf("%I64d", &vv[i]);

    for (i = 1; i <= n; i++) le[i] = vv[i] | le[i - 1];
    for (i = n; i >= 1; i--) ri[i] = vv[i] | ri[i + 1];

    for (i = 1; i <= n; i++) {
        aux = (mult * vv[i]) | le[i - 1] | ri[i + 1];
        ans = max(ans, aux);
    }

    printf("%I64d", ans);
    cerr << '\n' << ans << '\n';

    return 0;
}