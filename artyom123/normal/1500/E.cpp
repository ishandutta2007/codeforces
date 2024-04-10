#include <bits/stdc++.h>
#include <deque>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define pll pair<long long, long long>
#define ll long long
#define ull unsigned long long
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

vector<ull> cnt, sum, pr1, pr2;
map<ull, int> ma;
vector<ull> val;

void mod(int v, int vl, int vr, int id, int d) {
    if (vr - vl == 1) {
        if (d == -1) {
            cnt[v] = sum[v] = pr1[v] = pr2[v] = 0;
        } else {
            cnt[v] = 1;
            sum[v] = pr1[v] = pr2[v] = val[vl];
        }
        return;
    }
    int vm = (vl + vr) / 2;
    if (id < vm) mod(2 * v + 1, vl, vm, id, d);
    else
        mod(2 * v + 2, vm, vr, id, d);
    cnt[v] = cnt[2 * v + 1] + cnt[2 * v + 2];
    sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
    pr1[v] = pr1[2 * v + 2] + pr1[2 * v + 1] + sum[2 * v + 1] * cnt[2 * v + 2];
    pr2[v] = pr2[2 * v + 1] + pr2[2 * v + 2] + sum[2 * v + 2] * cnt[2 * v + 1];
}

ull getsum(int v, int vl, int vr, ull x) {
    if (vr - vl == 1) {
        if (x == 0) return 0;
        return sum[v];
    }
    int vm = (vl + vr) / 2;
    if (cnt[2 * v + 1] >= x) return getsum(2 * v + 1, vl, vm, x);
    else
        return sum[2 * v + 1] + getsum(2 * v + 2, vm, vr, x - cnt[2 * v + 1]);
}

ull getpr1(int v, int vl, int vr, ull x) {
    if (vr - vl == 1) {
        if (x == 0) return 0;
        return sum[v];
    }
    int vm = (vl + vr) / 2;
    if (cnt[2 * v + 1] >= x) return getpr1(2 * v + 1, vl, vm, x);
    else
        return pr1[2 * v + 1] + sum[2 * v + 1] * (x - cnt[2 * v + 1]) + getpr1(2 * v + 2, vm, vr, x - cnt[2 * v + 1]);
}

ull getpr2(int v, int vl, int vr, ull x) {
    if (vr - vl == 1) {
        if (x == 0) return 0;
        return sum[v];
    }
    int vm = (vl + vr) / 2;
    if (cnt[2 * v + 2] >= x) return getpr2(2 * v + 2, vm, vr, x);
    else
        return pr2[2 * v + 2] + sum[2 * v + 2] * (x - cnt[2 * v + 2]) + getpr2(2 * v + 1, vl, vm, x - cnt[2 * v + 2]);
}

ull f(int k) {
    ull res1 = getsum(0, 0, (int)val.size(), k + 1);
    ull res2 = sum[0] - getsum(0, 0, (int)val.size(), cnt[0] - k);
    if (res1 <= res2) return 0;
    return res1 - res2;
}

void solve() {
    if (cnt[0] == 0) {
        cout << 0 << "\n";
        return;
    }
    int left = -1, right = cnt[0] / 2;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (f(mid) <= 0) right = mid;
        else
            left = mid;
    }
    ull ans = 0;
    if (left >= 0) ans += getpr1(0, 0, (int)val.size(), left + 1);
    if (left > 0) ans -= getpr2(0, 0, (int)val.size(), left);
    ans *= 2;
    if (cnt[0] % 2 == 1) ans += f(cnt[0] / 2);
    cout << sum[0] - ans << "\n";
}

void add(ull x) {
    mod(0, 0, (int)val.size(), ma[x], 1);
}

void del(ull x) {
    mod(0, 0, (int)val.size(), ma[x], -1);
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
    int n, q;
    cin >> n >> q;
    vector<ull> a(n);
    for (auto &c : a) {
        cin >> c;
        val.pb(c);
    }
    vector<pair<int, ull>> b(q);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        ull x;
        cin >> x;
        b[i] = {t, x};
        val.pb(x);
    }
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    for (int i = 0; i < (int)val.size(); i++) ma[val[i]] = i;
    cnt.resize(4 * val.size());
    sum.resize(4 * val.size());
    pr1.resize(4 * val.size());
    pr2.resize(4 * val.size());
    for (auto &x : a) add(x);
    solve();
    for (int i = 0; i < q; i++) {
        if (b[i].fi == 1) add(b[i].se);
        else
            del(b[i].se);
        solve();
    }
    return 0;
}