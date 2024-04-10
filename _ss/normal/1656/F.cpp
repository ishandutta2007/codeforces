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

const int N = 2e5 + 10;
ll a[N], n, pr[N], su[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) pr[i] = pr[i - 1] + a[i];
    su[n + 1] = 0;
    for (int i = n; i; --i) su[i] = su[i + 1] + a[i];
    if (a[1] * (n - 1) + su[2] > 0 || a[n] * (n - 1) + pr[n - 1] < 0)
    {
        cout << "INF\n";
        return;
    }
    ll res = -8e18;
    for (int i = 2; i <= n; ++i)
    {
        ll l = -a[i];
        ll r = -a[i - 1];
        ll val = (a[1] + l) * (su[i] + (n - i + 1) * l) + (a[n] + l) * (pr[i - 1] + (i - 1) * l) - (a[1] + l) * (a[n] + l) - l * l * (n - 1);
        ll val2 = (a[1] + r) * (su[i] + (n - i + 1) * r) + (a[n] + r) * (pr[i - 1] + (i - 1) * r) - (a[1] + r) * (a[n] + r) - r * r * (n - 1);
        res = max({res, val, val2});
    }
    cout << res << "\n";
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}