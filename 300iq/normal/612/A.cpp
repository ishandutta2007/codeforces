#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    for (int i = 0; p * i <= n; i++) {
        for (int j = 0; q * j <= n; j++) {
            if (i * p + j * q == n) {
                cout << i + j << endl;
                char c;
                while(i--) {
                    for (int t = 0; t < p; t++) {
                        cin >> c;
                        cout << c;
                    }
                    cout << endl;
                }
                while (j--) {
                    for (int t = 0; t < q; t++) {
                        cin >> c;
                        cout << c;
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}