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

const int maxn = 4007;
int a[maxn];
int n;

void solve()
{
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> kek;
    set<int> x;
    for (int i = 0; i < n; i++)
        x.insert(i + 1);
    int pr = n;
    for (int i = n - 1; i >= 0; i--)
    {
        auto u = x.end();
        u--;
        if (a[i] == (*u))
        {
            kek.pb(pr - i);
            pr = i;
        }
        x.erase(a[i]);
    }
    bitset<maxn> dp;
    dp[0] = 1;
    n /= 2;
    for (int e : kek)
        dp |= (dp << e);
    if (dp[n])
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}