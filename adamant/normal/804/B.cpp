#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int cur = 0;
    int ans = 0;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        cur += s[i] == 'b';
        if(s[i] == 'a')
            ans = (ans + cur) % mod, cur = (cur + cur) % mod;
    }
    cout << ans << endl;
}