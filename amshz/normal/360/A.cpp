/// IN THE NAME OF METAL
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}
const ll MAXN = 1e6 + 10;
const ll INF  = 8e18;
const ll MOD  = 1e9 + 7;
ll wtf[MAXN], A[MAXN], ans[MAXN], T[MAXN], L[MAXN], R[MAXN], Val[MAXN], m, n;

int main() {
    fill(ans, ans + MAXN, INF);
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= m; i++) {
        ll t, l, r, val;
        scanf("%lld%lld%lld%lld", &t, &l, &r, &val);
        T[i] = t, L[i] = l, R[i] = r, Val[i] = val;
        if (t == 1) {
            for (ll j = l; j <= r; j++) A[j] += val;
        } else {
            for (ll j = l; j <= r; j++) {
                ans[j] = min(ans[j], val - A[j]);
            }
        }
    }
    for (ll i = 1; i <= n; i++) wtf[i] = ans[i];
    for (ll i = 1; i <= m; i++) {
        ll t = T[i], l = L[i], r = R[i], val = Val[i];
        if (t == 1) {
            for (ll j = l; j <= r; j++) ans[j] += val;
        } else {
            ll mx = -INF;
            for (ll j = l; j <= r; j++) mx = max(mx, ans[j]);
            if (mx != val) return !printf("NO\n");
        }
    }
    printf("YES\n");
    for (ll i = 1; i <= n; i++) if (wtf[i] == INF) wtf[i] = 0;
    for (ll i = 1; i <= n; i++) printf("%lld ", wtf[i]);
    return 0;
}