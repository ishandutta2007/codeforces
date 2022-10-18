#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        for(int j = i + 1; j <= s.size(); j++)
    {
        if(s.substr(0, i) + s.substr(j) == "CODEFORCES")
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}