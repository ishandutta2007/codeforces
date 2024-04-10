#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    int one, zero, lzy;
};

Node seg[1600005];
int N, Q;
vector<int> graph[200005];
int lft[200005], rht[200005];
int ET[400005], t = 0;
int init[200005];
string c;

void dfs(int n){
    t++;
    ET[t] = n;
    lft[n] = t;
    for(int e : graph[n]){
        dfs(e);
    }
    t++;
    ET[t] = n;
    rht[n] = t;
}

void pd(int idx){
    swap(seg[2*idx].one, seg[2*idx].zero);
    swap(seg[2*idx+1].one, seg[2*idx+1].zero);
    seg[2*idx].lzy ^= 1;
    seg[2*idx+1].lzy ^= 1;
    seg[idx].lzy = 0;
}

void build(int l, int r, int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    if(l == r){
        if(lft[ET[l]] == l){
            if(init[ET[l]]){
                seg[idx].one++;
            }
            else{
                seg[idx].zero++;
            }
        }
        return;
    }
    int mid = (l+r)>>1;
    build(l ,mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    seg[idx].one = seg[2*idx].one + seg[2*idx+1].one;
    seg[idx].zero = seg[2*idx].zero + seg[2*idx+1].zero;
}

int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].one;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = (seg[idx].l + seg[idx].r)>>1;
    if(r <= mid){
        return query(l ,r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        return query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1);
    }
}

void upd(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        swap(seg[idx].one, seg[idx].zero);
        seg[idx].lzy ^= 1;
        return ;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = (seg[idx].l + seg[idx].r)>>1;
    if(r <= mid){
        upd(l, r, 2*idx);
    }
    else if(l > mid){
        upd(l, r, 2*idx+1);
    }
    else{
        upd(l, mid, 2*idx);
        upd(mid+1, r, 2*idx+1);
    }
    seg[idx].one = seg[2*idx].one + seg[2*idx+1].one;
    seg[idx].zero = seg[2*idx].zero + seg[2*idx+1].zero;
}

int main(){
    cin >> N;
    for(int i= 2; i<=N; i++){
        int p;
        cin >> p;
        graph[p].push_back(i);
    }
    for(int i = 1; i<=N; i++){
        cin >> init[i];
    }
    dfs(1);
    build(1, 2*N, 1);
    scanf("%d", &Q);
    while(Q--){
        int n;
        cin >> c >> n;
        if(c == "get"){
            printf("%d\n", query(lft[n], rht[n], 1));
        }
        else{
            upd(lft[n], rht[n], 1);
        }
    }
}