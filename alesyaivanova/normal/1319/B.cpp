#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define mp make_pair
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e6 + 9;
int n;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r",stdin);
        //freopen("output.txt", "w",stdout);
    #endif
    cin >> n;
    map<int, int> dp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int b = a - i;
        dp[b] += a;
    }
    int ans = 0;
    for (auto e : dp)
        ans = max(ans, e.ss);
    cout << ans;
}