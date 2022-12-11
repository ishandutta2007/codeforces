#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    long long mn, mx, val;
};

int N, Q;
long long pre[200005];
long long h[200005];
Node seg[1000000];

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    if(l == r){
        seg[idx].mn = pre[l]-h[l];
        seg[idx].mx = pre[l]+h[l];
        seg[idx].val = h[l];
        return ;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
    seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
    seg[idx].val = max(seg[2*idx].val, seg[2*idx+1].val);
    seg[idx].val = max(seg[idx].val, seg[2*idx+1].mx - seg[2*idx].mn);
}

pair<pair<long long, long long>, long long> query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return {{seg[idx].mn, seg[idx].mx}, seg[idx].val};
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        auto p = query(l, mid, 2*idx), q = query(mid+1, r, 2*idx+1);
        p.second = max(p.second, q.second);
        p.second = max(p.second, q.first.second - p.first.first);
        p.first.first = min(p.first.first, q.first.first);
        p.first.second = max(p.first.second, q.first.second);
        return p;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> pre[i+1];
        pre[N+i+1] = pre[i+1];
    }
    for(int i = 1; i<=N; i++){
        cin >> h[i];
        h[i] *= 2;
        h[N+i] = h[i];
    }
    for(int i = 1; i<=2*N; i++){
        pre[i] += pre[i-1];
    }
    build(1, 2*N, 1);
    while(Q--){
        int l, r;
        cin >> r >> l;
        if(r <= l){
            r+=N;
            r--;
            l++;
        }
        else{
            r += N;
            l += N;
            r--;
            l++;
        }
        cout << query(l, r, 1).second << "\n";
    }
}