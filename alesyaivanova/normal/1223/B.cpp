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



signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string s, t;
        cin >> s >> t;
        set<char> a;
        int n = s.size();
        for (int e = 0; e < n; e++)
            a.insert(s[e]);
        int ans = 0;
        for (int e = 0; e < n; e++)
        {
            if (a.find(t[e]) != a.end())
                ans = 1;
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}