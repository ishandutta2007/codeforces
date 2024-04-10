#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, v, lzys, lzyx;
};

int N, Q;
int arr[100005];
Node seg[1000000];

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    seg[idx].lzys = -1;
    if(l == r){
        seg[idx].v = (l >= 0);
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void pd(int idx){
    if(seg[idx].lzys != -1){
        seg[2*idx].lzys = seg[2*idx+1].lzys = seg[idx].lzys;
        seg[2*idx].lzyx = seg[2*idx+1].lzyx = 0;
        seg[2*idx].v = seg[2*idx+1].v = seg[idx].lzys;
    }
    seg[2*idx].lzyx ^= seg[idx].lzyx;
    seg[2*idx+1].lzyx ^= seg[idx].lzyx;
    seg[2*idx].v ^= seg[idx].lzyx;
    seg[2*idx+1].v ^= seg[idx].lzyx;
    seg[idx].lzyx = 0;
    seg[idx].lzys = -1;
}

void upds(int l, int r, int v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].v = seg[idx].lzys = v;
        seg[idx].lzyx = 0;
        return;
    }
    pd(idx);
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        upds(l, r, v, 2*idx);
    }
    else if(l > mid){
        upds(l, r, v, 2*idx+1);
    }
    else{
        upds(l, mid, v, 2*idx);
        upds(mid+1, r, v, 2*idx+1);
    }
}

void updx(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].v ^= 1;
        seg[idx].lzyx ^= 1;
        return;
    }
    pd(idx);
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        updx(l, r, 2*idx);
    }
    else if(l > mid){
        updx(l, r, 2*idx+1);
    }
    else{
        updx(l, mid, 2*idx);
        updx(mid+1, r, 2*idx+1);
    }
}

int query(int p, int idx){
    if(seg[idx].l == seg[idx].r){
        return seg[idx].v;
    }
    pd(idx);
    int mid = seg[idx].l + seg[idx].r >> 1;
    return query(p, 2*idx+(p>mid));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    build(-100001, 100001, 1);
    while(Q--){
        char c;
        int n;
        cin >> c >> n;
        if(!n){
            if(c == '<'){
                upds(-100001, 100001, 1, 1);
            }
            else{
                upds(-100001, 100001, 0, 1);
            }
        }
        else if(n > 0){
            if(c == '<'){
                updx(-n+1, n-1, 1);
                upds(-100001, -n, 1, 1);
                upds(n, 100001, 1, 1);
            }
            else{
                upds(-100001, -n-1, 0, 1);
                upds(n+1, 100001, 0, 1);
            }
        }
        else{
            n = abs(n);
            if(c == '<'){
                upds(-100001, -n-1, 1, 1);
                upds(n+1, 100001, 1, 1);
            }
            else{
                updx(-n+1, n-1, 1);
                upds(-100001, -n, 0, 1);
                upds(n, 100001, 0, 1);
            }
        }
    }
    for(int i = 1; i<=N; i++){
        cout << (2*query(arr[i], 1)-1)*abs(arr[i]) << " ";
    }
}