#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e4 + 10;
const int mod = (int) 1e9 + 7;
int n, m, q;
int p[maxn];
int L[maxn][555];
int R[maxn][555];
int a[maxn], b[maxn];
int get(int v) {
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}
void uni(int u, int v) {
    u = get(u);
    v = get(v);
    if(u != v) p[u] = v;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin>>a[i] >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            L[i][j] = get(j);
        }
        uni(a[i], b[i]);
    }
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for(int i = m; i > 0; i--) {
        for(int j = 1; j <= n; j++) {
            R[i][j] = get(j);
        }
        uni(a[i], b[i]);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        for(int j = 1; j <= n; j++) p[j] = L[l][j];
        for(int j = 1; j <= n; j++) {
            uni(j, R[r][j]);
        }
        int ans = 0;
        for(int j = 1; j <= n; j++) if(get(j) == j) ans++;
        cout << ans << "\n";
    }
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}