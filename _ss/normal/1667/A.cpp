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

const int N = 1e5 + 10;
ll n, a[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll ans = 8e18;
    for (int i = 1; i <= n; ++i)
    {
        ll res = 0;
        ll val = 0;
        for (int j = i - 1; j; --j)
        {
            ll cnt = val / a[j] + 1;
            res += cnt;
            val = cnt * a[j];
        }
        val = 0;
        for (int j = i + 1; j <= n; ++j)
        {
            ll cnt = val / a[j] + 1;
            res += cnt;
            val = cnt * a[j];
        }
        ans = min(res, ans);
    }
    cout << ans;
    return 0;
}