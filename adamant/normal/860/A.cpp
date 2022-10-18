#include <bits/stdc++.h>

using namespace std;

bool cons(char c)
{
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

bool diff(char a, char b, char c)
{
    return a != b || a != c;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int dp[n + 1] = {0};
    vector<int> spaces[n];
    for(int i = 2; i < n; i++)
    {
        if(cons(s[i]) && cons(s[i - 1]) && cons(s[i - 2]) && diff(s[i], s[i - 1], s[i - 2]))
        {
            if(spaces[i - 1].size() < spaces[i - 2].size())
            {
                spaces[i] = spaces[i - 1];
                spaces[i].push_back(i);
            }
            else
            {
                spaces[i] = spaces[i - 2];
                spaces[i].push_back(i - 1);
            }
        }
        else
        {
            spaces[i] = spaces[i - 1];
        }
    }
    int cur = 0;
    for(int i = 0; i < n; i++)
    {
        if(cur < spaces[n - 1].size() && spaces[n - 1][cur] == i)
        {
            cur++;
            cout << ' ';
        }
        cout << s[i];
    }
    cout << endl;
}