#include <bits/stdc++.h>
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using namespace std;
#define int long long
const int maxn = 1e5, INF = 2e12;

struct segTree {
    int n; vector<pair<int, int>> t;
    segTree(int n) : n(n), t(2 * n, {INF, INF}) {}
    void upd(int v, pair<int, int> x) {
        v += n;
        t[v] = min(t[v], x);
        for(v >>= 1; v; v >>= 1) t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    pair<int, int> get(int l, int r) {
        pair<int, int> x = {INF, INF};
        for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if(l & 1) x = min(x, t[l]);
            if(!(r & 1)) x = min(x, t[r]);
        }
        return x;
    }
};

struct tramp {
    int x, d, t, p, id;
    bool operator < (const tramp &he) const {
        return x < he.x;
    }
};

int n, l, ans, lst = -1;
map<int, int> re;
tramp a[maxn];

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> l;
    //if(!n) return cout << l, 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].d >> a[i].t >> a[i].p, a[i].id = i;
        re[a[i].x - a[i].p]; re[a[i].x]; re[a[i].x + a[i].d];
    }
    sort(a, a + n);
    int dif = 0;
    for(auto it = re.begin(); it != re.end(); it++) it->second = dif++;
    ans = l;
    segTree t1(dif), t2(dif);
    vector<int> prev(n, -1);
    for(int i = 0; i < n; i++) if(a[i].x - a[i].p >= 0) {
        int bou = re[a[i].x - a[i].p];
        pair<int, int> x1 = t1.get(0, bou);
        pair<int, int> x2 = t2.get(bou + 1, dif - 1);
        pair<int, int> me = min({make_pair(a[i].x, -1LL), make_pair(x1.first + a[i].x, x1.second), make_pair(x2.first - a[i].x + 2 * a[i].p, x2.second)});
        me.first += a[i].t;
        if(me.first + (l - (a[i].x + a[i].d)) < ans) {
            ans = me.first + (l - (a[i].x + a[i].d));
            lst = i;
        }
        prev[i] = me.second;
        t1.upd(re[a[i].x + a[i].d], {me.first - a[i].x - a[i].d, i});
        t2.upd(re[a[i].x + a[i].d], {me.first + a[i].x + a[i].d, i});
    }
    cout << ans << '\n';
    vector<int> ids;
    while(lst != -1) ids.push_back(a[lst].id), lst = prev[lst];
    cout << sz(ids) << '\n';
    reverse(all(ids));
    for(int x : ids) cout << x + 1 << ' ';
}