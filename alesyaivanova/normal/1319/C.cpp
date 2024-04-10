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
    int len;
    string s;
    cin >> len >> s;
    for (char c = 'z'; c >= 'b'; c--)
    {
        for (int i = 0; i < (int)s.size(); )
        {
            if (s[i] == c && ((i && s[i - 1] == c - 1) || (i != (int)s.size() - 1 && s[i + 1] == c - 1)))
            {
                s = s.substr(0, i) + s.substr(i + 1, (int)s.size());
                i = max(0ll, i - 1);
            }
            else
                i++;
        }
    }
    cout << len - (int)s.size();
}