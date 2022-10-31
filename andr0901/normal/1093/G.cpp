#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
vector <vector <pii>> tr;
int n, k;

vector <pii> merge(const vector <pii>& a, const vector <pii>& b) {
    vector <pii> ans(1 << k);
    forn (i, 0, 1 << k)
        ans[i] = {min(a[i].fs, b[i].fs), max(a[i].sc, b[i].sc)};
    return ans;
}

void upd(int v, int vl, int vr, int idx, const vector <int>& b) {
    if (vr - vl == 1) {
        forn (msk, 0, 1 << k) {
            tr[v][msk] = {0, 0};
            forn (j, 0, k) {
                if ((msk >> j) & 1) 
                    tr[v][msk].fs += b[j], tr[v][msk].sc += b[j];
                else 
                    tr[v][msk].fs -= b[j], tr[v][msk].sc -= b[j];
            }
        }
        return;
    } 
    int vm = vl + vr >> 1;
    if (idx < vm)
        upd(2 * v, vl, vm, idx, b);
    else 
        upd(2 * v + 1, vm, vr, idx, b);
    tr[v] = merge(tr[2 * v], tr[2 * v + 1]);
}

vector <pii> get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl)
        return vector <pii> (1 << k, {INF, -INF});
    if (l <= vl && vr <= r)
        return tr[v];
    int vm = vl + vr >> 1;
    return merge(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    vector <vector <int>> a(n, vector <int> (k));
    forn (i, 0, n) 
        forn (j, 0, k)
            cin >> a[i][j];
    tr.resize(4 * n, vector <pii> (1 << k, {INF, -INF}));
    forn (i, 0, n)
        upd(1, 0, n, i, a[i]);
    int m;
    cin >> m;
    while (m --> 0) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int idx;
            cin >> idx;
            idx--;
            vector <int> b(k);
            forn (i, 0, k)
                cin >> b[i];
            upd(1, 0, n, idx, b);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            vector <pii> q = get(1, 0, n, l, r);
            int ans = -INF;
            forn (i, 0, 1 << k) 
                ans = max(ans, abs(q[i].sc - q[i].fs));
            cout << ans << "\n";
        }
    }
    return 0;
}