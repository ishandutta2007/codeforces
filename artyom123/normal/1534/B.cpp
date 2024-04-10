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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        a.insert(a.begin(), 0);
        a.pb(0);
        ll ans = 0;
        for (int i = 1; i + 1 < (int)a.size(); i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ll d = min(a[i] - a[i - 1], a[i] - a[i + 1]);
                ans += d;
                a[i] -= d;
            }
        }
        ans += a[0] + a.back();
        for (int i = 0; i + 1 < (int)a.size(); i++) ans += abs(a[i] - a[i + 1]);
        cout << ans << "\n";
    }
    return 0;
}