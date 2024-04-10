#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, maxi;
    long long sum;
};

int N, M = 1000000, Q;
int num[1000005];
int arr[300005];
Node seg[2000000];

void pu(int idx){
    seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
    seg[idx].maxi = max(seg[2*idx].maxi, seg[2*idx+1].maxi);
}

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    if(l ==r){
        seg[idx].maxi = seg[idx].sum = arr[l];
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    pu(idx);
}

void upd(int l, int r, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].sum = seg[idx].maxi = num[seg[idx].sum];
        return;
    }
    if(seg[idx].maxi <= 2){
        return;
    }
    int mid = seg[idx].l + seg[idx].r>>1;
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
    pu(idx);
}

long long query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
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
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i= 1; i<=M; i++){
        for(int j= i; j<=M; j+=i){
            num[j]++;
        }
    }
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    build(1, N, 1);
    while(Q--){
        int c, l, r;
        cin >> c >> l >> r;
        if(c == 1){
            upd(l, r, 1);
        }
        else{
            cout << query(l, r, 1) << "\n";
        }
    }
}