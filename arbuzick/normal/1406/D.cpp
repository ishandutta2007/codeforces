#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int R = 1 << 17;
int t[R*2], fl[R*2];
void push(int node) {
    if (fl[node] != 0) {
        fl[node*2] += fl[node];
        fl[node*2+1] += fl[node];
    }
    fl[node] = 0;
}
void add(int ql, int qr, int x, int node = 1, int nl = 0, int nr = R) {
    if (ql <= nl && nr <= qr) {
        fl[node] += x;
        return;
    }
    if (qr <= nl || nr <= ql)
        return;
    push(node);
    int nm = (nl+nr)/2;
    add(ql, qr, x, node*2, nl, nm);
    add(ql, qr, x, node*2+1, nm, nr);
}
int get(int pos, int node = 1, int nl = 0, int nr = R) {
    if (nl > pos || nr <= pos)
        return 0;
    if (nl == nr-1)
        return t[node]+fl[node];
    push(node);
    int nm = (nl+nr)/2;
    return get(pos, node*2, nl, nm)+get(pos, node*2+1, nm, nr);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i+R];
    int q;
    cin >> q;
    int k = 0;
    for (int i = 1; i < n; ++i)
        k += max(0LL, t[i+R]-t[i+R-1]);
    cout << max((t[R]+k)/2, t[R]-(t[R]+k)/2+k) << '\n';
    while (q--) {
        int l, r2, x;
        cin >> l >> r2 >> x;
        l--;
        if (l > 0) {
            k -= max(0LL, get(l)-get(l-1));
        }
        if (r2 < n) {
            k -= max(0LL, get(r2)-get(r2-1));
        }
        add(l, r2, x);
        if (l > 0) {
            k += max(0LL, get(l)-get(l-1));
        }
        if (r2 < n) {
            k += max(0LL, get(r2)-get(r2-1));
        }
        cout << max((get(0)+k)/2, get(0)-(get(0)+k)/2+k) << '\n';
    }
    return 0;
}