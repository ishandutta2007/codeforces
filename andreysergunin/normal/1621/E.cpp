#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

struct Group {
    ll k;
    ll sum;
    vector<ll> b;
    string res;
    int id;
};

bool operator<(const Group &a, const Group &b) {
    return a.sum * b.k < b.sum * a.k;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<Group> g(m);
    for (int i = 0; i < m; ++i) {
        cin >> g[i].k;
        g[i].b.resize(g[i].k);
        g[i].id = i;
        for (ll &x : g[i].b) {
            cin >> x;
            g[i].sum += x;
        }
        g[i].res.resize(g[i].k, '.');
    }

    sort(all(a));
    a = vector<ll>(a.end() - m, a.end());
    sort(all(g));

    vector<bool> pref(m + 1), suff(m + 1);
    set<int> bad_lf, bad_rg;

    pref[0] = suff[m] = true;
    for (int i = 0; i < m; ++i) {
        pref[i + 1] = pref[i] & (a[i] * g[i].k >= g[i].sum);
    }
    for (int i = m - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] & (a[i] * g[i].k >= g[i].sum);
    }
    for (int i = 0; i < m; ++i) {
        if (i > 0 && a[i - 1] * g[i].k < g[i].sum) {
            bad_lf.insert(i);
        }
        if (i + 1 < m && a[i + 1] * g[i].k < g[i].sum) {
            bad_rg.insert(i);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < g[i].k; ++j) {
            Group new_group;
            new_group.k = g[i].k - 1;
            new_group.sum = g[i].sum - g[i].b[j];
            int pos = lower_bound(all(g), new_group) - g.begin();

            bool ok = true;
            if (pos > i) {
                --pos;
                ok &= pref[i] & suff[pos + 1];
                ok &= a[pos] * new_group.k >= new_group.sum;
                auto it = bad_lf.lower_bound(i + 1);
                ok &= (it == bad_lf.end() || *it > pos);
            } else {
                ok &= pref[pos] & suff[i + 1];
                ok &= a[pos] * new_group.k >= new_group.sum;
                auto it = bad_rg.lower_bound(pos + 1);
                ok &= (it == bad_rg.end() || *it > i);
            }
            g[i].res[j] = ok ? '1' : '0';
        }
    }
    sort(all(g), [&](const Group &a, const Group &b) {
        return a.id < b.id;
    });
    string res;
    for (int i = 0; i < m; ++i) {
        res += g[i].res;
    }
    cout << res << endl;
}