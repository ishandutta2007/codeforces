#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n;
pii t[4 * maxn];
int a[maxn];
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = make_pair(a[l], l);
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = min(t[v*2], t[v*2 + 1]);
    }
}
pii get(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return make_pair(inf, -1);
    if(l <= tl && tr <= r) {
        return t[v];
    }
    int mid = (tl + tr)/2;
    return min(get(v * 2, tl, mid, l, r), get(v*2 + 1, mid + 1, tr, l, r));
}
int ans[maxn];
map< pii, ll > dp;
ll calc(int l, int r) {
    if(l > r) return 0;
    if(l == r) {
        return a[l];
    }
    if(dp.count(make_pair(l, r))) return dp[make_pair(l, r)];
    int mi = get(1, 0, n-1, l, r).second;
    ll res=max(calc(l, mi-1) + (r-mi+1) * 1ll * a[mi], calc(mi+1, r) + (mi - l + 1)  *1ll * a[mi]);
    return dp[make_pair(l, r)] = res;
}
void rec(int l, int r) {
    if(l > r) return;
    if(l == r) {
        ans[l] = a[l];
        return;
    }
    int mi = get(1, 0, n-1, l, r).second;
    if(calc(l, r) == calc(l, mi-1) + (r-mi+1) * 1ll * a[mi]) {
        rec(l, mi-1);
        for(int i = mi; i <= r; i++) ans[i] = a[mi];
        return;
    }
    for(int i = l; i <= mi; i++) ans[i] = a[mi];
    rec(mi+1, r);
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n-1);
    rec(0, n-1);
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}