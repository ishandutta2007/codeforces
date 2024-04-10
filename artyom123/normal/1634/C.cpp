#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    if (((n * k) / 2) % k != 0) {
        cout << "NO\n";
        return;
    }
    if (((n * k + 1) / 2) % k != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int s = 1; s <= n * k; s += k * 2) {
        int x = s;
        for (int it = 0; it < k; it++) {
            cout << x << " ";
            x += 2;
        }
        cout << "\n";
    }
    for (int s = 2; s <= n * k; s += k * 2) {
        int x = s;
        for (int it = 0; it < k; it++) {
            cout << x << " ";
            x += 2;
        }
        cout << "\n";
    }
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}