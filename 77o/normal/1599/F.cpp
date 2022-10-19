#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 5e5;

ll f0[N], f1[N], f2[N], f3[N];

ll get(ll f[], int pos) {
    ll res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += f[pos];
        if (res >= MOD) res -= MOD;
    }
    return res;
}

void add(ll f[], int pos, ll val) {
    val = (val % MOD + MOD) % MOD; 
    for (; pos < N; pos |= pos + 1) {
        f[pos] += val;
        if (f[pos] >= MOD) f[pos] -= MOD;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    struct Query {
        int l;
        ll d;
        int id;
    };
    
    vector<vector<Query>> queries(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        queries[r - 1].push_back(Query{l - 1, d, i});
    }
    
    ll inv6 = binpow(6, MOD - 2);
    ll inv2 = binpow(2, MOD - 2);
    auto getSquareSum = [&](ll n) {
        return n * (n + 1) % MOD * (n * 2 + 1) % MOD * inv6 % MOD;
    };

    map<ll, int> last;
    vector<int> ans(q);
    for (int i = 0; i < n; i++) {
        if (last.count(a[i])) {
            int pos = last[a[i]];
            add(f0, pos, -1);
            add(f1, pos, -a[i]);
            add(f2, pos, -a[i] * a[i]);
        }
        last[a[i]] = i;
        add(f0, i, 1);
        add(f1, i, a[i]);
        add(f2, i, a[i] * a[i]);
        for (auto query : queries[i]) {
            ll cnt = get(f0, i) - get(f0, query.l - 1);
            ll sum = get(f1, i) - get(f1, query.l - 1);
            ll h = get(f2, i) - get(f2, query.l - 1);
            // (2a + cnt - 1) * cnt = 2 * sum / d
            sum = (sum + MOD) % MOD * binpow(query.d, MOD - 2) % MOD * 2 % MOD;
            ll a = ((sum + cnt - cnt * cnt) % MOD + MOD) % MOD;
            a = a * binpow(cnt, MOD - 2) % MOD * inv2 % MOD;
            // a + (a + 1)^2 + (a + 2)^2 + .. (a + cnt - 1)^2
            h = (h + MOD) % MOD;
            ll need = (getSquareSum(a + cnt - 1) - getSquareSum(a - 1) + MOD) % MOD;
            need = need * query.d % MOD * query.d % MOD;
            // cerr << query.id << ' ' << need << ' ' << h << endl;
            ans[query.id] = (need == h);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}