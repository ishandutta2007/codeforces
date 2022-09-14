#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }


#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

const int LIM = 1000;
const int MAXN = 500500;
const int INF = 2 * MAXN - 1;

int pref_mn[MAXN], suff_mx[MAXN];

int used_x[MAXN], used_y[2 * MAXN];
int pref_x[MAXN], pref_y[2 * MAXN];

int minn[MAXN], maxx[MAXN];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pii> queries;
    vector<int> pos;
    vector<int> cand;

    for (int qw = 0; qw < q; ) {
        memset(used_x, 0, sizeof(used_x));
        memset(used_y, 0, sizeof(used_y));

        for (int i = 0; i < LIM && qw < q; ++i, ++qw) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            queries.push_back({pos, val});
            used_x[pos] = true;

            used_y[a[pos]] = true;
            used_y[val] = true;
        }

        for (int i = 0; i < n; ++i) {
            if (used_x[i]) {
                pos.push_back(i);
            }
        }

        pref_mn[0] = INF;
        for (int i = 0; i < n; ++i) {
            if (used_x[i]) {
                pref_mn[i + 1] = pref_mn[i];
            } else {
                pref_mn[i + 1] = min(pref_mn[i], a[i]);
            }
        }

        suff_mx[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (used_x[i]) {
                suff_mx[i] = suff_mx[i + 1];
            } else {
                suff_mx[i] = max(suff_mx[i + 1], a[i]);
            }
        }

        for (int i = 1; i < n; ++i) {
            if (pref_mn[i] > suff_mx[i]) {
                cand.push_back(i);
            }
        }

        pref_x[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref_x[i + 1] = pref_x[i] + used_x[i];
        }

        pref_y[0] = 0;
        for (int i = 1; i < 2 * MAXN; ++i) {
            pref_y[i] = pref_y[i - 1] + used_y[i];
        }

        if (sz(cand) > 0) {
            vector<int> cnt = {1};
            int it = 0;

            for (int i = 1; i < sz(cand); ++i) {
                if (pref_y[pref_mn[cand[it]]] - pref_y[suff_mx[cand[i]] - 1] > 0 || 
                            pref_x[cand[i]] - pref_x[cand[it]] > 0) {
                    cnt.push_back(1);
                    ++it;
                    cand[it] = cand[i];
                } else {
                    ++cnt.back();
                }
            }

            cand.resize(it + 1);

            // cerr << sz(cand) << endl;

            for (auto [ps, val] : queries) {
                a[ps] = val;

                int i = 0;
                int j = 0;

                int cur_minn = INF;
                int cur_maxx = 0;

                while (i < sz(pos) || j < sz(cand)) {
                    if (i == sz(pos) || (j < sz(cand) && pos[i] >= cand[j])) {
                        minn[j] = min(cur_minn, pref_mn[cand[j]]);
                        ++j;
                    } else {
                        cur_minn = min(cur_minn, a[pos[i]]);
                        ++i;
                    }
                }

                i = sz(pos) - 1;
                j = sz(cand) - 1;
                while (i >= 0 || j >= 0) {
                    if (i == -1 || (j >= 0 && pos[i] < cand[j])) {
                        maxx[j] = max(cur_maxx, suff_mx[cand[j]]);
                        --j;
                    } else {
                        cur_maxx = max(cur_maxx, a[pos[i]]);
                        --i;
                    }
                }

                int res = 0;

                for (int i = 0; i < sz(cand); ++i) {
                    if (maxx[i] < minn[i]) {
                        res += cnt[i];
                    }
                }

                cout << res + 1 << "\n";
            }

        } else {
            for (auto [ps, val] : queries) {
                a[ps] = val;
                cout << 1 << "\n";
            }
        }

        pos.clear();
        queries.clear();
        cand.clear();
    }

}