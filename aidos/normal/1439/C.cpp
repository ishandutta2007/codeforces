#include <bits/stdc++.h>

using namespace std;
const int maxn = (int)2e5 + 100;
int n, m;
int a[maxn];
long long sum[4 * maxn];
int tmin[4 * maxn];
int tmax[4 * maxn];
int u[4 * maxn];
void build(int v, int l, int r) {
    if(l == r) {
        sum[v] = a[l];
        tmin[v] = a[l];
        tmax[v] = a[l];
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v*2+1, mid+1, r);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
        tmin[v] = tmin[v * 2 + 1];
        tmax[v] = tmax[v * 2];
    }
}
void push(int v, int l, int r) {
    if(u[v] == 0 || l == r) return;
    tmin[v * 2] = u[v];
    tmax[v * 2] = u[v];
    tmin[v * 2+1] = u[v];
    tmax[v * 2+1] = u[v];
    u[v * 2] = u[v];
    u[v * 2 + 1] = u[v];
    long long mid = (l + r)/2;
    sum[v * 2] = (mid - l + 1) * u[v];
    sum[v * 2+1] = (r-mid) * u[v];
    u[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, long long x) {
    if(tl > r || l > tr) return;
    if(tmin[v] >= x) {
        return;
    }
    push(v, tl, tr);
    if(l <= tl && tr <= r) {
        if(tmax[v] <= x) {
            u[v] = x;
            tmax[v] = x;
            tmin[v] = x;
            sum[v] = x * (tr - tl + 1);
            return;
        }
    }
    int mid = (tl + tr)/2;
    upd(v * 2, tl, mid, l, r, x);
    upd(v * 2 + 1, mid + 1, tr, l, r, x);
    tmin[v] = tmin[v * 2+1];
    tmax[v] = tmax[v * 2];
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
}
long long get(int v, int tl, int tr, int l, int r, long long &x) {
    if(tl > r || l > tr) {
        return 0;
    }
    if(tmin[v] > x) return 0;
    if(l <= tl && tr <= r) {
        if(sum[v] <= x) {
            x -= sum[v];
            return tr - tl + 1;
        }
    }
    push(v, tl, tr);
    int mid = (tl + tr)/2;
    return get(v * 2, tl, mid, l, r, x) + get(v * 2 + 1, mid + 1, tr, l, r, x);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for(int i = 0; i < m; i++) {
        int t, x;
        long long y;
        cin >> t >> x >> y;
        if(t == 1) {
            upd(1, 1, n, 1, x, y);
        } else {
            cout << get(1, 1, n, x, n, y) << "\n";
        }
    }
}