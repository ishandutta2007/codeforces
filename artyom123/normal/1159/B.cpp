#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

long long INF = 1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    long long ans = INF;
    vector <int> a(n);
    for (auto &c : a) {
        cin >> c;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            long long now = min(a[i], a[n - 1]) / (n - 1);
            ans = min(ans, now);
            continue;
        }
        if (i == n - 1) {
            long long now = min(a[i], a[0]) / (n - 1);
            ans = min(ans, now);
            continue;
        }
        long long now1 = min(a[i], a[0]) / i;
        long long now2 = min(a[i], a[n - 1]) / (n - 1 - i);
        ans = min(ans, min(now1, now2));
    }
    cout << ans;
    return 0;
}