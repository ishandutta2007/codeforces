#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;

int n;
long long a[maxn], b[maxn];
vector<int> ord;
int u[maxn];
vector<int> g[maxn];
void dfs1(int v) {
    u[v] = 1;
    if(b[v] != -1 && !u[b[v]]) {
        dfs1(b[v]);
    }
    ord.push_back(v);
}

long long sum[maxn];

void dfs2(int v) {
    u[v] = 1;
    for(int to: g[v]) {
        if(!u[to]) dfs2(to);
    }
    ord.push_back(v);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        if(!u[i])
            dfs1(i);
    }
    reverse(ord.begin(), ord.end());
    for(int v: ord) {
        if(b[v] == -1) {
            sum[v] += a[v];
        } else if(sum[v]+a[v] > 0) {
            sum[v] += a[v];
            sum[b[v]] += sum[v];
            g[v].push_back(b[v]);
        } else {
            sum[v] += a[v];
            g[b[v]].push_back(v);
        }
    }
    ord.clear();
    memset(u, 0, sizeof u);
    for(int i = 1; i <= n; i++) {
        if(!u[i]) {
            dfs2(i);
        }
    }
    reverse(ord.begin(), ord.end());
    //cout << accumulate(sum + 1, sum + n + 1, 0ll) << "\n";

    long long ans =  0;
    for(int to: ord) {
        ans += a[to];
        if(b[to] != -1) a[b[to]] += a[to];
    }
    cout << ans << "\n";
    for(int to: ord) {
        cout << to <<  " ";
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