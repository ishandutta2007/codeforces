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
    unordered_map<string, unordered_set<int>> lol;
    for(int z = 0; z < n; z++)
    {
        cin >> s[z];
        for(int i = 0; i < 9; i++)
            for(int j = 1; i + j <= 9; j++)
                lol[s[z].substr(i, j)].insert(z);
    }
    for(int z = 0; z < n; z++)
    {
        for(int j = 1; j <= 9; j++)
            for(int i = 0; i + j <= 9; i++)
                if(lol[s[z].substr(i, j)].size() == 1)
                {
                    cout << s[z].substr(i, j) << "\n";
                    goto nxt;
                }
        nxt:;
    }
}