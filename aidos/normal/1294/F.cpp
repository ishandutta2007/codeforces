#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
int m;
vector<int> g[maxn];
pair<int, int> F[maxn];
pair<int, int> S[maxn];
pair<int, int> T[maxn];
int ans;
vector<int> d;
pair<int, int> dfs1(int v, int pa = -1) {
    F[v] = make_pair(0, v);
    S[v] = make_pair(-1e8, v);
    T[v] = make_pair(-1e8, v);
    for(int to: g[v]) {
        if(to == pa) {
        } else {
            pair<int, int> cur = dfs1(to, v);
            cur.first++;
            if(F[v] < cur) {
                T[v] = S[v];
                S[v] = F[v];
                F[v] = cur;
            } else if(S[v] < cur){
                T[v] = S[v];
                S[v] = cur;
            } else {
                T[v] = max(T[v], cur);
            }
        }
    }
    return F[v];
}
void dfs2(int v, int pa = -1, pair<int, int> mx = make_pair(-1e8, 0)) {
    if(mx.first + F[v].first + S[v].first > ans) {
        ans = mx.first + F[v].first + S[v].first;
        d = {mx.second, F[v].second, S[v].second};
    }
    if(F[v].first + S[v].first + T[v].first> ans) {
        ans = F[v].first + S[v].first + T[v].first;
        d = {F[v].second, S[v].second, T[v].second};
    }

    for(int to: g[v]) {
        if(to == pa) {
        } else {
            pair<int, int> D = mx;
            if(F[v].second == F[to].second) {
                D = max(D, S[v]);
            } else {
                D = max(D, F[v]);
            }
            D.first++;
            dfs2(to, v, D);
        }
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs1(1);
    ans = -1e9;
    dfs2(1);
    cout << ans << "\n";
    for(int i = 0; i < d.size(); i++) cout << d[i] << " ";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}