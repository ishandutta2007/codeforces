#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, v, lzy;
};

Node seg[400005];
int lft[100005], rht[100005], val[100005];
int N, M;

void build(int l, int r, int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    if(l == r){
        return ;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void pd(int idx){
    seg[2*idx].v |= seg[idx].lzy;
    seg[2*idx+1].v |= seg[idx].lzy;
    seg[2*idx].lzy |= seg[idx].lzy;
    seg[2*idx+1].lzy |= seg[idx].lzy;
    seg[idx].lzy = 0;
}

void upd(int l, int r, int v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].v |= v;
        seg[idx].lzy |= v;
        return;
    }
    pd(idx);
    int mid = (seg[idx].l + seg[idx].r)>>1;
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
    seg[idx].v = seg[2*idx].v & seg[2*idx+1].v;
}

int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r ==r){
        return seg[idx].v;
    }
    pd(idx);
    int mid = (seg[idx].l + seg[idx].r)>>1;
    int ans = 0;
    if(r <= mid){
        ans = query(l, r, 2*idx);
    }
    else if(l > mid){
        ans = query(l, r, 2*idx+1);
    }
    else{
        ans = query(l, mid, 2*idx) & query(mid+1, r, 2*idx+1);
    }
    seg[idx].v = seg[2*idx].v & seg[2*idx+1].v;
    return ans;
}

void traverse(int idx){
    if(seg[idx].l == seg[idx].r){
        printf("%d ", seg[idx].v);
        return;
    }
    pd(idx);
    traverse(2*idx);
    traverse(2*idx+1);
}

void debug(int idx){
    printf("%d %d %d %d %d\n", seg[idx].l, seg[idx].r, seg[idx].v, seg[idx].lzy, idx);
    if(seg[idx].l == seg[idx].r){
        return;
    }
    debug(2*idx);
    debug(2*idx+1);
}

int main(){
    cin >> N >> M;
    build(1, N, 1);
    for(int i = 1; i<=M; i++){
        cin >> lft[i] >> rht[i] >> val[i];
        upd(lft[i], rht[i], val[i], 1);
    }
    bool works = 1;
    for(int i= 1; i<=M; i++){
        works &= val[i] == query(lft[i], rht[i], 1);
    }
    if(works){
        printf("YES\n");
        traverse(1);
        printf("\n");
    }
    else{
        cout << "NO" << endl;
    }
}