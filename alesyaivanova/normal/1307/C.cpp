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

int cnt[26];
int dp[26 * 26];

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < 26; c++)
            dp[c * 26 + (s[i] - 'a')] += cnt[c];
        cnt[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max(ans, cnt[i]);
    for (int i = 0; i < 26 * 26; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}