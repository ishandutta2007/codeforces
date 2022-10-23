#include<bits/stdc++.h>

using namespace std;

constexpr int M = 8001;

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        int n = n0 + n1 + n2 + 1;
        if (n1 == 0) {
            if (n2 == 0) {
                for (int i = 0; i < n; ++i) cout << '0';
            } else if (n0 == 0) {
                for (int i = 0; i < n; ++i) cout << '1';
            } else {
                assert(false);
            }
        } else {
            cout << '0';
            for (int i = 0; i < n0; ++i) cout << '0';
            cout << '1';
            for (int i = 0; i < n2; ++i) cout << '1';
            for (int i = 0; i < n1 - 1; ++i) {
                if (i & 1) cout << '1';
                else cout << '0';
            }
        }
        cout << '\n';
    }
    return 0;
}