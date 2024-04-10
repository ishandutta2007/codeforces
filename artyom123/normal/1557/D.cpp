 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

vector<vector<pii>> f;
vector<vector<pii>> a;

void build(int x, pii b) {
    for (; x < (int)f.size(); x |= (x + 1)) {
        a[x].pb(b);
    }
}

void incr(int i, int j, pii x) {
    for (; j < (int)f[i].size(); j |= (j + 1)) f[i][j] = max(f[i][j], x);
}

void get(int i, int x, pii &best) {
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        int left = -1, right = a[i].size();
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (a[i][mid].fi >= x) left = mid;
            else right = mid;
        }
        for (int j = left; j >= 0; j = (j & (j + 1)) - 1) best = max(best, f[i][j]);
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
    int n, m;
    cin >> n >> m;
    vector<pii> le;
    vector<vector<int>> ma(n);
    vector<pii> seg(m);
    for (int i = 0; i < m; i++) {
        int j, l, r;
        cin >> j >> l >> r;
        j--;
        le.pb(l, i);
        ma[j].pb(i);
        seg[i] = {l, r};
    }
    sort(all(le));
    vector<int> id(m);
    for (int i = 0; i < m; i++) id[le[i].se] = i;
    f.resize(m);
    a.resize(m);
    for (int i = 0; i < m; i++) {
        build(id[i], mp(seg[i].se, i));
    }
    vector<vector<pii>> w(m);
    for (auto &c : a) {
        sort(all(c));
        reverse(all(c));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            w[a[i][j].se].pb(i, j);
        }
        f[i].resize(a[i].size(), {-1, -1});
    }
    vector<int> dp(n, 1), p(n, -1);
    for (int i = 0; i < n; i++) {
        for (auto &c : ma[i]) {
            int pr_len = upper_bound(all(le), mp(seg[c].se, INF)) - le.begin();
            pii best = {-1, -1};
            if (pr_len) get(pr_len - 1, seg[c].fi, best);
            if (best.fi + 1 > dp[i]) {
                dp[i] = best.fi + 1;
                p[i] = best.se;
            }
        }
        for (auto &c : ma[i]) {
            for (auto &p : w[c]) {
                incr(p.fi, p.se, mp(dp[i], i));
            }
        }
    }
    int lst = 0;
    set<int> ans;
    for (int i = 0; i < n; i++) ans.insert(i);
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[lst]) lst = i;
    }
    while (lst != -1) {
        ans.erase(lst);
        lst = p[lst];
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) cout << c + 1 << " ";
    return 0;
}