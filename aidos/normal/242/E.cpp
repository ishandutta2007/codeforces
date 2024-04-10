
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e5 + 10;
int n, m, k;
struct seg{
    int t[maxn * 4];
    int u[maxn * 4];
    void push(int v, int l, int r) {
        if(l == r || u[v] == 0) return;
        int mid = (l + r)/2;
        u[v*2] ^= 1;
        u[v*2+1] ^= 1;
        t[v * 2] = (mid+1 - l) - t[v*2];
        t[v * 2 + 1] = (r - mid) - t[v*2+1];
        u[v] = 0;
    }
    int get(int v, int tl, int tr,int l, int r) {
        push(v, tl, tr);
        if(tl > r || l > tr) return 0;
        if(l <= tl && tr <= r) return t[v];
        int mid = (tl + tr)/2;
        return get(v * 2, tl, mid, l, r) + get(v * 2 + 1, mid+1, tr, l, r);
    }
    void upd(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if(tl > r || l > tr) return;
        if(l <= tl && tr <= r) {
            u[v] ^= 1;
            t[v] = (tr - tl + 1) - t[v];
            return;
        }
        int mid = (tl + tr)/2;
        upd(v * 2, tl, mid, l, r);
        upd(v * 2 + 1, mid+1, tr, l, r);
        t[v] = t[v*2]+t[v*2+1];
    }
} T[20];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < 20; j++) {
            if(x&(1<<j))T[j].upd(1, 1, n, i, i);
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            ll ans = 0;
            for(int j = 0; j < 20; j++) {
                ll cur = T[j].get(1, 1, n, l, r);
                ans += cur << j;
            }
            cout << ans << "\n";
        } else {
            int x;
            cin >> x;
            for(int j = 0; j < 20; j++) {
                if(x&(1<<j))T[j].upd(1, 1, n, l, r);
            }
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}