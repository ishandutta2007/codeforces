#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for(auto &it: s)
        cin >> it;
    reverse(s, s + n);
    set<string> used;
    for(auto it: s)
        if(!used.count(it))
        {
            cout << it << "\n";
            used.insert(it);
        }
}