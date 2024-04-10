#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, T;
    cin >> n >> a >> b >> T;
    string s;
    cin >> s;
    int csuf[n + 1];
    int cpre[n];
    csuf[n] = 0;
    csuf[n - 1] = a + 1 + b * (s[n - 1] == 'w');
    cpre[0] = 1 + b * (s[0] == 'w');
    int csuf2[n + 1];
    csuf2[n] = 0;
    csuf2[n - 1] = a + a + 1 + b * (s[n - 1] == 'w');
    for(int i = 1; i < n; i++)
    {
        csuf[n - i - 1] = csuf[n - i] + a + 1 + b * (s[n - i - 1] == 'w');
        csuf2[n - i - 1] = csuf2[n - i] + a + a + 1 + b * (s[n - i - 1] == 'w');
        cpre[i] = cpre[i - 1] + a + 1 + b * (s[i] == 'w');
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cur = cpre[i] + i * a;
        if(cur <= T)
        {
            int it = lower_bound(csuf, csuf + n + 1, T - cur, greater<int>()) - csuf;
            //cout << i << ' ' << cur << ' ' << it << endl;
            ans = max(ans, min(n, i + 1 + (n - it)));
        }
        cur = cpre[i];
        if(cur <= T)
        {
            int it = lower_bound(csuf2, csuf2 + n + 1, T - cur, greater<int>()) - csuf2;
            ans = max(ans, min(n, i + 1 + (n - it)));
        }
    }
    cout << ans << "\n";
}