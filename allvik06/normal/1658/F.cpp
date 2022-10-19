#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int cnt1 = 0;
        for (char c : s) {
            cnt1 += c - '0';
        }
        if (m * cnt1 % n != 0) {
            cout << "-1\n";
            continue;
        }
        int cnt2 = m * cnt1 / n;
        vector <int> psum(n + 1);
        for (int i = 0; i < n; ++i) psum[i + 1] = psum[i] + s[i] - '0';
        bool f = false;
        for (int i = 0; i <= n - m; ++i) {
            if (psum[i + m] - psum[i] == cnt2) {
                cout << "1\n" << i + 1 << " " << i + m << "\n";
                f = true;
                break;
            }
        }
        if (!f) {
            for (int i = 0; i < m - 1; ++i) {
                int len = m - (i + 1);
                if (psum[i + 1] + psum[n] - psum[n - len] == cnt2) {
                    cout << "2\n" << 1 << " " << i + 1 << "\n" << n - len + 1 << " " << n << "\n";
                    break;
                }
            }
        }
    }
}