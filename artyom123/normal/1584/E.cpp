#include<bits/stdc++.h>

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

struct Sparse_Table{
    vector<vector<pair<ll, int>>> st;
    Sparse_Table(vector<ll> &a) {
        int n = a.size();
        st.resize(n);
        for (auto &c : st) {
            c.resize(32 - __builtin_clz(n));
        }
        for (int i = 0; i < n; i++) {
            st[i][0] = mp(a[i], 1);
        }
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j].fi = min(st[i][j - 1].fi, st[i + (1 << (j - 1))][j - 1].fi);
                if (st[i][j - 1].fi < st[i + (1 << (j - 1))][j - 1].fi) st[i][j].se = st[i][j - 1].se;
                else if (st[i][j - 1].fi > st[i + (1 << (j - 1))][j - 1].fi) {
                    st[i][j].se = st[i + (1 << (j - 1))][j - 1].se;
                } else {
                    st[i][j].se = st[i][j - 1].se + st[i + (1 << (j - 1))][j - 1].se;
                }
            }
        }
    }
    ll get(int l, int r) {
        int len = r - l;
        int p = 31 - __builtin_clz(len);
        return min(st[l][p].fi, st[r - (1 << p)][p].fi);
    }

    int get_cnt(int l, int r) {
        int len = r - l;
        ll cur_mn = INFLL;
        int cur_cnt = 0;
        for (int i = 0; i < 20; i++) {
            if (len & (1 << i)) {
                ll mn = st[l][i].fi;
                int cnt = st[l][i].se;
                if (mn < cur_mn) {
                    cur_mn = mn;
                    cur_cnt = cnt;
                } else if (mn == cur_mn) {
                    cur_cnt += cnt;
                }
                l += (1 << i);
            }
        }
        return cur_cnt;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<ll> b(n);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur *= -1;
        b[i] = a[i] + cur;
        cur += a[i];
    }
    vector<ll> b0(n, INFLL);
    for (int i = 0; i < n; i += 2) b0[i] = b[i];
    vector<ll> b1(n, INFLL);
    for (int i = 1; i < n; i += 2) b1[i] = b[i];
    Sparse_Table st0(b0), st1(b1);
    cur = 0;
    ll ans = 0;
    for (int l = 0; l < n; l++) {
        int left = l, right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            ll mn0 = st0.get(left, mid + 1), mn1 = st1.get(left, mid + 1);
            if (l % 2 == 0) {
                mn0 += cur;
                mn1 -= cur;
            } else {
                mn0 -= cur;
                mn1 += cur;
            }
            if (mn0 >= 0 && mn1 >= 0) left = mid;
            else right = mid;
        }
        int cnt0 = st0.get_cnt(l, left + 1), cnt1 = st1.get_cnt(l, left + 1);
        ll mn0 = st0.get(l, left + 1), mn1 = st1.get(l, left + 1);
        if (mn0 != INFLL) {
            if (l % 2 == 0) mn0 += cur;
            else mn0 -= cur;
            if (mn0 == 0) ans += cnt0;
        }
        if (mn1 != INFLL) {
            if (l % 2 == 0) mn1 -= cur;
            else mn1 += cur;
            if (mn1 == 0) ans += cnt1;
        }
        cur *= -1;
        cur += a[l];
    }
    cout << ans << "\n";
    return;
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
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}