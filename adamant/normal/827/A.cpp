#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    map<int, vector<int>> hr;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        int k;
        cin >> k;
        while(k--)
        {
            int t;
            cin >> t;
            hr[t - 1].push_back(i);
        }
    }
    string ans;
    int j = 0;
    for(auto jt: hr)
    {
        int i = jt.first;
        for(; j < i; j++)
            ans.push_back('a');
        for(auto it: hr[i])
            for(; j - i < s[it].size(); j++)
                ans.push_back(s[it][j - i]);
    }
    cout << ans << endl;
}