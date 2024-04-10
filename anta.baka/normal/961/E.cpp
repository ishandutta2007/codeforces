#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1 << 20, mod = 1e9 + 7;

int get(vector<int> &v, int x) {
    return v.end() - lower_bound(all(v), x);
}

int get(int l, int r, vector<vector<int>> &t, int x) {
    int ret = 0;
    for(l += (sz(t) >> 1), r += (sz(t) >> 1); l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if(l & 1) ret += get(t[l], x);
        if(!(r & 1)) ret += get(t[r], x);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> t(2 * n);
    for(int i = 0; i < n; i++) t[i + n].push_back(a[i]);
    for(int i = n - 1; i; i--) merge(all(t[i * 2]), all(t[i * 2 + 1]), back_inserter(t[i]));
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += get(i + 1, min(a[i] - 1, n - 1), t, i + 1);
    }
    cout << ans;
}