#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        int cnt = 0;
        int i = 1;
        while (cnt < n) {
            if (i % 3 != 0 && i % 10 != 3) 
                cnt++;
            i++;
            if (cnt == n) {
                cout << i - 1 << endl;
                break;
            }
        }
    }

    return 0;
}