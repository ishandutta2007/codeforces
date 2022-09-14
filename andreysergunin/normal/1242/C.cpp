#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

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

    int n;
    cin >> n;
    vector<vector<int>> a(n);
    map<ll, int> mapa;

    vector<ll> f(n);
    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
            mapa[a[i][j]] = i;
            sum += a[i][j];
            f[i] += a[i][j];
        }
    }

    if (sum % n) {
        cout << "No" << endl;
        return 0;
    }

    sum /= n;
    vector<int> used(n);

    vector<vector<int>> perms(1 << n);
    vector<vector<int>> vals(1 << n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(a[i]); ++j) {
            int x = a[i][j];
            used.assign(n, 0);

            vector<int> perm;
            vector<int> val;
            bool ok = true;
            int cur = i;
            used[cur] = 1;

            while (true) {
                ll y = sum - f[cur] + x;
                if (!mapa.count(y)) {
                    ok = false;
                    break;
                }

                perm.push_back(cur);
                val.push_back(y);

                int prv = mapa[y];
                if (used[prv]) {
                    if (prv != i) {
                        ok = false;
                        break;
                    }
                    if (y != a[i][j]) {
                        ok = false;
                        break;
                    }
                    break;
                }

                cur = prv;
                x = y;
                used[cur] = 1;
            }

            if (!ok) {
                continue;
            }

            int mask = 0;

            for (int i = 0; i < n; ++i) {
                mask |= used[i] << i;
            }

            // cout << "-----------" << endl;
            // for (int i = 0; i < sz(val); ++i) {
            //     cout << val[i] << " " << perm[i] << endl;
            // }

            perms[mask] = perm;
            vals[mask] = val;
        }
    }

    vector<int> prv(1 << n, -1);

    prv[0] = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            if (sz(perms[submask]) > 0 && prv[mask ^ submask] >= 0) {
                prv[mask] = submask;
                break;
            }
        }
    }
    int full = (1 << n) - 1;

    if (prv[full] == -1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    vector<int> res_perm(n);
    vector<int> res_val(n);

    int mask = full;
    while (mask != 0) {
        vector<int> val = vals[prv[mask]];
        vector<int> perm = perms[prv[mask]];

        for (int i = 0; i < sz(val); ++i) {
            int from = mapa[val[i]];
            res_val[from] = val[i];
            res_perm[from] = perm[i];
        }

        mask ^= prv[mask];
    }

    for (int i = 0; i < n; ++i) {
        cout << res_val[i] << " " << res_perm[i] + 1 << endl;
    }



#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}