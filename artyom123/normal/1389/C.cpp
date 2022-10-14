#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define fi first
#define se second
#define ll long long

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(10);
        for (auto &c : s) cnt[c - '0']++;
        int ans = n;
        for (auto &c : cnt) ans = min(ans, n - c);
        for (int a = '0'; a <= '9'; a++) {
            for (int b = '0'; b <= '9'; b++) {
                if (a == b) continue;
                int cnt = 0;
                for (auto &c : s) {
                    if (cnt % 2 == 0 && c == a) cnt++;
                    else if (cnt % 2 == 1 && c == b) cnt++;
                }
                if (cnt % 2) cnt--;
                ans = min(ans, n - cnt);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}