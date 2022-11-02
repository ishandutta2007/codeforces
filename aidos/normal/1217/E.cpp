#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
int t[maxn][10][2];
int a[maxn];
int sum[maxn];
void upd(int &x, int y) {
    if(y == -1) return;
    if(x == -1 || x > y) x = y;
}
void upd2(int &x, int y, int z) {
    if(y == -1) return;
    if(z == -1) return;
    upd(x, y + z);
}
void build(int v, int l, int r) {
    sum[v] = -1;
    if(l == r) {
        int x = a[l];
        for(int i = 0; i < 10; i++) {
            if(x % 10 == 0) {
                t[v][i][0] = a[l];
                t[v][i][1] = -1;
            } else {
                t[v][i][1] = a[l];
                t[v][i][0] = -1;
            }
            x/=10;
        }
        return;
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        upd(sum[v], sum[2*v]);
        upd(sum[v], sum[2*v + 1]);
        for(int i = 0; i < 10; i++) {
            upd2(sum[v], t[v*2][i][1], t[v*2 + 1][i][1]);
        }
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 2; j++) {
                t[v][i][j] = -1;
                upd(t[v][i][j], t[v*2][i][j]);
                upd(t[v][i][j], t[v*2+1][i][j]);
            }
        }
    }
}
int d[10][2];
int ans;
void get(int v, int tl, int tr, int l, int r) {
    if(tl > r||l > tr) return;
    if(l <= tl && tr <= r) {
        upd(ans, sum[v]);
        for(int i = 0; i < 10; i++) {
            upd2(ans, d[i][1], t[v][i][1]);
            for(int j = 0; j < 2; j++) {
                upd(d[i][j], t[v][i][j]);
            }
        }
        return;
    }
    int mid = (tl + tr)/2;
    get(v * 2, tl, mid, l, r);
    get(v*2 + 1, mid + 1, tr, l, r);
}
void change(int v, int l, int r, int pos, int val) {

    sum[v] = -1;
    if(l == r) {
        int x = val;
        for(int i = 0; i < 10; i++) {
            if(x % 10 == 0) {
                t[v][i][0] = val;
                t[v][i][1] = -1;
            } else {
                t[v][i][1] = val;
                t[v][i][0] = -1;
            }
            x/=10;
        }
    } else {
        int mid = (l + r)/2;
        if(pos <= mid) change(v * 2, l, mid, pos, val);
        else change(v * 2 + 1, mid + 1, r, pos, val);
        upd(sum[v], sum[2*v]);
        upd(sum[v], sum[2*v + 1]);
        for(int i = 0; i < 10; i++) {
            upd2(sum[v], t[v*2][i][1], t[v*2 + 1][i][1]);
        }
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 2; j++) {
                t[v][i][j] = -1;
                upd(t[v][i][j], t[v*2][i][j]);
                upd(t[v][i][j], t[v*2+1][i][j]);
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1,0, n-1);
    for(int i = 0; i < m; i++) {
        int type, l, r;

        cin >>type;
        if(type == 2) {
            cin >> l >> r;
            l--;
            r--;
            ans = -1;
            memset(d, -1, sizeof d);
            get(1, 0, n - 1, l, r);
            cout << ans << "\n";
        } else {
            cin >> l >> r;
            change(1, 0, n-1, l-1, r);
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
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