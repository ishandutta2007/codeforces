#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 100005;

int n, a[2 * N], mn1[2 * N], mn2[2 * N];

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= 2 * n; i++) {
        mn1[i] = 1e9;
        mn2[i] = 1e9;
    }
    mn1[n] = n;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) cnt1++;
        else cnt2++;
        mn1[cnt1 - cnt2 + n] = n - i;
    }
    cnt1 = 0;
    cnt2 = 0;
    mn2[n] = n;
    for (int i = 2 * n; i >= n + 1; i--) {
        if (a[i] == 1) cnt1++;
        else cnt2++;
        mn2[cnt2 - cnt1 + n] = i - n - 1;
    }
    int ans = 2e9;
    for (int i = 0; i <= 2 * n; i++) {
        ans = min(ans, mn1[i] + mn2[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}