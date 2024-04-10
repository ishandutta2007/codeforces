#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
int n, m;
ll l, r;
tuple<int, int, int, int> ans[maxn];
int t[4*maxn];
void upd(int v, int tl, int tr, int pos, int val) {
    if(tl==tr) {
        t[v] = val;
    } else {
        int mid = (tl + tr)/2;
        if(pos <= mid) upd(v*2, tl, mid, pos, val);
        else upd(v * 2 + 1, mid+1, tr, pos, val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
int get(int v, int tl ,int tr, int l, int r) {
    if(tl > r || l > tr) return m+1;
    if(l <= tl && tr <= r) {
        return t[v];
    }
    int mid = (tl + tr)/2;
    return min(get(v * 2, tl, mid, l, r), get(v * 2 + 1, mid+1, tr, l, r));
}

void solve() {
    cin >> n >> m >> l >> r;
    for(int i = 1; i <= m; i++) {
        upd(1, 1, m, i, m + 1);
    }
    for(int i = m; i >= 1; i--) {

        for(int j = i; j <= n; j += i) {
            ll A = l/j;
            ll B = r/j;
            if(A * j < l) A++;
            if(B > m) B = m;
            if(A <= B) {
                ll cur = get(1, 1, m, A, B);
                if(cur <= m) {
                    ll x1 = j;
                    ll x2 = (x1 * cur)/i;
                    if(x2 <= n) {
                        ll y1 = (A+cur-1)/cur * cur;
                        ll y2 = x1 * y1 / x2;
                        ans[j] = {x1, y1, x2, y2};
                    }
                }
            }
        }
        for(int j = i; j <= m; j+=i) {
            upd(1, 1, m, j, i);
        }
    }
    for(int i = 1; i <= n; i++) {
        int a, b, c, d;
        tie(a, b, c, d) = ans[i];
        if(a == 0) {
            cout << -1 << "\n";
        } else {
            cout << a << " "<<b << " " << c << " " << d << "\n";
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