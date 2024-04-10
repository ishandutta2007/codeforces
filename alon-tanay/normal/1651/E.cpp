#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

void bop(pl &x, ll v) {
    x.f = min(x.f, v);
    x.s = max(x.s, v);
}

int n;

ll cnts(pl &a, pl &b) {
    return a.f * (b.f - n) * (n - a.s + 1) * (2 * n - b.s + 1);
}

string str(pl &a) { return "{" + to_string(a.f) + "," + to_string(a.s) + "}"; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> nei(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    vector<bool> vis(2 * n + 1);
    ll res = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (vis[i]) {
            continue;
        }
        vector<int> cyc;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = true;
            cyc.push_back(cur);
            for (int ne : nei[cur]) {
                if (!vis[ne]) {
                    cur = ne;
                    break;
                }
            }
        }
        ll sz = cyc.size();
        vector<int> cyc2 = cyc;
        for (int c : cyc) {
            cyc2.push_back(c);
        }
        cyc2.push_back(cyc2[0]);
        for (int i = 1; i <= sz; i++) {
            pl bndL = {1e9, 0};
            pl bndR = {1e9, 0};
            bop(cyc2[i] > n ? bndR : bndL, cyc2[i]);
            // cout << " ! " << cyc2[i] << endl;
            for (int k = 2; k < sz; k++) {
                // cout << " + " << cyc2[i + k - 1] << endl;
                bop(cyc2[i + k - 1] > n ? bndR : bndL, cyc2[i + k - 1]);
                pl bndL0 = bndL;
                pl bndR0 = bndR;
                pl bndL1 = bndL;
                pl bndR1 = bndR;
                pl bndLB = bndL;
                pl bndRB = bndR;
                if (cyc2[i - 1] > n) {
                    bop(bndR0, cyc2[i - 1]);
                    bop(bndRB, cyc2[i - 1]);
                } else {
                    bop(bndL0, cyc2[i - 1]);
                    bop(bndLB, cyc2[i - 1]);
                }
                if (cyc2[i + k] > n) {
                    bop(bndR1, cyc2[i + k]);
                    bop(bndRB, cyc2[i + k]);
                } else {
                    bop(bndL1, cyc2[i + k]);
                    bop(bndLB, cyc2[i + k]);
                }

                ll cnt = cnts(bndL, bndR);
                cnt -= cnts(bndL0, bndR0);
                cnt -= cnts(bndL1, bndR1);
                cnt += cnts(bndLB, bndRB);
                // cout << "  " << str(bndL) << " " << str(bndR) << endl;
                // cout << cnt << " of size " << k << endl;
                res += cnt * (k / 2);
            }
        }
        pl bndL = {1e9, 0};
        pl bndR = {1e9, 0};
        for (int i = 0; i < sz; i += 2) {
            bop(bndL, cyc[i]);
        }
        for (int i = 1; i < sz; i += 2) {
            bop(bndR, cyc[i]);
        }
        // cout << cnts(bndL, bndR) << " OF FULL CIRCLE " << sz << endl;
        res += cnts(bndL, bndR) * (sz / 2);
    }
    cout << res << "\n";
    return 0;
}