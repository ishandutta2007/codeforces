#include <bits/stdc++.h>

using namespace std;

struct Node{
    short lzy;
    int v, lft, rht;
};

int N, Q;
Node seg[15000000];
int nxt;

void pd(int nl, int nr, int idx){
    int mid = nl + nr >> 1;
    seg[seg[idx].lft].lzy = seg[seg[idx].rht].lzy = seg[idx].lzy;
    if(seg[idx].lzy == -1){
        seg[seg[idx].lft].v = seg[seg[idx].rht].v = 0;
    }
    else{
        seg[seg[idx].lft].v = mid - nl + 1;
        seg[seg[idx].rht].v = nr - mid;
    }
    seg[idx].lzy = 0;
}

void upd(int nl, int nr, int l, int r, int v, int idx){
    if(nl == l && nr == r){
        seg[idx].lzy = v;
        if(v == -1){
            seg[idx].v = 0;
        }
        else{
            seg[idx].v = nr - nl + 1;
        }
        return;
    }
    int mid = nl + nr >> 1;
    if(!seg[idx].lft){
        seg[idx].lft = ++nxt;
        seg[idx].rht = ++nxt;
    }
    if(seg[idx].lzy){
        pd(nl, nr, idx);
    }
    if(r <= mid){
        upd(nl, mid, l, r, v, seg[idx].lft);
    }
    else if(l > mid){
        upd(mid+1, nr, l, r, v, seg[idx].rht);
    }
    else{
        upd(nl, mid, l, mid, v, seg[idx].lft);
        upd(mid+1, nr, mid+1, r, v, seg[idx].rht);
    }
    seg[idx].v = seg[seg[idx].lft].v + seg[seg[idx].rht].v;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    nxt++;
    seg[1].lzy = 1;
    seg[1].v = N;
    for(int i = 1; i<=Q; i++){
        int l, r, v;
        cin >> l >> r >> v;
        if(v == 1){
            upd(1, N, l, r, -1, 1);
        }
        else{
            upd(1, N, l, r, 1, 1);
        }
        cout << seg[1].v << "\n";
    }
}