#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAX_VALUE = 1'000'000'000;
int a[MAXN], b[MAXN];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    b[n + 1] = MAX_VALUE;
    int answer = 0;
    for (int i = 1; i <= n - 1; i++) {
        int t = min(a[i], a[i + 1]);
        int p = max(a[i], a[i + 1]);

        bool isTGood = 0;
        if (lower_bound(b + 1, b + n + 1, t) - b <= k)
            isTGood = 1;

        bool isPGood = 0;
        if (lower_bound(b + 1, b + n + 1, p) - b <= k and lower_bound(b + 1, b + n + 1, t) - b < k)
            isPGood = 1;

        int ans1 = min(t, 2 * b[k + 1]);
        int ans2 = min(p, 2 * b[k + isTGood]);
        int ans3 = (k >= 2) * 2 * b[k - 1 + isTGood + isPGood];
        answer = max({answer, ans1, ans2, ans3});
    }
    cout << min(MAX_VALUE, answer) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}