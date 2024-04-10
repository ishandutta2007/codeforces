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

const int maxn = 20;
int g[maxn][maxn];

void solve()
{
    for (int i = 0; i < maxn; i++)
        for (int e = 0; e < maxn; e++)
            g[i][e] = 0;
    int n;
    string a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "-1\n";
            return;
        }
        if (a[i] < b[i])
            g[a[i] - 'a'][b[i] - 'a'] = 1;
    }
    int ans = 0;
    for (int i = 0; i < maxn; i++)
    {
        int j = -1;
        for (int e = i + 1; e < maxn; e++)
        {
            if (g[i][e])
            {
                j = e;
                break;
            }
        }
        if (j == -1)
            continue;
        ans++;
        for (int e = j + 1; e < maxn; e++)
        {
            if (g[i][e])
                g[j][e] = 1;
        }
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