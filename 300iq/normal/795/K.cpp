#include <bits/stdc++.h>

using namespace std;

int g[255];

int main()
{
    g['a'] = g['e'] = g['i'] = g['o'] = g['u'] = g['y'] = 1;
    g['e'] = g['o'] = 2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; )
    {
        int j = i;
        int cnt = 0;
        while (j < n && s[j] == s[i])
        {
            j++;
            cnt++;
        }
        if (g[s[i]])
        {
            cnt = min(cnt, (cnt == 2 ? g[s[i]] : 1));
        }
        while (cnt--)
        {
            cout << s[i];
        }
        i = j;
    }
}