#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define mod 1000000007LL

int n, i;
long long ans,aux;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);

    ans = 1;
    for (i = 1; i <= n; i++) ans = (ans * 27LL) % mod;

    aux = 1;
    for (i = 1; i <= n; i++) aux = (aux * 7LL) % mod;

    ans -= aux;
    if (ans < 0) ans += mod;

    printf("%I64d", ans);

    return 0;
}