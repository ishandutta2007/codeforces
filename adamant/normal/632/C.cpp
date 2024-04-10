#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for(auto &it: s)
        cin >> it;
    sort(s, s + n, [](string a, string b){return a + b < b + a;});
    for(auto it: s)
        cout << it;
}