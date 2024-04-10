#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> cnt;
    while(n--)
    {
        string s;
        cin >> s;
        cout << (cnt[s] == 0 ? "NO" : "YES") << "\n";
        cnt[s]++;
    }
    return 0;
}