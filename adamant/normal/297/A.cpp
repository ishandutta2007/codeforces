#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    for(auto c: a) {
        cnt1 += c == '1';
    }
    for(auto c: b) {
        cnt2 += c == '1';
    }
    cout << (cnt1 + (cnt1 % 2) >= cnt2 ? "YES" : "NO") << endl;
    return 0;
}