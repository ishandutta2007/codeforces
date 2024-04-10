#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int d[maxn];
int len[maxn];
vector < pair<int, int> > g[maxn];
int sz[maxn];
int mx[maxn];
int ans[maxn];
int cnt[1<<22];
int n;
void dfs(int v, int pa, int mask) {
    d[v] = mask;
    len[v] = len[pa] + 1;
    sz[v] = 1;
    for(auto to: g[v]) {
        if(to.first != pa) {
            dfs(to.first, v, mask ^ (1<<to.second));
            sz[v] += sz[to.first];
            if(sz[mx[v]] < sz[to.first]) {
                mx[v] = to.first;
            }
        }
    }
}
int calc2(int v, int pa) {
    int cur = 0;
    for(auto to: g[v]) {
        if(to.first != pa) {
            cur = max(cur, calc2(to.first, v));
        }
    }
    int mask = d[v];
    for(int i = 0; i < 22; i++) {
        if(cnt[mask^(1<<i)]) {
            cur = max(cur, cnt[mask^(1<<i)] + len[v]);
        }
    }
    if(cnt[mask]) {
        cur = max(cur, cnt[mask] + len[v]);
    }
    return cur;
}
void clr(int v, int pa, int x){
    if(x) {
        cnt[d[v]] = 0;
    } else{
        cnt[d[v]] = max(cnt[d[v]], len[v]);
    }
    for(auto to: g[v]) {
        if(to.first != pa) {
            clr(to.first, v, x);
        }
    }
}
void calc(int v, int pa, int cl) {
    for(auto to: g[v]) {
        if(to.first == pa || to.first == mx[v]) continue;
        calc(to.first, v, 1);
        ans[v] = max(ans[v], ans[to.first]);
    }
    if(mx[v] != 0) {
        calc(mx[v], v, 0);
        ans[v] = max(ans[v], ans[mx[v]]);
    }

    //add(d[v], len[v]);
    if(cnt[d[v]]) {
        ans[v] = max(ans[v], cnt[d[v]] - len[v]);
    }
    for(int i = 0; i < 22; i++) {
        if(cnt[d[v]^(1<<i)]) ans[v] = max(ans[v], cnt[d[v]^(1<<i)] - len[v]);
    }
    cnt[d[v]] = max(len[v], cnt[d[v]]);
    for(auto to: g[v]) {
        if(to.first == pa || to.first == mx[v]) continue;
        ans[v] = max(ans[v], calc2(to.first, v) - 2 * len[v]);
        clr(to.first, v, 0);
    }
    if(cl) {
        clr(v, pa, 1);
    }
}
int main(){
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int v;
        char c;
        cin >> v >> c;
        g[v].push_back({i, c - 'a'});
        g[i].push_back({v, c - 'a'});

    }
    dfs(1, 0, 0);
    calc(1, 0, 1);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}