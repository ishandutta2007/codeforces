#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const ll N=4e5+10,mod=1e9+7;
ll ifact[N],fact[N],inv[N];

void build(int n)
{
    inv[1] = ifact[0] = ifact[1] = fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
        ifact[i] = ifact[i - 1] * inv[i] % mod;
        fact[i] = fact[i - 1] * i % mod;
    }
}

ll C(int t,int h) { return fact[h]*ifact[t]%mod*ifact[h-t]%mod; }

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    build(4e5);
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 0; i <= n; ++i) cin >> a[i];
    ll res = a[0];
    for (int i = 1; i <= n && a[i]; ++i) res = (res + C(a[i] - 1, a[i] + i)) % mod;
    cout << res;
    return 0;
}