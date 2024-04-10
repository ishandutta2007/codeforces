
#include<iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = (int)1e6 + 100;
int sz[maxn];
int mx[maxn];
int g[maxn][3];
int S[maxn];
int del[maxn];
int ord[maxn];
tuple < int, int, int> centr[maxn * 11];
int SZ;
int prv[maxn * 11];
int start[maxn];
int k;
int n;
int ans[maxn];
int L;
void dfs(int v, int p) {
    sz[v] = 1;
    mx[v] = 0;
    ord[L++] = v;
    for(int i = 0; i < S[v]; i++) {
        int to = g[v][i];
        if(del[to]) continue;
        if(to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        mx[v] = max(sz[to], mx[v]);
    }
}
int dist[maxn];
int ord2[maxn];
void dfs2(int v, int p, int len) {
    ord2[L++] = v;
    dist[v] = len;
    for(int i = 0; i < S[v]; i++) {
        int to = g[v][i];
        if(to == p) continue;
        if(del[to]) continue;
        dfs2(to, v, len + 1);
    }
}
void add_centr(int v, tuple<int, int, int> x) {
    int cur = start[v];

    start[v] = SZ;
    centr[SZ] = x;
    prv[SZ++] = cur;
}
void rec(int v) {

    L = 0;
    dfs(v, -1);
    if(L < 2000) return;
    int centroid = v;
    for(int i = 0; i < L; i++) {
        int to = ord[i];
        if(max(L - sz[to], mx[to]) <
           max(L - sz[centroid], mx[centroid])) {
            centroid = to;
        }
    }
    add_centr(centroid, make_tuple(centroid, 0, 0));
    int ind = 1;
    for(int i = 0; i < S[centroid]; i++) {
        int to = g[centroid][i];
        if(del[to]) continue;
        L = 0;
        dfs2(to, centroid, 1);
        for(int j = 0; j < L; j++) {
            int x = ord2[j];
            add_centr(x, make_tuple(centroid, dist[x], ind));
        }
        ind++;
    }
    del[centroid] = 1;
    for(int i = 0; i < S[centroid]; i++) {
        int to = g[centroid][i];
        if(!del[to]) rec(to);
    }

}
pair<int, int> mx1[maxn];
pair<int, int> mx2[maxn];
inline void upd(int centroid, int dist, int ind) {
    if(mx1[centroid].second == ind) {
        mx1[centroid].first = max(mx1[centroid].first, dist);
    } else if(mx1[centroid].first <= dist){
        mx2[centroid] = mx1[centroid];
        mx1[centroid] = make_pair(dist, ind);
    } else {
        mx2[centroid] = max(mx2[centroid], make_pair(dist, ind));
    }
}
inline int get(int centroid, int dist, int ind) {
    if(mx1[centroid].second == ind) {
        return mx2[centroid].first;
    }
    return mx1[centroid].first;
}

void calc() {
    for(int i = 1; i <= n; i++) {
        mx1[i] = make_pair(-1e9, -1);
        mx2[i] = make_pair(-1e9, -1);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = start[i]; j >= 0; j = prv[j]) {
            int centroid = get<0>(centr[j]);
            int dist = get<1>(centr[j]);
            int ind = get<2>(centr[j]);
            ans[i] = max(ans[i], get(centroid, dist, ind) + dist);
        }
        for(int j = start[i]; j >= 0; j = prv[j]) {
            int centroid = get<0>(centr[j]);
            int dist = get<1>(centr[j]);
            int ind = get<2>(centr[j]);
            upd(centroid, dist, ind);
        }
    }
}

int get_max_dist(int v, int p, int len) {
    int ans = len;
    for(int i = 0; i < S[v];i++) {
        int to = g[v][i];
        if(to == p) continue;
        ans = max(ans, get_max_dist(to, v, len+1));
    }
    return ans;
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int q;
    cin >> q;
    n = 1;
    for(int i = 2; i <= 4; i++){
        n++;
        g[1][S[1]++] = n;
        g[n][S[n]++] = 1;
    }
    vector<int> a;
    int f = 0;
    ans[4] = 2;
    for(int i = 0; i < q; i++) {
        int v;
        cin >> v;
        n++;
        g[v][S[v]++] = n;
        g[n][S[n]++] = v;
        n++;
        a.push_back(n);
        g[v][S[v]++] = n;
        g[n][S[n]++] = v;
        if(!f) {
            ans[n] = get_max_dist(n, -1, 0);
            if(n > 2000) f = 1;
        }
    }
    for(int i = 1; i <= n; i++) start[i] = -1;
    rec(1);

    calc();
    for(int i = 2; i <= n; i++) {
        ans[i] = max(ans[i], ans[i-1]);
    }
    for(int i = 0; i < q; i++) {
        cout << ans[a[i]] << "\n";
    }
}