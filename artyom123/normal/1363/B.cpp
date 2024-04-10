#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sum0 = 0, sum1 = 0;
        for (auto &c : s) c -= '0';
        for (auto &c : s) {
            if (c == 0) sum0++;
            else sum1++;
        }
        int ans = INF;
        int now1 = 0, now0 = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            ans = min(ans, now1 + sum0 - now0);
            if (s[i] == 0) now0++;
            else now1++;
        }
        now1 = 0, now0 = 0;
        for (int i = 0; i < n; i++) {
            ans = min(ans, now0 + sum1 - now1);
            if (s[i] == 0) now0++;
            else now1++;
        }
        cout << ans << "\n";
    }
    return 0;
}