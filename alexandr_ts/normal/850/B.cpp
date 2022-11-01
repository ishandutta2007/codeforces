#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 5e5 + 10;
const ll INF = 1e17 + 1;
const ll MOD = 1e9 + 7;
const int M = 1e6 + 10;

int pref[M];
ll prefSum[M];

ll cnt(int l, int r) {
    r = min(r, M - 1);
    l = max(l, 0);
    if (l > r) return 0;
    return pref[r] - (l == 0 ? 0 : pref[l - 1]);
}

ll sum(int l, int r) {
    r = min(r, M - 1);
    l = max(l, 0);
    if (l > r) return 0;
    return prefSum[r] - (l == 0 ? 0 : prefSum[l - 1]);
}

int a[N];

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[a[i]]++;
        prefSum[a[i]] += a[i];
    }

    for (int i = 1; i < M; i++) {
        pref[i] += pref[i - 1];
        prefSum[i] += prefSum[i - 1];
    }

    ll ans = n * x;

    int mxEl = *max_element(a, a + n);

    for (int g = 2; g <= mxEl + 1; g++) {
        ll curans = 0;
        for (int k = g; k <= g + mxEl + 1; k += g) {
            ll f = max((ll)k - g, k - x / y - 1);
            curans += (cnt(k - g + 1, f) * x + (k * cnt(f + 1, k) - sum(f + 1, k)) * y);
        }

        //cout << curans << " " << g << endl;

        ans = min(ans, curans);
    }
    cout << ans << endl;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int tst = 1;
    while (tst--)
        solve();
}