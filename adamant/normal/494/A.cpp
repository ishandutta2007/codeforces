#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

void FAIL()
{
    cout << -1 << endl;
    exit(0);
}

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int x = 0;
    vector<int> ans;
    for(auto c: s)
    {
        if(c == '(') x++;
        else if(c == ')') x--;
        else
        {
            x--;
            ans.push_back(1);
        }
        if(x < 0) FAIL();
    }
    int cnt = ans.size();
    int y = 0;
    for(auto c: s)
    {
        if(c == '(') y++;
        else if(c == ')') y--;
        else
        {
            y--;
            cnt--;
            if(!cnt)
            {
                y -= x;
                ans.back() += x;
            }
        }
        if(y < 0) FAIL();
    }
    for(auto it: ans) cout << it << endl;
}