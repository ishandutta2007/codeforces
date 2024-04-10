#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(m), b(m);
        for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
        vector<ll> c = a;
        sort(all(c)); reverse(all(c));
        vector<ll> pr(m + 1);
        for (int i = 0; i < m; i++) pr[i + 1] = pr[i] + c[i];
        ll ans = pr[min(n, m)];
        for (int i = 0; i < m; i++) {
            int left = -1, right = m;
            while (right - left > 1) {
                int mid = (left + right) / 2;
                if (c[mid] > b[i]) left = mid;
                else right = mid;
            }
            int cnt = left + 1;
            ll sum = pr[cnt];
            if (a[i] <= b[i]) {
                cnt++;
                sum += a[i];
            }
            if (cnt >= n) continue;
            ans = max(ans, (n - cnt) * b[i] + sum);
        }
        cout << ans << "\n";
    }
    return 0;
}