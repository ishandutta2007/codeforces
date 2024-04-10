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

const int maxN = 300011;

ll n, i, cont;
ll a[maxN], b[maxN], ans, aux;
ll sum[maxN], up[maxN], down[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] += a[i];
    for (i = 1; i <= n; i++) scanf("%lld", &b[i]), sum[i] += b[i];

    for (i = n; i >= 1; i--) sum[i] += sum[i + 1];
    up[n] = b[n];
    down[n] = a[n];

    for (i = n - 1; i >= 1; i--) {
        up[i] = up[i + 1] + sum[i + 1];
        down[i] = down[i + 1] + sum[i + 1];
        up[i] += b[i] * (2 * (n - i) + 1);
        down[i] += a[i] * (2 * (n - i) + 1);
    }

    ans = up[1];

    aux = cont = 0;
    for (i = 1; i <= n; i++) {
        if (i & 1) {
            aux += (cont++) * a[i];
            aux += (cont++) * b[i];
            ans = max(ans, aux + down[i + 1] + sum[i + 1] * cont);
        } else {
            aux += (cont++) * b[i];
            aux += (cont++) * a[i];
            ans = max(ans, aux + up[i + 1] + sum[i + 1] * cont);
        }
    }
    ans = max(ans, aux);

    printf("%lld", ans);



    return 0;
}