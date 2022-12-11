//i'm bad
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, maxi, lzy;
};

int N, M, Q;
Node seg[4000100];
int arr[1000005], drr[1000005];

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    if(l == r){
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void pd(int idx){
    seg[2*idx].maxi += seg[idx].lzy;
    seg[2*idx+1].maxi += seg[idx].lzy;
    seg[2*idx].lzy += seg[idx].lzy;
    seg[2*idx+1].lzy += seg[idx].lzy;
    seg[idx].lzy = 0;
}

void upd(int l, int r, int v, int idx){
    if(seg[idx].l == l && r == seg[idx].r){
        seg[idx].maxi += v;
        seg[idx].lzy += v;
        return;
    }
    pd(idx);
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        upd(l, r, v, 2*idx);
    }
    else if (l > mid){
        upd(l, r, v, 2*idx+1);
    }
    else{
        upd(l, mid, v, 2*idx);
        upd(mid+1, r, v, 2*idx+1);
    }
    seg[idx].maxi = max(seg[2*idx].maxi, seg[2*idx+1].maxi);
}

int query(int idx){
    if(seg[idx].l == seg[idx].r){
        return seg[idx].l;
    }
    pd(idx);
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(seg[2*idx+1].maxi > 0){
        return query(2*idx+1);
    }
    else{
        return query(2*idx);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    build(1, 1000000, 1);
    for(int i = 1; i<=M; i++){
        cin >> drr[i];
        upd(1, drr[i], 1, 1);
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        upd(1, arr[i], -1, 1);
    }
    //cout << "here" << "\n";
    cin >> Q;
    while(Q--){
        int c, n, v;
        cin >> c >> n >> v;
        if(c == 2){
            upd(1, arr[n], 1, 1);
            arr[n] = v;
            upd(1, arr[n], -1, 1);
        }
        else{
            upd(1, drr[n], -1, 1);
            drr[n] = v;
            upd(1, drr[n], 1, 1);
        }
        int k = -1;
        if(seg[1].maxi > 0){
            k = query(1);
        }
        cout << k << "\n";
    }
}

/*
1 1
1
1
1
1 1 100
*/