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
        for (int i = 2; i <= n + 1; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}