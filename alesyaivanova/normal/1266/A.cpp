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
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        string s;
        cin >> s;
        int m = s.size();
        bool t = 0;
        int sum = 0;
        bool y = 0;
        for (int i = 0; i < m; i++)
        {
            sum += s[i] - '0';
            if (s[i] == '0')
            {
                if (!t)
                    t = 1;
                else
                    y = 1;
            }
            else if ((s[i] - '0') % 2 == 0)
                y = 1;
        }
        if (sum % 3 == 0 && y && t)
            cout << "red\n";
        else
            cout << "cyan\n";
    }
}