#include <bits/stdc++.h>

using namespace std;

map <char, int> Map;

int main()
{
    ios_base :: sync_with_stdio(false);

    string str;
    cin >> str;

    for (auto it: str)
        ++ Map[it];

    int ans = str.size() + 1;

    ans = min(ans, Map['B']);
    ans = min(ans, Map['l']);
    ans = min(ans, Map['b']);
    ans = min(ans, Map['s']);
    ans = min(ans, Map['a'] / 2);
    ans = min(ans, Map['u'] / 2);
    ans = min(ans, Map['r']);

    cout << ans << '\n';
    return 0;
}