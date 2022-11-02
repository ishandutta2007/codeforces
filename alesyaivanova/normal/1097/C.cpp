#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int t[MAX_N];
int bal[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int m = s.size();
        int cur = 0;
        bool u = true;
        for (int e = 0; e < m; e++)
        {
            if (s[e] == '(')
                cur++;
            else
                cur--;
            if (cur < 0)
            {
                u = false;
                break;
            }
        }
        if (u)
        {
            if (cur == 0)
            {
                cnt++;
                i--;
                n--;
            }
            else
            {
                t[i] = 0;
                bal[i] = cur;
            }
        }
        bool v = true;
        cur = 0;
        for (int e = m - 1; e >= 0; e--)
        {
            if (s[e] == ')')
                cur++;
            else
                cur--;
            if (cur < 0)
            {
                v = false;
                break;
            }
        }
        if (v && cur != 0)
        {
            t[i] = 1;
            bal[i] = cur;
        }
        if (!u && !v)
        {
            i--;
            n--;
        }
    }
    multiset<int> s;
    int ans = cnt / 2;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 0)
            s.insert(bal[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 1)
        {
            auto j = s.find(bal[i]);
            if (j == s.end())
                continue;
            ans++;
            s.erase(j);
        }
    }
    cout << ans;
}