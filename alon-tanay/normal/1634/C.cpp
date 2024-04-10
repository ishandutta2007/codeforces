#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k == 1) {
            cout << "YES\n";
            for(int i = 1; i <= n; i ++) {
                cout << i << "\n";
            }
            continue;
        }
        if(n&1) {
            cout << "NO\n";
        } else {
            int k2 = 2 * k;
            cout << "YES\n";
            int kn = k * n;
            for(int i = 1; i < kn; i += k2) {
                for(int j = 0; j < k; j ++) {
                    cout << i + j * 2 << " ";
                }
                cout << "\n";
                for(int j = 0; j < k; j ++) {
                    cout << (i+1) + j * 2 << " ";
                }
                cout << "\n";
            }
        }
        /*
        if(k >= 4) {
            cout << "NO\n";
            continue;
        } else if(k == 1) {
            cout << "YES\n";
            for(int i = 1; i <= n; i ++) {
                cout << i << "\n";
            }
        } else if(k == 2) {
            if(n&1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                for(int i = 1; i < n; i += 4) {
                    cout << i << " " << (i+2) << "\n" << (i+1) << " " << (i+3) << "\n";  
                }
            }
        } else if(k == 3) {
            if(n&1) {
                cout << "NO\n";
            } else {
                for(int i = 1; i < n; i += 6) {
                    cout << i << " " << (i+2) << " " << (i+4) << "\n" << (i+1) << " " << (i+3) << " " << (i+5) << "\n";
                }
            }
        }
        */
    }
    return 0;
}