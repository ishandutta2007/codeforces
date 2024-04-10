#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
string s[MAX_N];
int len[26];
int n;
int inf = 1000 * 1000 * 1000 + 7;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int e = 0; e < (int)s[0].length(); e++)
    {
        int cur = 1;
        while (e + 1 < (int)s[0].length() && s[0][e] == s[0][e + 1])
        {
            cur++;
            e++;
        }
        len[s[0][e] - 'a'] = max(len[s[0][e] - 'a'], cur);
    }
    for (int i = 1; i < n; i++)
    {
        bool check = true;
        int m = s[i].length();
        for (int e = 0; e < m - 1; e++)
        {
            if (s[i][e] != s[i][e + 1])
                check = false;
        }
        if (check)
        {
            len[s[i][0] - 'a'] = min((m + 1) * (len[s[i][0] - 'a'] + 1) - 1, inf);
            for (int j = 0; j < 26; j++)
            {
                if (j != s[i][0] - 'a' && len[j] >= 1)
                    len[j] = 1;
            }
            continue;
        }
        int e = 0;
        while (s[i][e + 1] == s[i][e])
            e++;
        int u = m - 1;
        while (s[i][u - 1] == s[i][u])
            u--;
        if (s[i][0] == s[i][m - 1] && len[s[i][0] - 'a'] > 0)
            len[s[i][0] - 'a'] = 1 + (e + 1) + (m - u);
        else if (s[i][0] == s[i][m - 1])
            len[s[i][0] - 'a'] = max(e + 1, m - u);
        else
        {
            if (len[s[i][0] - 'a'] > 0)
                len[s[i][0] - 'a'] = 1 + (e + 1);
            else
                len[s[i][0] - 'a'] = e + 1;
            if (len[s[i][m - 1] - 'a'] > 0)
                len[s[i][m - 1] - 'a'] = 1 + (m - u);
            else
                len[s[i][m - 1] - 'a'] = m - u;
        }
        for (int j = 0; j < 26; j++)
        {
            if (j != s[i][0] - 'a' && j != s[i][m - 1] - 'a' && len[j] >= 1)
                len[j] = 1;
        }
        for (int e = 0; e < m; e++)
        {
            int cur = 1;
            while (e + 1 < m && s[i][e] == s[i][e + 1])
            {
                cur++;
                e++;
            }
            len[s[i][e] - 'a'] = max(len[s[i][e] - 'a'], cur);
        }
    }
    int ans = 0;
    for (int j = 0; j < 26; j++)
        ans = max(ans, len[j]);
    cout << ans;
}