#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;
const int MAXN = 3e5 + 5;

void incr(int x, int d, vector<ll> &f) {
    for (; x < (int)f.size(); x |= (x + 1)) f[x] += d;
}

ll get(int x, vector<ll> &f) {
    ll ans = 0;
    for (; x >= 0; x = ((x & (x + 1)) - 1)) ans += f[x];
    return ans;
}

vector<ll> t(4 * MAXN), tadd(4 * MAXN);

void mod(int v, int vl, int vr, int l, int r, ll d) {
    if (r <= l) return;
    if (vl >= l && vr <= r) {
        tadd[v] += d;
        t[v] += d * (vr - vl);
        return;
    }
    if (vl >= r || vr <= l) return;
    int vm = (vl + vr) / 2;
    mod(2 * v + 1, vl, vm, l, r, d);
    mod(2 * v + 2, vm, vr, l, r, d);
    t[v] = t[2 * v + 1] + t[2 * v + 2] + tadd[v] * (vr - vl);
}

ll get(int v, int vl, int vr, int l, int r) {
    if (r <= l) return 0;
    if (vl >= l && vr <= r) return t[v];
    if (vl >= r || vr <= l) return 0;
    int vm = (vl + vr) / 2;
    tadd[2 * v + 1] += tadd[v];
    tadd[2 * v + 2] += tadd[v];
    t[2 * v + 1] += (vm - vl) * tadd[v];
    t[2 * v + 2] += (vr - vm) * tadd[v];
    tadd[v] = 0;
    return get(2 * v + 1, vl, vm, l, r) + get(2 * v + 2, vm, vr, l, r);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<ll> f1(MAXN), f2(MAXN);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = 0; j < MAXN; j += x) {
            ans += (get(min(MAXN - 1, j + x - 1), f1) - get(j - 1, f1)) - (ll)j * (get(min(MAXN - 1, j + x - 1), f2) - get(j - 1, f2));
        }
        incr(x, 1, f2);
        incr(x, x, f1);
        ans += get(0, 0, MAXN, 0, x + 1);
        //ans += b[x];
        for (int j = 0; j < MAXN; j += x) {
            //for (int k = j; k < j + x && k < MAXN; k++) b[k] += k - j;
            mod(0, 0, MAXN, j + 1, min(MAXN, j + x), 1);
            if (j + x < MAXN) mod(0, 0, MAXN, j + x, j + x + 1, -(x - 1));
        }
        cout << ans << " ";
    }
    return 0;
}