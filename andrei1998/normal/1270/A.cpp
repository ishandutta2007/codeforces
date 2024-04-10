#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 0;
    cin >> T;
    while (T--) {
        int N, k1, k2;
        cin >> N >> k1 >> k2;
        int maximum = -1;
        int who = -1;
        for (int i = 1; i <= k1; ++i) {
            int nr;
            cin >> nr;
            if (nr > maximum) {
                maximum = nr;
                who = 1;
            }
        }
        for (int i = 1; i <= k2; ++i) {
            int nr;
            cin >> nr;
            if (nr > maximum) {
                maximum = nr;
                who = 2;
            }
        }
        if (who == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}