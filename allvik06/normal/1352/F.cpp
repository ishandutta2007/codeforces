#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 10;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        bool nul = false, two = false;
        if (n0 > 0) {
            nul = true;
            cout << 0;
        }
        while (n0 > 0) {
            cout << 0;
            --n0;
        }
        if (n2 > 0) {
            two = true;
            cout << 1;
            if (nul) --n1;
        }
        while (n2 > 0) {
            cout << 1;
            --n2;
        }
        if (!two && n1 > 0) {
            if (!nul) {
                cout << 0;
            }
            --n1;
            cout << 1;
        }
        while (n1 > 1) {
            cout << "01";
            n1 -= 2;
        }
        if (n1 == 1) {
            cout << 0;
        }
        cout << "\n";
    }
    return 0;
}