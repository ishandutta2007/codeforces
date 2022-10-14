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
#define ld long double

const long long INFLL = 1e18;
const int INF = 1e9 + 5;
const int mod = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> id;
    while (k) {
        id.pb(k % 2);
        k /= 2;
    }
    ll ans = 0;
    for (int i = 0; i < (int)id.size(); i++) {
        if (!id[i]) continue;
        ll now = 1;
        for (int j = 0; j < i; j++) {
            now *= n;
            now %= mod;
        }
        ans += now;
        ans %= mod;
    }
    cout << ans << "\n";
    return;
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