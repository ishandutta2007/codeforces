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

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &l : a) cin >> l;
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ll mn = 0, cur = 0;
        for (int j = i + 1; j < n; j += 2) {
            ll x = 0;
            ll y = 0;
            if (mn < 0) x = -mn;
            ll b = cur - mn;
            y = b;
            if (x <= a[i] && y <= a[j]) {
                if (x == 0 || y == 0) {
                    x++;
                    y++;
                }
                ans += min(a[i] - x + 1, a[j] - y + 1);
            }
            cur -= a[j];
            mn = min(mn, cur);
            if (j + 1 < n) cur += a[j + 1];
        }
    }
    cout << ans;
    return 0;
}