#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string pass;
    cin >> pass;
    int n;
    cin >> n;
    set<char> first, second;
    while(n--) {
        string t;
        cin >> t;
        for(int i = 0; i + 1 < t.size(); i++) {
            if(pass == t.substr(i, 2)) {
                cout << "YES\n";
                return 0;
            }
        }
        second.insert(t[0]);
        first.insert(t.back());
    }
    if(first.count(pass[0]) && second.count(pass[1])) {
        cout << "YES\n";
        return 0;
    }
    
    cout << "NO\n";
    
}