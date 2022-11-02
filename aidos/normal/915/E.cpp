#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n, m;
int sz = 1;
int L[maxn * 30];
int R[maxn * 30];
int t[maxn * 30];
int U[maxn * 30];
void push(int v, int l, int r) {
    if(L[v] == 0) {
        L[v] = ++sz;
    }
    if(R[v] == 0) {
        R[v] = ++sz;
    }
    if(U[v] == 0) return;
    U[R[v]] = U[v];
    U[L[v]] = U[v];

    if(U[v] == 2) {
        int mid = (l + r)/2;
        t[L[v]] = mid - l + 1;
        t[R[v]] = r - mid;
    }  else {
        t[L[v]] = 0;
        t[R[v]] = 0;
    }
    U[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val) {
    if(l > tr || tl > r) return;
    if(l <= tl && tr <= r) {
        U[v] = val;
        if(val == 2) t[v] = tr - tl + 1;
        else t[v] = 0;
        return;
    }
    int mid = (tl + tr)/2;
    push(v, tl, tr);
    upd(L[v], tl, mid, l, r, val);
    upd(R[v], mid+1, tr, l, r, val);
    t[v] = t[L[v]] + t[R[v]];
}
void solve() {
    cin >> n >> m;
    upd(1, 1, n, 1, n, 2);
    for(int i = 0; i < m; i++) {
        int x, l, r;
        cin >> l >> r >> x;
        upd(1, 1, n, l, r, x);
        cout << t[1] << "\n";
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