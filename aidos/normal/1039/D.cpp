#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
int n, m;
vector<int> g[maxn];
vector<int> gr[maxn];
vector<int> ord;
void dfs(int v, int p = -1) {
    for(int to: g[v]) {
        if(to != p) {
            gr[v].push_back(to);
            dfs(to, v);
        }
    }
    ord.push_back(v);
}
int ans[maxn];
int d[maxn];
int calc(int L) {
    int cnt = 0;
    for(int v: ord) {
        int mx1 = 0, mx2 = 0;
        for(int to: gr[v]) {
            if(d[to] > mx1) {
                mx2 = mx1;
                mx1 = d[to];
            } else if(mx2 < d[to]) {
                mx2 = d[to];
            }
        }
        if(mx1 + mx2 + 1 >= L) {
            d[v] = 0;
            cnt++;
        } else {
            d[v] = mx1 + 1;
        }
    }
    return cnt;
}
void rec(int l, int r, int L, int R) {
    if(l > r) return;
    if(L == R) return;
    int mid = (l + r)/2;
    ans[mid] = calc(mid);
    rec(l, mid-1, L, ans[mid]);
    rec(mid+1, r, ans[mid], R);
}
void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    ans[1] = n;
    rec(2, n, n, 0);
    for(int i = n; i>=1; i--) ans[i] = max(ans[i], ans[i+1]);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
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