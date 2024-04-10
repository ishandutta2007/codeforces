#include <bits/stdc++.h>

#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;

bool check(int a, int b, int c) {
    return (b > a && b > c) || (b < a && b < c);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i + 1 < n; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ans++;
            }
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
                ans++;
            }
        }
        int sum = ans;
        for (int i = 0; i < n; ++i) {
            int ans1 = sum, ans2 = sum;
            int val1 = a[i], val2 = a[i];
            if (i + 1 < n) {
                val1 = a[i + 1];
            }
            if (i > 0) {
                val2 = a[i - 1];
            }
            if (i > 0 && i + 1 < n && check(a[i - 1], a[i], a[i + 1])) {
                ans1--;
                ans2--;
            }
            if (i + 2 < n && check(a[i], a[i + 1], a[i + 2])) {
                ans1--;
            }
            if (i - 2 >= 0 && check(a[i - 2], a[i - 1], a[i]) && !check(a[i - 2], a[i - 1], val1)) {
                ans1--;
            }
            if (i - 2 >= 0 && !check(a[i - 2], a[i - 1], a[i]) && check(a[i - 2], a[i - 1], val1)) {
                ans1++;
            }
            if (i + 2 < n && check(a[i], a[i + 1], a[i + 2]) && !check(val2, a[i + 1], a[i + 2])) {
                ans2--;
            }
            if (i - 2 >= 0 && check(a[i - 2], a[i - 1], a[i])) {
                ans2--;
            }
            if (i + 2 < n && !check(a[i], a[i + 1], a[i + 2]) && check(val2, a[i + 1], a[i + 2])) {
                ans2++;
            }
            ans = min(ans, min(ans1, ans2));
        }
        cout << ans << '\n';
    }
    return 0;
}