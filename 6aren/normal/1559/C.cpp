#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (a[1] == 1) {
            cout << n + 1 << ' ';
            for (int i = 1; i <= n; i++) 
                cout << i << ' ';
            cout << '\n';
        } else {
            int found = 0;
            for (int i = 1; i < n; i++) {
                if (a[i] == 0 && a[i + 1] == 1) {
                    found = i;
                    break;
                }
            }
            if (found == 0) {
                for (int i = 1; i <= n + 1; i++) 
                    cout << i << ' ';
                cout << '\n';
            } else {
                for (int i = 1; i <= found; i++)
                    cout << i << ' ';
                cout << n + 1 << ' ';
                for (int i = found + 1; i <= n; i++) 
                    cout << i << ' ';
                cout << '\n'; 
            }
        }
    }

    return 0;
}