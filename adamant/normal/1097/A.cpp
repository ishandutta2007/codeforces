#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> a;
    int n = 5;
    string s[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        if(s[i][0] == a[0] || s[i][1] == a[1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;   
    return 0;
}