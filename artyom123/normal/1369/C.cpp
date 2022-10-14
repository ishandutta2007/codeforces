#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<int> w(k);
        for (auto &c : w) cin >> c;
        ll ans = 0;
        sort(all(a));
        reverse(all(a));
        sort(all(w));
        for (int i = 0; i < k; i++) {
            if (w[i] == 1) ans += 2 * a[i];
            else ans += a[i];
        }
        for (int i = 0; i < k; i++) w[i]--;
        int j = k;
        for (int i = 0; i < k; i++) {
            if (w[i] == 0) continue;
            ans += a[j + w[i] - 1];
            j += w[i];
        }
        cout << ans << "\n";
    }
    return 0;
}