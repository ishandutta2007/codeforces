#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(n >= 30) {
        cout << m << endl;
    } else {
        cout << (m & ((1 << n) - 1)) << endl;
    }
    return 0;
}