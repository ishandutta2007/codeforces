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

const int maxn = 2e5 + 9;
int a[maxn];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mi = a[0], ma = a[0];
    for (int i = 0; i < n; i++)
    {
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
    }
    if (k % 2 == 1)
    {
        for (int i = 0; i < n; i++)
            a[i] = ma - a[i];
        k--;
        ma = ma - mi;
        mi = 0;
    }
    if (k)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] - mi << " ";
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}