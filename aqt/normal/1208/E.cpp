#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, mx, id;
};

Node seg[4001005];
int N, W;
long long ans[1000005];
int arr[1000005];

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    seg[idx].mx = seg[idx].id = 0;
    if(l == r){
        seg[idx].mx = arr[l];
        seg[idx].id = l;
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx), build(mid+1, r, 2*idx+1);
    if(seg[2*idx].mx > seg[2*idx+1].mx){
        seg[idx].mx = seg[2*idx].mx;
        seg[idx].id = seg[2*idx].id;
    }
    else{
        seg[idx].mx = seg[2*idx+1].mx;
        seg[idx].id = seg[2*idx+1].id;
    }
}

pair<int, int> query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return {seg[idx].mx, seg[idx].id};
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        auto p = query(l, mid, 2*idx);
        auto q = query(mid+1, r, 2*idx+1);
        if(p.first > q.first){
            return p;
        }
        else{
            return q;
        }
    }
}

void rec(int l, int r, int vl, int vr, int rng){
    if(l > r || vl > vr){
        return;
    }
    int idx = query(l, r, 1).second;
    int lft = max(vl, idx), rht = min(vr+1, idx+rng);
    if(rht > lft){
        ans[lft] += arr[idx], ans[rht] -= arr[idx];
    }
    rec(l, idx-1, vl, lft-1, rng);
    rec(idx+1, r, rht, vr, rng);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> W;
    for(int i = 1; i<=N; i++){
        int s;
        cin >> s;
        for(int j = 1; j<=s; j++){
            cin >> arr[j];
        }
        arr[s+1] = 0;
        build(0, s+1, 1);
        rec(0, s+1, 1, W, W-s+1);
    }
    for(int i = 1; i<=W; i++){
        ans[i] += ans[i-1];
        cout << ans[i] << " ";
    }
}