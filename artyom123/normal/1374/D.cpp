#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        map<int, int> cnt;
        for (auto &c : a) {
            if ((k - c % k) % k != 0) {
                cnt[(k - c % k) % k]++;
            }
        }
        ll ans = 0;
        for (auto &c : cnt) {
            ans = max(ans, c.fi + k * (c.se - 1) + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}