#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 2e5 + 10;
const int mod = (int) 1e9 + 7;
int n, m;
int a[maxn];
int b[maxn];
int t[4*maxn];
void push(int v, int l, int r) {
    if(l == r || t[v] == 0) return;
    int mid = (l + r)/2;
    t[v * 2] = t[v];
    t[v * 2 + 1] = t[v] + mid - l + 1;
    t[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int &val) {
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r) {
        t[v] = val;
        val += tr - tl + 1;
        return;
    }
    push(v, tl, tr);
    int mid = (tl + tr) / 2;
    upd(v * 2, tl, mid, l, r, val);
    upd(v * 2 + 1, mid + 1, tr, l, r, val);
}
int get(int v, int l, int r, int pos) {
    if(l == r) {
        if(t[v] == 0) return b[l];
        return a[t[v]];
    }
    push(v, l, r);
    int mid = (l + r)/2;
    if(pos <= mid) return get(v * 2, l, mid, pos);
    return get(v * 2 + 1, mid + 1, r, pos);
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if(type==1) {
            int x, y, k;
            cin >> x >> y >> k;
            upd(1, 1, n, y, y + k - 1, x);
        } else {
            int x;
            cin >> x;
            cout << get(1, 1, n, x) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}