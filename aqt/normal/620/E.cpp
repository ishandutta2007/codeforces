#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    long long msk, lzy;
};

int N, Q;
Node seg[4000000];
long long clr[500000];
vector<int> graph[500000];
int ET[1000000], lft[500000], rht[500000], t = 0;

void dfs(int n, int p){
    ET[++t] = n;
    lft[n] = t;
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
        }
    }
    ET[++t] = n;
    rht[n] = t;
}

inline void build(int l, int r, int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    if(l == r){
        seg[idx].msk = clr[ET[l]];
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    seg[idx].msk = seg[2*idx].msk | seg[2*idx+1].msk;
}

inline void pd(int idx){
    seg[2*idx+1].msk = seg[2*idx].msk = seg[2*idx+1].lzy = seg[2*idx].lzy = seg[idx].lzy;
    seg[idx].lzy = 0;
}

inline void upd(int l, int r, long long v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].msk = seg[idx].lzy = v;
        return;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        upd(l, r, v, 2*idx);
    }
    else if(l > mid){
        upd(l, r, v, 2*idx+1);
    }
    else{
        upd(l, mid, v, 2*idx);
        upd(mid+1, r, v, 2*idx+1);
    }
    seg[idx].msk = seg[2*idx].msk | seg[2*idx+1].msk;
}

long long query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].msk;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else {
        return query(l, mid, 2*idx) | query(mid+1, r, 2*idx+1);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i =1 ; i<=N; i++){
        cin >> clr[i];
        clr[i] = (1LL << clr[i]);
    }
    for(int i =1 ; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    build(1, 2*N, 1);
    while(Q--){
        int c;
        cin >> c;
        if(c == 2){
            int n;
            cin >> n;
            cout << __builtin_popcountll(query(lft[n], rht[n], 1)) << "\n";
        }
        else{
            int n, v;
            cin >> n >> v;
            upd(lft[n], rht[n], 1LL << v, 1);
        }
    }
}