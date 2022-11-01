#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int N = (1 << 19);

ll ad[2][2 * N];
ll t[2][2 * N];

void push(int v, int tl, int tr, int i) {
    if (!ad[i][v]) return;
    if (tl < tr) {
        ad[i][2 * v] += ad[i][v];
        ad[i][2 * v + 1] += ad[i][v];
    }
    t[i][v] += ad[i][v] * (tr - tl + 1);
    ad[i][v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int val, int i) {
    push(v, tl, tr, i);
    if (l > tr || tl > r) return;
    if (l <= tl && tr <= r) {
        ad[i][v] += val;
        push(v, tl, tr, i);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, l, r, val, i);
    add(2 * v + 1, tm + 1, tr, l, r, val, i);
    t[i][v] = t[i][2 * v] + t[i][2 * v + 1];
}

ll sum(int v, int tl, int tr, int l, int r, int i) {
    push(v, tl, tr, i);
    if (l > tr || tl > r) return 0;
    if (l <= tl && tr <= r) return t[i][v];
    int tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, r, i) + sum(2 * v + 1, tm + 1, tr, l, r, i);
}

void build(int v, int tl, int tr, int n) {
    if (tl == tr) {
        t[0][v] = tl + 1;
        t[1][v] = n - tl;
        return;
    }

    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm, n);
    build(2 * v + 1, tm + 1, tr, n);
    t[0][v] = t[0][2 * v] + t[0][2 * v + 1];
    t[1][v] = t[1][2 * v] + t[1][2 * v + 1];
}

int a[N];

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> seq(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seq[i] = {a[i], i};
    }
    sort(seq.begin(), seq.end(), greater<pair<int, int>>());
    build(1, 0, n - 1, n);

    ll ans = 0;

    //cout << sum(1, 0, n - 1, 0, n - 1, 0) << endl;
    //cout << sum(1, 0, n - 1, 0, n - 1, 1) << endl;

    for (int i = 0; i < n; i++) {
        int pos = seq[i].second;
        ll val0 = sum(1, 0, n - 1, pos, pos, 0) % MOD;
        ll val1 = sum(1, 0, n - 1, pos, pos, 1) % MOD;
        ll sum0 = (sum(1, 0, n - 1, pos, n - 1, 0) - (n - pos) * (val0 - 1)) % MOD;
        ll sum1 = (sum(1, 0, n - 1, 0, pos, 1) - (pos + 1) * val1) % MOD;
        ll addi = ((pos + 1) * sum0 + (n - pos) * sum1) % MOD;
        ans += addi * seq[i].first;
        ans = ans % MOD;
        if (ans < 0) ans += MOD;

        add(1, 0, n - 1, pos, n - 1, -1, 0);
        add(1, 0, n - 1, 0, pos, -1, 1);

    }

    cout << ans << "\n";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int t = 1;
    while (t--)
        solve();
}