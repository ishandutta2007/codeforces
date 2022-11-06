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
#define mod 1000000007LL
#define maxN 200011

int n, i, x;
int cnt[maxN];
ll ans;
ll until;

ll my_pow(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    ans = 1;
    until = 1;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (i = 2; i <= 200000; i++) {
        if (cnt[i] == 0) continue;

        ll aux = my_pow(ans, cnt[i] + 1);
        ans = aux;
        for (int j = 0; j <= cnt[i]; j++) {
            ll val = my_pow(i, j);
            val = my_pow(val, until);
            ans *=  val;
            ans %= mod;
        }

        until = (until * (cnt[i] + 1)) % (mod - 1);
    }



    printf("%I64d", ans);


    return 0;
}