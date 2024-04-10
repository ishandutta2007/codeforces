#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
pii t[maxn * 4];
int a[maxn];
ll sum[maxn * 4];
int n, m;
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = make_pair(a[l], l);
        sum[v] = a[l];
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = max(t[v * 2], t[v*2 + 1]);
        sum[v] = sum[v*2] + sum[v*2+1];
    }
}
pii get(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return make_pair(0, -1);
    if(l <= tl && tr <= r) {
        return t[v];
    }
    int mid = (tl + tr)/2;
    return max(get(v*2, tl, mid, l, r), get(v*2+1, mid+1, tr, l, r));
}
void upd(int v, int l, int r, int pos, int val) {
    if(l == r) {
        t[v].first = val;
        sum[v] = val;
    } else {
        int mid = (l + r)/2;
        if(pos <= mid) {
            upd(v*2, l, mid, pos, val);
        } else {
            upd(v*2+1, mid+1, r, pos, val);
        }
        t[v] = max(t[v*2], t[v*2+1]);
        sum[v] = sum[v*2] + sum[v*2+1];
    }
}
ll get_sum(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return 0ll;
    if(l <= tl && tr <= r) {
        return sum[v];
    }
    int mid = (tl + tr)/2;
    return get_sum(v*2, tl, mid, l, r)+get_sum(v*2+1, mid+1, tr, l, r);
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r;
            cin >> l >> r;
            cout << get_sum(1, 1, n, l, r) << "\n";
        } else if(type == 2){
            int l, r, x;
            cin >> l >> r >> x;
            pii g = get(1, 1, n, l, r);
            while(g.first >= x) {
                upd(1, 1, n, g.second, g.first % x);
                g =  get(1, 1, n, l, r);
            }
        } else {
            int k, x;
            cin >> k >> x;
            upd(1, 1, n, k, x);
        }
    }
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