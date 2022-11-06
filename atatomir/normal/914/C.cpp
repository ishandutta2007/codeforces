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

#define maxN 1024
#define mod 1000000007

const int limit = 1011;

int n, k, i;
char s[maxN];
int cnt[maxN];
ll ans;
ll fact[maxN], inv_fact[maxN];

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

ll comb(ll n, ll k) {
    if (k > n) return 0;
    ll ans = (fact[n] * inv_fact[k]) % mod;
    ans = (ans * inv_fact[n - k]) % mod;
    return ans;
}

int bts_cnt(int x) {
    int ans = 0;

    while (x > 0) {
        if (x & 1) ans++;
        x >>= 1;
    }

    return ans;
}

ll check(ll cnt) {
    ll i;
    ll ans = 0;

    for (i = 1; i <= n; i++) {
        if (s[i] == '0') {
            continue;
        } else {
            ans += comb(n - i, cnt);
            if (--cnt < 0) break;
        }
    }

    if (cnt == 0) ans++;

    ans %= mod;
    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);
   // freopen("*.out","w",stdout);

    scanf("%s%d", s + 1, &k);
    n = strlen(s + 1);

    cnt[1] = 0;
    for (i = 2; i <= limit; i++)
        cnt[i] = 1 + cnt[bts_cnt(i)];

    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;

    for (i = 1; i <= limit; i++) {
        if (cnt[i] == k - 1) ans += 1LL * check(i);
        ans %= mod;
    }

    if (k == 0) ans = 1;
    if (k == 1) ans = (ans + mod - 1) % mod;

    printf("%lld", ans);

    return 0;
}