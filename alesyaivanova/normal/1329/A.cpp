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
int ans[maxn];
int n, m;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < n)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        if (i + a[i] > n)
        {
            cout << -1;
            return 0;
        }
    }
    int cur = n;
    for (int i = m - 1; i >= 0; i--)
    {
        ans[i] = max(cur - a[i], i);
        cur = ans[i];
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] + 1 << " ";
}