#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 5e5 + 10;
const ll INF = 1e17 + 1;
const ll MOD = 1e9 + 7;
const int M = 1e6 + 10;
const int H = 41;
const ld EPS = 1e-12;

ld pref[N][H + 1];
int par[N];
vector<int> g[N];
ld pows[H + 1];
ld mults[N][H + 1];

void recalc(int v, int height, int last) {
    assert(v >= 0 && v < N);
    assert(height >= 0 && height <= H);
    if (!height) {
        fill(pref[v], pref[v] + H + 1, 1.0);
        fill(mults[v], mults[v] + H + 1, 1);
    }
    if (g[v].size()) {
        int u = last;
        if (height == 1) {
            if (par[v] != -1 && abs((1 + pref[v][0]) / 2) > EPS)
                mults[par[v]][0] /= ((1 + pref[v][0]) / 2);
            pref[v][0] = pows[g[v].size()];
            if (par[v] != -1)
                mults[par[v]][0] *= ((1 + pref[v][0]) / 2);
        }
        else {
            for (int h = height - 1; h <= height - 1; h++) {
                if (par[v] != -1 && abs((1 + pref[v][0]) / 2) > EPS)
                    mults[par[v]][h] /= ((1 + pref[v][h]) / 2);
                ld tmp = (mults[v][h - 1] -
                    (h - 1 > 0 ? mults[v][h - 2] : pows[g[v].size()]));
                pref[v][h] = tmp + (h - 1 >= 0 ? pref[v][h - 1] : 0);
                assert(pref[v][h] > -EPS && pref[v][h] < 1 + EPS);
                assert(!isnan(pref[v][h]));
                if (par[v] != -1)
                    mults[par[v]][h] *= ((1 + pref[v][h]) / 2);
            }
        }
    }
}

void solve() {
    int q;
    cin >> q;
    fill(par, par + q + 1, -1);
    pows[0] = 1;
    for (int i = 1; i <= H; i++)
        pows[i] = pows[i - 1] / 2.0;
    for (int i = 0; i < q; i++)
        for (int j = 0; j <= H; j++)
            pref[i][j] = 1;

    recalc(0, 0, -1);

    int curInd = 1;
    for (int i = 0; i < q; i++) {
        int typ, v;
        cin >> typ >> v;
        v--;
        if (typ == 1) {
            par[curInd] = v;
            g[v].pb(curInd);

            int u = curInd;
            int lastu = -1;
            for (int i = 0; i < H; i++) {
                recalc(u, i, lastu);
                lastu = u;
                if (par[u] != -1) {
                    u = par[u];
                } else {
                    break;
                }
            }
            curInd++;
        } else {
            ld ans = 0;
            for (int i = 0; i <= H; i++) {
                ld tmp = (pref[v][i] - (i ? pref[v][i - 1] : 0));
                if (!isnan(tmp))
                    ans += i * tmp;
            }
            cout << fixed << setprecision(12) << ans << "\n";
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