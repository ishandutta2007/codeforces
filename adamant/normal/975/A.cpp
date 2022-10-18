#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<set<char>> lol;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        lol.insert(set<char>(all(s)));
    }
    cout << lol.size() << endl;
    return 0;
}