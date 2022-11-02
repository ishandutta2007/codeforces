#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
typedef long long ll;
typedef long long ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}

ftype f(point a,  ftype x) {
    return dot(a, {x, 1});
}

point line[33 * maxn];
int L[33*maxn];
int R[33*maxn];
int sz;
int ok;
int create(int l, int r) {
    int v = ++sz;
    line[v] = {0, (long long)1e18};
    return v;
}
void add_line(point nw, int v = 1, int l = -maxn, int r = maxn) {
    int m = l+(r-l) / 2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if(mid) {
        swap(line[v], nw);
    }
    if(r - l == 1) {
        return;
    } else if(lef != mid) {
        if(L[v] == 0) L[v] = create(l, r);
        add_line(nw, L[v], l, m);
    } else {
        if(R[v] == 0) R[v] = create(l, r);
        add_line(nw, R[v], m, r);
    }
}
ftype get(int x, int v, int l = -maxn, int r = maxn) {
    int m = l+(r-l) / 2;
    if(v == 0) return 1e18;
    if(r - l == 1) {
        return f(line[v], x);
    } else if(x < m) {
        return min(f(line[v], x), get(x, L[v], l, m));
    } else {
        return min(f(line[v], x), get(x, R[v], m, r));
    }
}
int tin[maxn];
int tout[maxn];
vector<int> ord;
vector<int> g[maxn];
int a[maxn];
int b[maxn];
int timer;
void dfs(int v, int pa) {
    tin[v] = ++timer;

    for(int to: g[v]) {
        if(to != pa) {
            dfs(to, v);
        }
    }
    ord.push_back(v);
    tout[v] = timer;
}
int n;
int t[4 * maxn];
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = create(-maxn, maxn);
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = create(-maxn, maxn);
    }
}
ftype get2(int v, int tl, int tr, int l, int r, int x) {
    if(tl > r || l > tr) return 1e18;
    if(l <= tl && tr <= r) {
        return get(x, t[v]);
    }
    int mid = (tl + tr)/2;
    return min(get2(v * 2, tl, mid, l, r, x), get2(v * 2 + 1, mid + 1, tr, l, r, x));
}
void upd(int v, int l, int r, int pos, point nw) {
    if(l == r) {
        add_line(nw,t[v]);
    } else {
        int mid = (l + r)/2;
        if(pos <= mid) {
            upd(v * 2, l, mid, pos, nw);
        } else {
            upd(v * 2 + 1, mid+1, r, pos, nw);
        }
        add_line(nw, t[v]);
    }
}
long long dp[maxn];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    build(1, 1, n);
    for(int v: ord) {
        ok = (v == 1);
        if(tin[v] == tout[v]) {
            dp[v] = 0;
        } else {
            dp[v] = get2(1, 1, n, tin[v], tout[v], a[v]);
        }
        //cout << v << " " << tin[v] << " " << tout[v] << " " << dp[v] << " " << b[v]<< "\n";
        upd(1, 1, n, tin[v], {b[v], dp[v]});
    }
    //cout << "\n";
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
}