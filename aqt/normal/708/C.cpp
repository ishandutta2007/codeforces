#include <bits/stdc++.h>

using namespace std;

struct node{
    int l, r;
    int val;
};

int N;
node seg[2000005];
vector<int> graph[400005];
int sz[400005], par[400005];
int ans[400005];
int BIT[400005];
int who[400005];

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    seg[idx].val = 0;
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void upd(int p, int v, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].val += v;
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(p <= mid){
        upd(p, v, 2*idx);
    }
    else{
        upd(p, v, 2*idx+1);
    }
    seg[idx].val = seg[2*idx].val + seg[2*idx+1].val;
}

int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].val;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        return query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1);
    }
}

void dfs1(int n){
    sz[n] = 1;
    for(int e : graph[n]){
        if(e != par[n]){
            par[e] = n;
            dfs1(e);
            sz[n] += sz[e];
        }
    }
}

void dfs2(int n){
    int lim = max(0, N - sz[n] - N/2);
    ans[n] = query(lim, N/2, 1);
    upd(sz[n], 1, 1);
    for(int e : graph[n]){
        if(e != par[n]){
            dfs2(e);
        }
    }
    ans[n] = query(lim, N/2, 1) - ans[n];
}

void dfs3(int n){
    int lim = max(0, N - sz[n] - N/2);
    ans[n] -= query(lim, N/2, 1);
    upd(sz[n], 1, 1);
    for(int e : graph[n]){
        if(e != par[n]){
            if(who[n]){
                who[e] = who[n];
            }
            dfs3(e);
        }
    }
    upd(sz[n], -1, 1);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1);
    int rt = 1;
    while(true){
        int hvy = 0;
        for(int e : graph[rt]){
            if(e != par[rt]){
                hvy = (sz[hvy] > sz[e] ? hvy : e);
            }
        }
        if(2*sz[hvy] <= N){
            break;
        }
        else{
            rt = hvy;
        }
    }
    par[rt] = 0;
    build(0, N, 1);
    dfs1(rt);
    dfs2(rt);
    for(int n = 1; n<=N; n++){
        if(n == rt){
            ans[n] = 1;
        }
        else{
            assert(ans[n] >= 0);
            int lim = N - sz[n] - N/2;
            ans[n] = query(lim, N/2, 1) - ans[n];
        }
    }
    build(0, N, 1);
    for(int e : graph[rt]){
        who[e] = e;
    }
    dfs3(rt);
    for(int n = 1; n<=N; n++){
        if(n == rt){
            ans[n] = 1;
        }
        else{
            int lim = N - sz[n] - N/2;
            ans[n] += (lim <= (N-sz[who[n]]) && (N-sz[who[n]]) <= N/2);
            assert(ans[n] >= 0);
            ans[n] = !!ans[n];
        }
        cout << ans[n] << " ";
    }
}