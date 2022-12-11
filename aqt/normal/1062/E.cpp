#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, v, mn, mx;
};

int N, Q;
Node seg[500000];
int tbl[17][100005];
int dep[500000];
vector<int> graph[100005];
int t, lft[100005], rht[100005];

void dfs(int n){
    lft[n] = ++t;
    for(int e : graph[n]){
        dep[e] = dep[n] + 1;
        dfs(e);
    }
    rht[n] = ++t;
}

int lca(int x, int y){
    if(dep[x] < dep[y]){
        swap(x, y);
    }
    for(int d = 16; d>=0; d--){
        if(dep[tbl[d][x]] >= dep[y]){
            x = tbl[d][x];
        }
    }
    if(x == y){
        return x;
    }
    for(int d = 16; d>=0; d--){
        if(tbl[d][x] != tbl[d][y]){
            x = tbl[d][x], y = tbl[d][y];
        }
    }
    return tbl[0][x];
}

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    if(l == r){
        seg[idx].v = l;
        seg[idx].mn = seg[idx].mx = l;
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    seg[idx].v = lca(seg[2*idx].v, seg[2*idx+1].v);
    if(lft[seg[2*idx].mn] < lft[seg[2*idx+1].mn]){
        seg[idx].mn = seg[2*idx].mn;
    }
    else{
        seg[idx].mn = seg[2*idx+1].mn;
    }
    if(rht[seg[2*idx].mx] > rht[seg[2*idx+1].mx]){
        seg[idx].mx = seg[2*idx].mx;
    }
    else{
        seg[idx].mx = seg[2*idx+1].mx;
    }
}

int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].v;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else {
        return lca(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
    }
}

pair<int, int> extrema(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return {seg[idx].mn, seg[idx].mx};
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return extrema(l, r, 2*idx);
    }
    else if(l > mid){
        return extrema(l, r, 2*idx+1);
    }
    else{
        auto p = extrema(l, mid, 2*idx), q = extrema(mid+1, r, 2*idx+1);
        if(lft[p.first] > lft[q.first]){
            p.first = q.first;
        }
        if(rht[p.second] < rht[q.second]){
            p.second = q.second;
        }
        return p;
    }
}

int solve(int l, int r, int v){
    if(v == l){
        return dep[query(l+1, r, 1)];
    }
    else if(v == r){
        return dep[query(l, r-1, 1)];
    }
    else{
        return dep[lca(query(l, v-1, 1), query(v+1, r, 1))];
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 2; i<=N; i++){
        cin >> tbl[0][i];
        graph[tbl[0][i]].push_back(i);
    }
    dfs(1);
    for(int d = 1; d<17; d++){
        for(int n = 1; n<=N; n++){
            tbl[d][n] = tbl[d-1][tbl[d-1][n]];
        }
    }
    build(1, N, 1);
    while(Q--){
        int l, r;
        cin >> l >> r;
        auto p = extrema(l, r, 1);
        if(solve(l, r, p.first) > solve(l, r, p.second)){
            cout << p.first << " " << solve(l, r, p.first) << "\n";
        }
        else{
            cout << p.second << " " << solve(l, r, p.second) << "\n";
        }
    }
}