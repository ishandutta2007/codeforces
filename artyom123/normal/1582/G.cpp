#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double
#define ll long long
#define pll pair<long long, long long>

const long long INFLL = 1e18;
const int INF = 1e9 + 1;
const int MAXN = 1e6 + 1;

vector<int> tmn;

void mod(int v, int vl, int vr, int l, int r, int x) {
    if (x >= tmn[v]) return;
    if (vl >= l && vr <= r) {
        tmn[v] = min(tmn[v], x);
        return;
    }
    if (r <= vl || l >= vr) return;
    int vm = (vl + vr) >> 1;
    mod(2 * v + 1, vl, vm, l, r, x);
    mod(2 * v + 2, vm, vr, l, r, x);
}

void push(int v) {
    tmn[2 * v + 1] = min(tmn[2 * v + 1], tmn[v]);
    tmn[2 * v + 2] = min(tmn[2 * v + 2], tmn[v]);
}

int get(int v, int vl, int vr, int id) {
    if (vr - vl == 1) return tmn[v];
    push(v);
    int vm = (vl + vr) / 2;
    if (id < vm) return get(2 * v + 1, vl, vm, id);
    else return get(2 * v + 2, vm, vr, id);
}

vector<int> t, tadd;

void mod1(int v, int vl, int vr, int l, int r, int d) {
    if (vl >= l && vr <= r) {
        tadd[v] += d;
        t[v] += d;
        return;
    }
    if (r <= vl || l >= vr) return;
    int vm = (vl + vr) >> 1;
    mod1(2 * v + 1, vl, vm, l, r, d);
    mod1(2 * v + 2, vm, vr, l, r, d);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]) + tadd[v];
}

int get1(int v, int vl, int vr) {
    int d = 0;
    while (1) {
        if (t[v] + d >= 0) return vr;
        if (vr - vl == 1) return vl;
        int vm = (vl + vr) >> 1;
        d += tadd[v];
        if (t[2 * v + 1] + d < 0) {
            v = 2 * v + 1;
            vr = vm;
        }
        else {
            v = 2 * v + 2;
            vl = vm;
        }
    }
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    string s;
    cin >> s;
    vector<vector<pii>> fact(MAXN);
    vector<int> mn(MAXN);
    vector<int> p;
    for (int i = 2; i < MAXN; i++) {
        if (!mn[i]) {
            mn[i] = i;
            p.pb(i);
        }
        for (int j = 0; j < (int)p.size() && p[j] <= mn[i] && p[j] * i < MAXN; j++) {
            mn[p[j] * i] = p[j];
        }
    }
    tmn.assign(4 * n, n);
    t.resize(4 * n);
    tadd.resize(4 * n);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 1) {
            if (fact[mn[x]].size() && fact[mn[x]].back().fi == i) fact[mn[x]].back().se++;
            else fact[mn[x]].pb(i, 1);
            x /= mn[x];
        }
    }
    vector<int> kek(n, n);
    for (int x = 0; x < MAXN; x++) {
        if (fact[x].empty()) continue;
        for (int i = 0; i < 4 * (int)fact[x].size(); i++) {
            t[i] = 0;
            tadd[i] = 0;
        }
        for (int j = (int)fact[x].size() - 1; j >= 0; j--) {
            int d = fact[x][j].se;
            if (s[fact[x][j].fi] == '/') d *= -1;
            mod1(0, 0, fact[x].size(), j, fact[x].size(), d);
            int id = get1(0, 0, fact[x].size());
            if (id == (int)fact[x].size()) continue;
            int pr = 0;
            if (j > 0) pr = fact[x][j - 1].fi + 1;
            if (fact[x][j].fi - pr < 20) {
                for (int k = pr; k <= fact[x][j].fi; k++) {
                    kek[k] = min(kek[k], fact[x][id].fi);
                }
                continue;
            }
            mod(0, 0, n, pr, fact[x][j].fi + 1, fact[x][id].fi);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(0, min(kek[i], get(0, 0, n, i)) - i);
    }
    cout << ans;
    return 0;
}