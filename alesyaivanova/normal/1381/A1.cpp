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

void solve()
{
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
//        cout << "   " << s1 << "\n";
        if (s1[i] == s2[i])
            continue;
        if (!i)
        {
            ans.pb(1);
            s1[0] = char('1' + '0' - s1[0]);
            break;
        }
        if (s1[0] != s1[i])
        {
            ans.pb(1);
            s1[0] = s1[i];
        }
        ans.pb(i + 1);
        for (int e = 0; e <= i - e; e++)
        {
            s1[e] = char('1' + '0' - s1[e]);
            if (e != i - e)
            {
                s1[i - e] = char('1' + '0' - s1[i - e]);
                swap(s1[e], s1[i - e]);
            }
        }
    }
    cout << ans.size() << " ";
    for (int e : ans)
        cout << e << " ";
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