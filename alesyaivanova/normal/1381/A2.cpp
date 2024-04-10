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
    int l = 0, rev = 0, fl = 0;
    for (int i = n - 1; i >= 0; i--)
    {
//        cout << "   " << s1 << "\n";
        int pos = (rev ? l - i : l + i);
        char c = s1[pos];
        if (fl)
            c = char('1' + '0' - c);

//        cout << pos << " " << l << " " << rev << " " << fl << " " << c << " " << s1 << "\n";

        if (c == s2[i])
            continue;
        if (!i)
        {
            ans.pb(1);
//            s1[pos] = char('1' + '0' - s1[pos]);
            break;
        }
        c = s1[l];
        if (fl)
            c = char('1' + '0' - c);
        if (c == s2[i])
        {
            ans.pb(1);
            s1[l] = char('1' + '0' - s1[l]);
        }
        ans.pb(i + 1);
        if (!rev)
            l = l + i;
        else
            l = l - i;
        rev ^= 1;
        fl ^= 1;
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