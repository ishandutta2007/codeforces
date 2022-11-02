#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k, q;
int a[maxn], b[maxn];
int t[maxn * 4];
int mi;
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = a[l];
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}
int get_min(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return inf;
    if(l <= tl && tr <= r) return t[v];
    int mid = (tl + tr)/2;
    return min(get_min(v * 2, tl, mid, l, r), get_min(v * 2 + 1, mid + 1, tr, l, r));
}
int cur = 1;
int T[maxn * 30];
int L[maxn * 30];
int R[maxn * 30];
int U[maxn * 30];
void init(int &v, int l, int r) {
    v = ++cur;
    T[cur] = get_min(1, 0, 2 * n - 1, l % n, l % n + min(r-l+1, n) - 1);
}
void push(int v, int tl, int tr) {
    if(tl == tr) return;
    int mid = (tl + tr)/2;
    if(L[v] == 0) {
        init(L[v], tl, mid);
    }
    if(R[v] == 0) {
        init(R[v], mid + 1, tr);
    }
    if(U[v] == 0) return;
    U[L[v]] = U[v];
    T[L[v]] = U[v];
    U[R[v]] = U[v];
    T[R[v]] = U[v];
    U[v] = 0;
}
int get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(tl > r || l > tr) return inf;
    if(l <= tl && tr <= r) return T[v];
    int mid = (tl + tr)/2;
    if(L[v] == 0) {
        init(L[v], tl, mid);
    }
    if(R[v] == 0) {
        init(R[v], mid+1, tr);
    }
    return min(get(L[v], tl, mid, l, r), get(R[v], mid + 1, tr, l, r));
}
void upd(int v, int tl, int tr, int l, int r, int val) {
    push(v, tl, tr);
    if(tl > r || l > tr) return;
    if(l <= tl && tr <= r) {
        T[v] = val;
        U[v] = val;
        return;
    }
    int mid = (tl + tr)/2;
    if(L[v] == 0) {
        init(L[v], tl, mid);
    }
    if(R[v] == 0) {
        init(R[v], mid+1, tr);
    }
    upd(L[v], tl, mid, l, r, val);
    upd(R[v], mid + 1, tr, l, r, val);
    T[v] = min(T[L[v]], T[R[v]]);
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    build(1, 0, 2 * n - 1);
    cur = 0;
    init(T[1], 0, n * k - 1);

    cin >> q;
    for(int i = 0; i < q; i++) {
        int d;
        cin >> d;
        if(d == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            upd(1, 0, n*k - 1, l, r, x);
        } else{
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << get(1, 0, n * k - 1, l, r) << "\n";
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