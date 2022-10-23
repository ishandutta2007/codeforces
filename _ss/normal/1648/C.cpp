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

const int N = 2e5 + 10, mod = 998244353;
int T[N], n, m;

ll ifact[N], fact[N], inv[N];

void precal(int k)
{
    inv[1] = ifact[0] = ifact[1] = fact[0] = fact[1] = 1;
    for (int i = 2; i <= k; ++i)
    {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
        ifact[i] = ifact[i - 1] * inv[i] % mod;
        fact[i] = fact[i - 1] * i % mod;
    }
}

int cnt[N];
ll bit[N];

void add(int v, int x)
{
    for (int i = v; i <= 2e5; i += (i & -i)) bit[i] += x;
}

ll get(int v)
{
    ll res = 0;
    for (int i = v; i; i -= (i & -i)) res += bit[i];
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1, x; i <= n; ++i) cin >> x, cnt[x]++;
    for (int i = 1; i <= m; ++i) cin >> T[i];
    ll val = 1;
    precal(2e5);
    for (int i = 1; i <= 2e5; ++i)
    {
        val = val * ifact[cnt[i]] % mod;
        if (cnt[i]) add(i, cnt[i]);
    }
    ll res = 0;
    for (int i = 1; i <= min(m, n); ++i)
    {
        res = (res + get(T[i] - 1) % mod * val % mod * fact[n - i]) % mod;
        val = val * cnt[T[i]] % mod;
        cnt[T[i]]--;
        if (cnt[T[i]] < 0) break;
        add(T[i], -1);
        if (i == n && i < m) res = (res + 1) % mod;
    }
    cout << res;
    return 0;
}