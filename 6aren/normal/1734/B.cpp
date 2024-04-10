#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            vector<int> a(i, 0);
            a[0] = 1, a.back() = 1;
            for (int e : a) {
                cout << e << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}