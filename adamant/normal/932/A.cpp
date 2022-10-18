#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    
    cout << s + string(s.rbegin(), s.rend()) << endl;
    return 0;
}