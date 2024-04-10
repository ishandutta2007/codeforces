#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pii> a(k);
        vector<int> usd(2 * n);
        for (int i = 0; i < k; i++) {
            cin >> a[i].fi >> a[i].se;
            a[i].fi--;
            a[i].se--;
            usd[a[i].fi] = usd[a[i].se] = 1;
            if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (a[i].se < a[j].fi) continue;
                if (a[i].fi > a[j].se) continue;
                if (a[i].fi < a[j].fi && a[i].se > a[j].se) continue;
                if (a[j].fi < a[i].fi && a[j].se > a[i].se) continue;
                ans++;
            }
        }
        for (auto &c : a) {
            int x = 0;
            for (int i = c.fi; i <= c.se; i++) {
                if (!usd[i]) x++;
            }
            int y = 2 * n - x - 2 * k;
            ans += min(x, y);
        }
        ans += ((n - k) * (n - k - 1)) / 2;
        cout << ans << "\n";
    }
    return 0;
}