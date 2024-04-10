#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)2e6 + 100;
int n;
int L[maxn], R[maxn], x[maxn];
bool u[maxn];
int ans;
multiset<int> S;
void dfs(int v, int l, int r) {
    if(v == -1) return;
    if(l <= x[v] && x[v] <= r) {
        S.insert(x[v]);
    }
    dfs(L[v], l, min(r, x[v] - 1));
    dfs(R[v], max(l, x[v] + 1), r);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> L[i] >> R[i];
        if(L[i] > 0) u[L[i]] = 1;
        if(R[i] > 0) u[R[i]] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(!u[i]) {
            dfs(i, -1, 2e9);
            break;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(S.find(x[i]) == S.end()) ans++;
    }
    cout << ans << "\n";
}
int main(){
    //freopen("in", "r", stdin);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}