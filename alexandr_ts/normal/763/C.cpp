#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const int INF = 1e9;
const int LOG = 30;
const ll MOD = 1e9 + 7;
const int N = 1e5 + 10;

ll pw(ll x, int a, ll mod) {
    if (a == 0) return 1;
    if (a % 2) return x * pw(x, a - 1, mod) % mod;
    ll tmp = pw(x, a / 2, mod);
    return tmp * tmp % mod;
}

int a[N];

void solve() {
    ll m, n;
    cin >> m >> n;
    set<int> as;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        as.insert(a[i]);
    }
    sort(a, a + n);

    if (a[0] == 0 && a[n - 1] == n - 1) {
        cout << "0 1\n";
        return;
    }

    if (n == 1) {
        cout << a[0] << " 0\n";
        return;
    }

    vector<pair<int, int>> cands;
    set<int> ds;
    ll sum = accumulate(a, a + n, 0ll) % m;
    for (int i = 0; i < n; i++) {
        ll d = (sum - (ll)n * a[i]) % m * pw((ll)n * (n - 1) / 2 % m, m - 2, m) % m;
        if (d < 0) d += m;
        if (!d) continue;
        cands.pb({d, i});
        ds.insert(d);
    }

    vector<pair<int, int>> newcands;

    for (auto t: cands) {
        int a0 = a[t.second];
        ll d = t.first;
        if (!ds.count(m - d))
            continue;

        if (as.count((a0 + d * (n - 1)) % m) &&
            !as.count((a0 + d * n) % m))
            newcands.pb({d, a0});
    }

    for (auto t: newcands) {
        bool ok = true;
        for (int i = 1; i < n - 1 && ok; i++)
            if (!as.count((t.second + (ll)t.first * i) % m))
                ok = false;
        if (ok) {
            cout << t.second << " " << t.first << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}