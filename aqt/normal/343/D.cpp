#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, sum, lzy;
};

Node seg[8000005];

void pd(int idx){
    seg[2*idx].sum = seg[2*idx].r - seg[2*idx].l + 1;
    seg[2*idx+1].sum = seg[2*idx+1].r - seg[2*idx+1].l + 1;
    seg[2*idx].lzy = seg[2*idx+1].lzy = 1;
    seg[idx].lzy = 0;
}

void build(int l, int r, int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    build(l ,mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void upd(int p, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].sum = 0;
        seg[idx].lzy = 0;
        return;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(p <= mid){
        upd(p, 2*idx);
    }
    else{
        upd(p, 2*idx+1);
    }
    seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

void rng(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].sum = seg[idx].r - seg[idx].l + 1;
        seg[idx].lzy = 1;
        return;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        rng(l ,r , 2*idx);
    }
    else if(l > mid){
        rng(l, r, 2*idx+1);
    }
    else {
        rng(l, mid, 2*idx);
        rng(mid+1, r, 2*idx+1);
    }
    seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].sum;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l ,r ,2 *idx+1);
    }
    else{
        return query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1);
    }
}

int lft[1000005], rht[1000005], cnt = 0;
vector<int> graph[500005];
int par[1000005];
int N, Q;

void dfs(int n, int p){
    par[n] = p;
    lft[n] = ++cnt;
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
        }
    }
    rht[n] = ++cnt;
}

int main(){
    cin >> N;
    for(int i= 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    build(0, 2*N, 1);
    cin >> Q;
    while(Q--){
        int c, n;
        cin >> c >> n;
        if(c == 1){
            if(query(lft[n],rht[n], 1) != rht[n] - lft[n] + 1){
                upd(lft[par[n]], 1);
                upd(rht[par[n]], 1);
            }
            rng(lft[n], rht[n], 1);
        }
        else if(c == 2){
            upd(lft[n], 1);
            upd(rht[n], 1);
        }
        else{
            if(query(lft[n], rht[n], 1) == rht[n] - lft[n] + 1){
                cout << 1 << "\n";
            }
            else{
                cout << 0 <<"\n";
            }
        }
    }

}