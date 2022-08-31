#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = s;
        int k_prime = 1;
        for (int k = 0; k < n; k++) {
            string t = s;
            rotate(t.begin(), t.begin() + k, t.end());
            if (k % 2 != n % 2) {
                reverse(t.begin() + n - k, t.end());
            }
            if (t < ans) {
                ans = t;
                k_prime = k+1;
            }
        }
        cout << ans << '\n';
        cout << k_prime << '\n';
    }
}