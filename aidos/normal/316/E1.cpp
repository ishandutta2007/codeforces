#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;

int n, k;
int q;
int a[maxn];
struct matrix {
    int a[2][2];
    matrix operator * (matrix o) {
        matrix b;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                b.a[i][j] = 0;
                for(int k = 0; k < 2; k++) {
                    b.a[i][j] = (b.a[i][j] + a[i][k] * 1ll * o.a[k][j]) % mod;
                }
            }
        }
        return b;
    }
    matrix operator + (matrix o) {
        matrix b;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                b.a[i][j] = (a[i][j] + o.a[i][j]) % mod;
            }
        }
        return b;
    }

    matrix operator * (ll val) {
        matrix b;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                b.a[i][j] = a[i][j] * val % mod;
            }
        }
        return b;
    }
};
matrix one;
matrix fib[maxn];
matrix sum[maxn];
matrix t[4*maxn];
ll A[4*maxn];
void push(int v, int l, int r) {
    if(l == r || A[v] == 0) {
        return;
    }
    A[v*2] =(A[v*2] + A[v]) % mod;
    A[v*2+1] =(A[v*2+1] + A[v]) % mod;
    int mid = (l + r)/2;
    t[v*2] = t[v*2] + sum[mid-l] * A[v];
    t[v*2+1] = t[v*2+1] + sum[r-mid-1] * A[v];
    A[v] = 0;
}
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = one * a[l];
    } else {
        int mid = (l + r) >> 1;
        build(v * 2, l, mid);
        build(v*2+1, mid+1, r);
        int len = mid - l + 1;
        t[v] = t[v*2] + t[v*2+1] * fib[len];
    }
}
matrix get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(l <= tl && tr <= r) return t[v];
    int mid = (tl + tr)/2;
    if(r <= mid) return get(v*2, tl, mid, l, r);
    if(mid < l) return get(v*2+1, mid+1, tr, l, r);
    int len = mid - max(tl, l) + 1;
    return (get(v*2, tl, mid, l, r) + get(v*2+1, mid+1, tr, l, r) * fib[len]);
}
void upd(int v, int l, int r, int pos, ll val) {
    push(v, l, r);
    if(l == r) {
        t[v] = one * val;
    } else {
        int mid = (l + r)/2;
        if(pos <= mid) upd(v * 2, l, mid, pos, val);
        else upd(v*2+1, mid+1, r, pos, val);
        int len = mid - l + 1;
        t[v] = (t[v*2] + t[v*2+1] * fib[len]);
    }
}
void add(int v, int tl, int tr, int l, int r, ll val) {
    push(v, tl, tr);
    if(tl > r || l > tr) return;
    if(l <= tl && tr <= r) {
        t[v] = (t[v] + sum[tr - tl] * val);
        A[v] = (A[v] + val) % mod;
        return;
    }
    int mid = (tl + tr)/2;
    add(v * 2, tl, mid, l, r, val);
    add(v*2+1, mid+1, tr, l, r, val);
    int len = mid - tl + 1;
    t[v] = (t[v*2] + t[v*2+1] * fib[len]);
}
void solve() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            one.a[i][j] = i==j;
        }
    }
    matrix cur;
    cur.a[0][0] = 0;
    cur.a[0][1] = 1;
    cur.a[1][0] = 1;
    cur.a[1][1] = 1;
    fib[0] = one;
    sum[0] = one;

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        fib[i] = fib[i-1] * cur;
        sum[i] = sum[i-1] + fib[i];
    }
    build(1, 1, n);
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int pos, v;
            cin >> pos >> v;
            upd(1, 1, n, pos, v);
        } else if(t == 2) {
            int l, r;
            cin >> l >> r;
            matrix d = get(1, 1, n, l, r);
            cout << (d.a[0][0] + d.a[0][1]) % mod << "\n";
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            add(1, 1, n, l, r, d);
        }

    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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