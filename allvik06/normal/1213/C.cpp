#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k) {
        int n, m;
        cin >> n >> m;
        vector <bool> a(10, false);
        vector <int> por;
        for (int i = 1; i < 11; ++i) {
            if (!a[(m * i) % 10]) {
                a[(m * i) % 10] = true;
                por.push_back(m * i);
            }
            else {
                break;
            }
        }
        int sum = 0;
        for (auto i : por) {
            sum += i % 10;
        }
        int ans = sum * (int)(n / (por.back()));
        for (int i = 0; por[i] <= n % (por.back()); ++i) {
            ans += por[i] % 10;
        }
        cout << ans << "\n";
    }
}