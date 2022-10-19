#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <bool> now(n);
        int c = 0, cha = 0;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            bool flag = true;
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                --x;
                if (flag) {
                    if (!now[x]) {
                        now[x] = true;
                        flag = false;
                        ++cha;
                    }
                }
            }
            if (flag) {
                c = i;
            }
        }
        if (cha == n) {
            cout << "OPTIMAL\n";
        }
        else {
            cout << "IMPROVE\n";
            cout << c + 1 << " ";
            int nn;
            for (int i = 0; i < n; ++i) {
                if (!now[i]) {
                    nn = i;
                    break;
                }
            }
            cout << nn + 1 << "\n";
        }
    }
    return 0;
}