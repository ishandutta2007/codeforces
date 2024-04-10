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
#define maxN 1000011

ll n, l, k, i, j, p, pp, mfull, full, part;
ll a[maxN];
pair<ll, bool> ord[maxN];
ll dp[maxN][2], last[maxN][2];

ll cnt[maxN][2], aux;
ll ans, last_val;

ll fact[maxN], inv_fact[maxN];

ll arj(ll n, ll k) {
    ll ans = (fact[n] * inv_fact[n - k]) % mod;
    return ans;
}

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void add(ll& a, ll b) {
    last_val = b;
    a += b;
    if (a >= mod) a -= mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &l, &k);
    for (i = 0; i < n; i++) scanf("%lld", &a[i]), ord[i] = mp(a[i], false);
    full = l / n;
    part = l % n;
    mfull = full % mod;

    for (i = 0; i < part; i++) ord[i].second = true;
    sort(ord, ord + n);


    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i > 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;

    dp[0][0] = 1;
    for (i = 0; i < n; i = j) {
        ll bef = 0;
        ll aft = 0;

        for (j  = i; j < n && ord[i].first == ord[j].first; j++) {
            if (ord[j].second)
                aft++;
            else
                bef++;
        }

        for (p = 0; p <= k; p++) {
            last[p][0] = dp[p][0];
            last[p][1] = dp[p][1];
            dp[p][0] = dp[p][1] = 0;
        }

        for (p = 0; p < k; p++) {
            if (last[p][0] == 0 && last[p][1] == 0) continue;
            aux = last[p][0] + last[p][1];
            if (aux >= mod) aux -= mod;

            add(dp[p][0], last[p][0]);
            add(dp[p][1], last[p][1]);

            add(last[p + 1][0], (aux * bef) % mod);
            add(cnt[p + 1][0], last_val);

            add(last[p + 1][1], (aux * aft) % mod);
            add(cnt[p + 1][1], last_val);
        }
    }



    for (i = 1; i <= k; i++) {
        //! with 0 and 1
        if (full >= i) {
            add(ans, (cnt[i][0] * (mod + mfull - i + 1)) % mod);
            add(ans, (cnt[i][1] * (mod + mfull - i + 1)) % mod);
        }

        //! with 1
        if (full + 1 >= i) {
            add(ans, cnt[i][1]);
        }
    }

    cout << ans;



    return 0;
}