#include <bits/stdc++.h>

using namespace std;

//#define int long long
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
int dp[maxn];
vector<int> cur[4] = {{0, 1}, {0, 1, 1}, {0, 0, 1}, {0, 0, 1, 1}};
int n;

int check()
{
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = n;
        for (int e = 0; e < 4; e++)
        {
            if (cur[e].size() > i + 1)
                continue;
            int cnt = 0;
            for (int q = 0; q < (int)cur[e].size(); q++)
                cnt += (cur[e][q] ^ a[i - q]);
            dp[i + 1] = min(dp[i + 1], dp[i + 1 - (int)cur[e].size()] + cnt);
        }
    }
    return dp[n];
}

void solve()
{
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        a[i] = (s[i] == 'R');
    int ans = n;
    for (int j = 0; j < 5; j++)
    {
        ans = min(ans, check());
        bool fl = a[0];
        for (int i = 0; i < n - 1; i++)
            a[i] = a[i + 1];
        a[n - 1] = fl;
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