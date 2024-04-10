#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod = (int)998244353;
const int mod2 = (int)1e9 + 7;
int n;
int a[maxn];
ll sum[maxn];


struct point{
    ll x, y;
};
struct seg{

    ll f(point a,  ll x) {
        return a.x * x + a.y;
    }
    point line[4 * maxn];
    int L[4 * maxn];
    int R[4 * maxn];
    int sz = 2;
    int getLeft(int v) {
        if(L[v] == 0) {
            L[v] = sz;
            line[sz] = {0, -(1ll<<60)};
            sz++;
        }

        return L[v];
    }
    int getRight(int v) {
        if(R[v] == 0) {
            R[v] = sz;
            line[sz] = {0, -(1ll<<60)};
            sz++;
        }
        return R[v];
    }
    void add_line(point nw, int v = 1, int l = -1e6-10, int r = 1e6+10) {
        int m = l + (r-l) / 2;
        bool lef = f(nw, l) > f(line[v], l);
        bool mid = f(nw, m) > f(line[v], m);
        if(mid) {
            swap(line[v], nw);
        }
        if(r - l == 1) {
            return;
        } else if(lef != mid) {
            add_line(nw, getLeft(v), l, m);
        } else {
            add_line(nw, getRight(v), m, r);
        }
    }
    ll get(int x, int v = 1, int l = -1e6-10, int r = 1e6+10) {
        int m = l + (r-l) / 2;
        if(r - l == 1) {
            return f(line[v], x);
        } else if(x < m) {
            return max(f(line[v], x), get(x, getLeft(v), l, m));
        } else {
            return max(f(line[v], x), get(x, getRight(v), m, r));
        }
    }
} A, B;

void solve() {
    cin >> n;

    ll cur = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cur += a[i] *1ll* i;
        sum[i] = sum[i-1] + a[i];
    }
    A.line[1] = {0, -(1ll<<60)};
    B.line[1] = {0, -(1ll<<60)};
    for(int i = 1; i <= n; i++) {
        A.add_line({i, -sum[i-1]});
        B.add_line({a[i], sum[i] - a[i] * 1ll*i});
        ans = max(ans, A.get(a[i]) + sum[i-1] - a[i] *1ll* i);
        ans = max(ans, B.get(i) - sum[i]);
        //cout << B.get(i) - sum[i] << "\n";
        //sum[i - 1] - sum[l-1] + a[i] * l - a[i] * i;
        //-sum[i] + sum[l] + a[l] * i - a[l] * l;
    }
    cout << cur + ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}