#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 109;
int a[maxn];
int n, d;

void solve()
{
    cin >> n >> d;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i)
        {
            int cur = d / i;
            ans += min(cur, a[i]);
            d -= i * min(cur, a[i]);
        }
        else
            ans += a[i];
    }
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}