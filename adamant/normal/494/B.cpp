#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9, mod = 1e9 + 7;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    string c = b + '#' + a;
    int n = c.size();
    int z[n];
    memset(z, 0, sizeof(z));
    int l = 0, r = 0;
    for(int i = 1; i < n; i++)
    {
        if(i < r) z[i] = min(z[i - l], r - i);
        while(i + z[i] < n && c[z[i]] == c[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    int dp_end[n], dp_total[n], sum_total[n];
    memset(dp_end, 0, sizeof(dp_end));
    memset(dp_total, 0, sizeof(dp_total));
    memset(sum_total, 0, sizeof(sum_total));
    int m = b.size();
    for(int i = 2 * m; i < n; i++)
    {
        dp_end[i] = ((z[i - m + 1] == m) ? ((i - 2 * m + 1) + sum_total[i - m]) : dp_end[i - 1] ) % mod;
        dp_total[i] = (dp_total[i - 1] + dp_end[i]) % mod;
        sum_total[i] = (sum_total[i - 1] + dp_total[i]) % mod;
    }
    cout << dp_total[n - 1] << "\n";
}