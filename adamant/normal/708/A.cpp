#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != 'a')
        {
            for(int j = i; j < s.size() && s[j] != 'a'; j++)
                s[j]--;
            cout << s << "\n";
            return 0;
        }
    }
    s[s.size() - 1] = 'z';
    cout << s << "\n";
    return 0;
}