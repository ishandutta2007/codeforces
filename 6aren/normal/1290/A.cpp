#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int a[3505];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (m - 1 <= k) {
            int ans = 0;
            for (int i = 0; i <= m - 1; i++) {
                int t = m - 1 - i;
                ans = max(ans, max(a[i + 1], a[n - t]));
            }
            cout << ans << '\n';
            continue;
        } else {
            int ans = 0;  
            for (int i = 0; i <= k; i++) {
                int t = k - i;
                int l = i + 1;
                int r = n - t;
                int rem = m - 1 - k;
                int temp = 1e9 + 1;
                for (int j = 0; j <= rem; j++) {
                    int tt = rem - j;
                    temp = min(temp, max(a[l + j], a[r - tt]));
                }
                ans = max(ans, temp);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}