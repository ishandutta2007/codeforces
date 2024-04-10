#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 200005;

ii a[N], b[N];
pair<ii, int> c[N];
int n, m, p;
vector<ii> aa;
long long it[4 * N];
long long lazy[4 * N];

void build(int k, int l, int r) {
    if (l == r) {
        it[k] = -aa[l].y;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    it[k] = max(it[2 * k], it[2 * k + 1]);
}

void down(int k) {
    long long val = lazy[k];
    if (val == 0) return;
    lazy[k] = 0;
    lazy[2 * k] += val;
    lazy[2 * k + 1] += val;
    it[2 * k] += val;
    it[2 * k + 1] += val;
}

void update(int k, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        it[k] += val;
        lazy[k] += val;
        return;
    }
    down(k);
    int mid = (l + r) / 2;
    update(2 * k, l, mid, u, v, val);
    update(2 * k + 1, mid + 1, r, u, v, val);
    it[k] = max(it[2 * k], it[2 * k + 1]);
}

long long get(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return -1e18;
    if (l >= u && r <= v) {
        return it[k];
    }
    down(k);
    int mid = (l + r) / 2;
    return max(get(2 * k, l, mid, u, v), get(2 * k + 1, mid + 1, r, u, v));
}

bool cmp(ii x, ii y) {
    if (x.x == y.x) return x.y > y.y;
    else return x.x < y.x;
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].x >> b[i].y;
    }
    for (int i = 1; i <= p; i++) {
        cin >> c[i].x.y >> c[i].x.x >> c[i].y;
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + m + 1);
    sort(c + 1, c + p + 1);
    aa.pb(a[n]);
    for (int i = n - 1; i >= 1; i--) {
        if (a[i].y > aa.back().y) continue;
        aa.pb(a[i]);
    }
    n = aa.size();
    aa.pb({0, 0});
    reverse(all(aa));
    build(1, 1, n);
    int cur = 1;
    long long ans = -1e18;
    for (int i = 1; i <= m; i++) {
        long long tmpAns = -b[i].y;
        while (cur <= p && c[cur].x.x < b[i].x) {
            int k = upper_bound(aa.begin(), aa.end(), make_pair(c[cur].x.y, 1000000001)) - aa.begin();
            update(1, 1, n, k, n, c[cur].y);
            cur++;
        }
        tmpAns += get(1, 1, n, 1, n);
        ans = max(ans, tmpAns);
    }
    cout << ans;
    return 0;
}