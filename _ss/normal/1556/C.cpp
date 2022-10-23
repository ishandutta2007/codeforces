#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
pll a[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum = 0, res = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        if (i & 1) a[i] = mp(sum + 1, sum + x), sum += x;
        else a[i] = mp(sum - x, sum - 1), sum -= x;
        for (int j = 0; j < i && i % 2 == 0; ++j)
        {
            ll l = max(a[j].fi, a[i].fi);
            ll r = min(a[j].se, a[i].se);
            if (l <= r) res += r - l + 1;
        }
        for (int j = 0; j <= i; ++j) a[j].se = min(a[j].se, sum);
    }
    cout << res;
    return 0;
}