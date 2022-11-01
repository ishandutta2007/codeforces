#pragma gcc optimize("OFast")
#pragma gcc target("sse,sse2,sse3,sse4,tune=native")
//#pragma gcc optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;
const ll llINF = 1e18;

struct segTree {
    int n; vector<int> t;
    segTree(int n) : n(n), t(2 * n, 0) {}
    void upd(int l, int r) {
        for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if(l & 1) t[l]++;
            if(!(r & 1)) t[r]++;
        }
    }
    int get(int pos) {
        int ret = 0;
        for(pos += n; pos; pos >>= 1) ret += t[pos];
        return ret;
    }
};

struct segTree1 {
    int n; vector<int> t;
    segTree1(int n) : n(n), t(2 * n, 0) {}
    void upd(int v, int x) {
        t[v += n] = x;
        for(v >>= 1; v; v >>= 1) t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    int get(int l, int r) {
        int ret = 0;
        for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if(l & 1) ret = max(ret, t[l]);
            if(!(r & 1)) ret = max(ret, t[r]);
        }
        return ret;
    }
};

int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    segTree t(m);
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r; l--; r--;
        t.upd(l, r);
    }
    vector<int> a(m);
    for(int i = 0; i < m; i++) a[i] = t.get(i);

    segTree1 t1(n + 1);
    vector<int> dp1(m);
    for(int i = 0; i < m; i++) {
        //if(a[i] == 0) continue;
        int x = 1 + t1.get(0, a[i]);
        t1.upd(a[i], x);
        dp1[i] = x;
    }
    reverse(all(a));
    segTree1 t2(n + 1);
    vector<int> dp2(m);
    for(int i = 0; i < m; i++) {
        //if(a[i] == 0) continue;
        int x = 1 + t2.get(0, a[i]);
        t2.upd(a[i], x);
        dp2[i] = x;
    }
    reverse(all(dp2));
    int ans = 0;
    for(int i = 0; i < m; i++) ans = max(ans, dp1[i] + dp2[i] - 1);
    cout << ans;

}