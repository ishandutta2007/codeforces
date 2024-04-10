#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int y[m];
    for(int i = 0; i < m; i++)
        cin >> y[i], y[i]--;
    int k = s.size();
    int p[k];
    p[0] = 0;
    for(int i = 1; i < k; i++)
    {
        p[i] = p[i - 1];
        while(p[i] && s[i] != s[p[i]]) p[i] = p[p[i] - 1];
        if(s[i] == s[p[i]]) p[i]++;
    }
    int j = 0;
    string t(n, '0');
    int cl = k;
    bool ok[k + 1];
    memset(ok, 0, sizeof(ok));
    for(int i = k - 1; p[i]; p[i] = p[p[i] - 1])
        ok[p[i]] = 1;
    ok[0] = 1;
    for(int i = 0; i < n; i++)
    {
        if(j != m && y[j] == i)
        {
            j++;
            if(!ok[k - cl])
            {
                cout << 0 << "\n";
                return 0;
            }
            cl = 0;
        }
        if(cl < k)
        {
            t[i] = '1';
            cl++;
        }
    }
    int ans = 1;
    for(int i = 0; i < n; i++)
        if(t[i] == '0')
            ans = (1LL * ans * 26) % mod;
    cout << ans << "\n";
}