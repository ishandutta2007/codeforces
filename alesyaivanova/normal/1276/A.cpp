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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (i + 2 < n && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
            {
                if (i - 1 >= 0 && s[i - 1] == 'o')
                    ans.pb(i + 1);
                else
                    ans.pb(i);
            }
            else if (i - 2 >= 0 && s[i] == 'o' && s[i - 1] == 'w' && s[i - 2] == 't')
            {
                if (i + 1 < n && s[i + 1] == 'o')
                    ans.pb(i - 1);
                else
                    ans.pb(i);
            }
        }
        cout << ans.size() << "\n";
        for (int e : ans)
            cout << e + 1 << " ";
        cout << "\n";
    }
}