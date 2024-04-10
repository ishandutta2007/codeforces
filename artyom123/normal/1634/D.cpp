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
    int n;
    cin >> n;
    vector<pii> a;
    for (int i = 3; i <= n; i++) {
        cout << '?' << " " << 1 << " " << 2 << " " << i << endl;
        int x;
        cin >> x;
        a.pb(x, i);
    }
    sort(all(a));
    if (a[0].fi != a.back().fi) {
        vector<int> id;
        for (int j = 1; j <= n; j++) {
            if (j != a.back().se) id.pb(j);
        }
        int mxi = -1, mx = -1;
        for (int i = 0; i < (int)id.size() - 1; i++) {
            cout << '?' << " " << a.back().se << " " << id[i] << " " << id[i + 1] << endl;
            int x;
            cin >> x;
            if (x > mx) {
                mx = x;
                mxi = i;
            }
        }
        int v = id[mxi], u = id[mxi + 1];
        int j = 1;
        while (j == v || j == u || j == a.back().se) j++;
        cout << '?' << " " << a.back().se << " " << v << " " << j << endl;
        int x;
        cin >> x;
        if (x == mx) cout << '!' << " " << a.back().se << " " << v << endl;
        else cout << '!' << " " << a.back().se << " " << u << endl;
    } else {
        vector<int> id;
        for (int j = 1; j <= n; j++) {
            if (j != 3) id.pb(j);
        }
        int mxi = -1, mx = -1;
        for (int i = 0; i < (int)id.size() - 1; i++) {
            cout << '?' << " " << 3 << " " << id[i] << " " << id[i + 1] << endl;
            int x;
            cin >> x;
            if (x > mx) {
                mx = x;
                mxi = i;
            }
        }
        if (mxi == 0) {
            cout << '!' << " " << 1 << " " << 2 << endl;
            return;
        }
        int v = id[mxi], u = id[mxi + 1];
        int j = 1;
        while (j == v || j == u || j == 3) j++;
        cout << '?' << " " << 3 << " " << v << " " << j << endl;
        int x;
        cin >> x;
        if (x == mx) cout << '!' << " " << 3 << " " << v << endl;
        else cout << '!' << " " << 3 << " " << u << endl;
    }
}

int main() {
    /*
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    */
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}