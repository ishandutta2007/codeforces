#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 1e5 + 10;
const ll INF = 1e18 + 1;
const ll MOD = 1e9 + 7;

pair<int, int> a[N];

ll powMod(ll x, ll a) {
    if (a == 0)
        return 1;
    if (a % 2)
        return powMod(x, a - 1) * x % MOD;
    ll tmp = powMod(x, a / 2);
    return tmp * tmp % MOD;
}

ll fac[N];
ll bfac[N];
ll pw25[N];

void prec() {
    fac[0] = 1;
    bfac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        bfac[i] = powMod(fac[i], MOD - 2);
    }
    pw25[0] = 1;
    for (int i = 1; i < N; i++) {
        pw25[i] = (pw25[i - 1] * 25) % MOD;
    }
}

int ans[451][N];

void solve() {
    int m;
    cin >> m;
    string s, st;
    cin >> st;
    prec();

    set<int> ks = {st.size()};

    for (int i = 0; i < m; i++) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            cin >> s;
            a[i] = {1, s.size()};
            ks.insert(s.size());
        } else {
            int n;
            cin >> n;
            a[i] = {2, n};
        }
    }

    vector<int> vks;
    map<int, int> backKs;
    for (auto x: ks) {
        backKs[x] = vks.size();
        vks.pb(x);
    }

    for (int i = 0; i < (int)vks.size(); ++i) {
        int k = vks[i];
        ans[i][k] = 1;
        for (int n = k + 1; n < N; n++) {
            ans[i][n] = ((ll)ans[i][n - 1] * 26 + fac[n - 1] * bfac[n - k] %
                MOD * bfac[k - 1] % MOD * pw25[n - k] % MOD) % MOD;
        }
    }

    int curk = st.size();
    for (int i = 0; i < m; i++) {
        if (a[i].first == 1) {
            curk = a[i].second;
        } else {
            cout << ans[backKs[curk]][a[i].second] << endl;
        }
    }



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int tst = 1;
    while (tst--)
        solve();
}