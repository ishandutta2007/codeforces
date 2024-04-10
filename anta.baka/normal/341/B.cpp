#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;

struct segTree {
    int n; vector<int> t;
    segTree(int n) : n(n), t(2 * n, 0) {}
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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
    segTree t(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i++) {
        dp[i] = 1 + t.get(0, a[i]);
        t.upd(a[i], dp[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans;
}