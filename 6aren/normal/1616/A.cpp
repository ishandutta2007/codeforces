#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        map<int, int> check;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            check[abs(x)]++;
        }
        int res = 0;
        for (int i = 1; i <= 100; i++) {
            res += min(check[i], 2);
        }
        res += min(check[0], 1);
        cout << res << '\n';
    }
    return 0;
}