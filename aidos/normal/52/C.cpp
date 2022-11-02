#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 2e5 + 100;

int n;
long long a[maxn];
long long u[4 * maxn];
long long t[4 * maxn];
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = a[l];
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
void push(int v, int l, int r) {
    if(l == r) return;
    u[v*2] += u[v];
    u[v * 2 + 1] += u[v];
    t[v * 2] += u[v];
    t[v * 2 + 1] += u[v];
    u[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int z) {
    push(v, tl, tr);
    if(tl > r || l > tr) return;
    if(l <= tl && tr <= r) {
        t[v] += z;
        u[v] += z;
    } else {
        int mid = (tl + tr)/2;
        upd(v * 2, tl, mid, l, r, z);
        upd(v * 2 + 1, mid + 1, tr, l, r, z);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}
long long get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(tl > r || l > tr) return (long long)(1e18);
    if(l <= tl && tr <= r) {
        return t[v];
    } else {
        int mid = (tl + tr)/2;
        return min(get(v * 2, tl, mid, l, r), get(v * 2 + 1, mid + 1, tr, l, r));
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n-1);
    int q;
    cin >> q;
    cin.ignore();
    for(int i = 0; i < q; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x, y, z;
        ss >> x >> y;
        if(ss >> z) {
            if(x <= y) {
                upd(1, 0, n-1, x, y, z);
            } else {
                upd(1, 0, n-1, x, n-1, z);
                upd(1, 0, n-1, 0, y, z);
            }
        } else {
            if(x <= y) {
                cout << get(1, 0, n-1, x, y) << "\n";
            } else {
                cout << min(get(1, 0, n-1, x, n-1), get(1, 0, n-1, 0, y)) << "\n";
            }
        }

    }
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}