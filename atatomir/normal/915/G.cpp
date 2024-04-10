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

#define mod 1000000007
#define maxN 2000011


ll n, k, i;
bool pr[maxN];
bool bad[maxN];
int sgn[maxN];

ll smen[maxN];
ll pp[maxN];
ll ans;

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void prep() {
    ll i, j;

    for (i = 1; i <= k; i++) pp[i] = poww(i, n);

    for (i = 2; i <= k; i++) {
        if (pr[i]) continue;
        sgn[i] ^= 1;

        for (j = 2 * i; j <= k; j += i) {
            pr[j] = true;
            sgn[j] ^= 1;
            if (j % (i * i) == 0) bad[j] = true;
        }
    }
}

void add_number(ll nr) {
    ll sg = (sgn[nr] ? -1 : 1);
    ll cnt, p1, p2;

    for (cnt = 1; cnt <= k / nr; cnt++) {
        p1 = cnt * nr;
        p2 = (cnt + 1) * nr - 1;
        p2 = min(p2, k);

        smen[p1] += mod + sg * pp[cnt];
        smen[p2 + 1] += mod - sg * pp[cnt];

        while (smen[p1] >= mod) smen[p1] -= mod;
        while (smen[p2 + 1] >= mod) smen[p2 + 1] -= mod;
    }
}

int main()
{
    //freopen("test.in","r",stdin);
   // freopen("*.out","w",stdout);

    scanf("%d%d", &n, &k);
    prep();

    for (i = 1; i <= k; i++)
        if (!bad[i])
            add_number(i);

    for (i = 1; i <= k; i++) {
        smen[i] += smen[i - 1];
        smen[i] %= mod;

        ans += smen[i] ^ i;
        ans %= mod;
    }

    cout << ans;


    return 0;
}