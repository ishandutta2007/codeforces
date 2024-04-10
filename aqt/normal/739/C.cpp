#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, pre, suf, maxi;
};

int N, Q;
long long diff[300005]; //a[i]-a[i-1]
Node seg[1500000];

void pu(int idx){
    bool valid = (!(diff[seg[2*idx].r] < 0 && diff[seg[2*idx+1].l] > 0)
                  && diff[seg[2*idx].r] && diff[seg[2*idx+1].l]);
    if(seg[2*idx].pre == seg[2*idx].r-seg[2*idx].l+1 && valid){
        seg[idx].pre = seg[2*idx].pre + seg[2*idx+1].pre;
    }
    else{
        seg[idx].pre = seg[2*idx].pre;
    }
    if(seg[2*idx+1].suf == seg[2*idx+1].r - seg[2*idx+1].l+1 && valid){
        seg[idx].suf = seg[2*idx+1].suf + seg[2*idx].suf;
    }
    else{
        seg[idx].suf = seg[2*idx+1].suf;
    }
    seg[idx].maxi = max(seg[2*idx].maxi, seg[2*idx+1].maxi);
    if(valid){
        seg[idx].maxi = max(seg[idx].maxi, seg[2*idx].suf + seg[2*idx+1].pre);
    }
}

void build(int l, int r, int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    if(l == r){
        if(diff[l]){
            seg[idx].pre = seg[idx].suf = seg[idx].maxi = 1;
        }
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    pu(idx);
}

void upd(int p, int idx){
    if(seg[idx].l == seg[idx].r){
        if(diff[seg[idx].l]){
            seg[idx].pre = seg[idx].suf = seg[idx].maxi = 1;
        }
        else{
            seg[idx].pre = seg[idx].suf = seg[idx].maxi = 0;
        }
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(p <= mid){
        upd(p, 2*idx);
    }
    else{
        upd(p, 2*idx+1);
    }
    pu(idx);
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int lst;
    cin >> lst;
    if(N== 1){
        cin >> Q;
        while(Q--){
            cout << 1 << "\n";
        }
        return 0;
    }
    for(int i = 2; i<=N; i++){
        int n;
        cin >> n;
        diff[i] = n-lst;
        lst = n;
    }
    build(2, N, 1);
    cin >> Q;
    while(Q--){
        int l, r, d;
        cin >> l>> r >> d;
        diff[l]+=d;
        diff[r+1]-=d;
        if(l != 1){
            upd(l, 1);
        }
        if(r != N){
            upd(r+1, 1);
        }
        cout << seg[1].maxi+1 << "\n";
    }
}