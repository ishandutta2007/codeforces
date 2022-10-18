#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int pref[maxn], a[maxn];

int can(int cnt, int val, int sum) {
    if (val * cnt < sum) return 0;
    return 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = n - k + 1; i <= n; i++) cin >> pref[i];
    int start = n - k + 2;
    for (int i = start; i <= n; i++) a[i] = pref[i] - pref[i - 1];
    if (n == k) {
        start = 1, a[1] = pref[1];
    }
    for (int i = start + 1; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            cout << "No" << '\n';
            return;
        }
    }
    if (k == 1) {
        cout << "Yes" << '\n';
        return;
    }
    if (can(start, a[start], pref[start])) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}