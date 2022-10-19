#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        int res = 0;
        for (int i = 0; i < n; i++) {
            vector<int> b = a;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                while (b[j] % 2 == 0) {
                    b[j] /= 2;
                    b[i] *= 2; 
                }
            }
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += b[j];
            }
            res = max(res, tmp);
        }
        cout << res << '\n';
    }
    
    return 0;
}