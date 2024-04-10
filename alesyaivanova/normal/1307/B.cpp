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

const int maxn = 1e5 + 9;
int a[maxn];
int n, x;

void solve()
{
    cin >> n >> x;
    bool fl = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == x)
            fl = 1;
    }
    if (fl)
    {
        cout << "1\n";
        return;
    }
    sort(a, a + n);
    int ans = (x + a[n - 1] - 1) / a[n - 1];
    ans = max(ans, 2ll);
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