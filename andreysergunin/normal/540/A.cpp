#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k = abs(s[i] - t[i]);
        ans += min(k, 10 - k);
    }
     cout << ans;
    return 0;
}