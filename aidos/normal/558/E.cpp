#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)400200;
const ll inf = (1ll<<50);
int n, m;
int c[maxn];
string s;
int cnt[27];
struct seg_tree{
    int t[maxn];
    int a[maxn];
    void build(int v, int l, int r) {
        a[v] = -1;
        if(l == r) {
            t[v] = 0;
        } else {
            int mid = (l + r)/2;
            build(v * 2, l, mid);
            build(v * 2 + 1, mid + 1, r);
            t[v] = t[v * 2] + t[v*2+1];
        }
    }
    void push(int v, int tl, int tr) {
        if(tl==tr) return;
        if(a[v] == -1) return;
        a[v * 2] = a[v * 2 + 1] = a[v];
        int mid = (tl + tr)/2;
        t[v*2] = a[v] * (mid  - tl + 1);
        t[v * 2 + 1] = a[v] * (tr - mid);
        a[v] = -1;
    }
    void upd(int v, int tl, int tr, int l, int r, int x) {
        if(tr < l || r < tl) return;
        push(v, tl, tr);
        if(l <= tl && tr <= r) {
            a[v] = x;
            t[v] = (tr - tl + 1) * x;
            return;
        }
        int mid = (tl + tr)/2;
        upd(v * 2, tl, mid, l, r, x);
        upd(v * 2 + 1, mid + 1, tr, l, r, x);
        t[v] = t[v*2] + t[v*2+1];
    }
    int get(int v, int tl, int tr, int l, int r) {
        if(tl > r || l > tr) return 0;
        push(v, tl, tr);
        if(l <= tl && tr <= r) return t[v];
        int mid = (tl + tr)/2;
        return get(v * 2, tl, mid, l, r) + get(v * 2 + 1, mid + 1, tr, l, r);
    }
} t[27];
void solve() {
    cin >> n >> m >> s;
    for (int i = 0; i < 26; i++) {
        t[i].build(1, 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        t[s[i] - 'a'].upd(1, 0, n - 1, i, i, 1);
    }


    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        for(int j = 0; j < 26; j++) {
            cnt[j] = t[j].get(1, 0, n-1, l, r);
            t[j].upd(1, 0, n-1, l, r, 0);
        }
        if(k > 0) {
            for(int j = 0; j < 26; j++) {
                if(cnt[j]) {
                    t[j].upd(1, 0, n-1, l, l + cnt[j] - 1, 1);
                    l += cnt[j];
                }
            }
        } else {
            for(int j = 0; j < 26; j++) {
                if(cnt[j]) {
                    t[j].upd(1, 0, n-1, r-cnt[j] + 1, r, 1);
                    r -= cnt[j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int j = 0;
        while(t[j].get(1, 0, n-1, i, i) == 0) j++;
        cout << char(j + 'a');
    }
    cout << "\n";
}
int main() {

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}