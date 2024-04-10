#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1000;

void solve() {
    string s;
    cin >> s;
    int counter = 0;
    for(size_t i = 0; i < s.size(); i++) {
        if(s[i] == 'A' || !counter) {
            counter++;
        } else {
            counter--;
        }
    }
    cout << counter << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}