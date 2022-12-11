#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l,r;
    long long maxi, sum;
};

int N, Q;
Node seg[400005];
int arr[400005];

void pu(int idx){
    seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
    seg[idx].maxi = max(seg[2*idx].maxi, seg[2*idx+1].maxi);
}

void build(int l, int r, int idx){
    seg[idx].l =l;
    seg[idx].r =r;
    if(l ==r){
        seg[idx].maxi = seg[idx].sum = arr[l];
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    pu(idx);
}

void upd(int p, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].sum = seg[idx].maxi = arr[p];
        return;
    }
    int mid = (seg[idx].l + seg[idx].r)>>1;
    if(p <= mid){
        upd(p, 2*idx);
    }
    else{
        upd(p, 2*idx+1);
    }
    pu(idx);
}

void rng(int l, int r, int x, int idx){
    if(seg[idx].maxi < x){
        return;
    }
    if(seg[idx].l == seg[idx].r){
        arr[l] %= x;
        seg[idx].sum = seg[idx].maxi = arr[l];
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        rng(l, r, x, 2*idx);
    }
    else if(l > mid){
        rng(l, r, x, 2*idx+1);
    }
    else{
        rng(l, mid, x, 2*idx);
        rng(mid+1, r, x, 2*idx+1);
    }
    pu(idx);
}

long long query(int l, int r, int idx){
    if(seg[idx].l ==l && seg[idx].r == r){
        return seg[idx].sum;
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

int main(){
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    build(1, N, 1);
    while(Q--){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int l, r;
            cin >> l >> r;
            printf("%lld\n", query(l, r, 1));
        }
        else if(cmd == 2){
            int l, r, x;
            cin >> l >> r >> x;
            rng(l, r, x, 1);
        }
        else{
            int k, x;
            cin >> k >> x;
            arr[k] = x;
            upd(k, 1);
        }
    }
}