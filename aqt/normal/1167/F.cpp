#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    long long v, lzy;
};

int N;
long long MOD = 1e9+7;
vector<pair<long long, long long>> v;
Node seg[2000005];

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void pd(int idx){
    seg[2*idx].v += (1LL*seg[2*idx].r - seg[2*idx].l + 1)*seg[idx].lzy;
    seg[2*idx].v %= MOD;
    seg[2*idx+1].v += (1LL*seg[2*idx+1].r - seg[2*idx+1].l + 1)*seg[idx].lzy;
    seg[2*idx+1].v %= MOD;
    seg[2*idx].lzy += seg[idx].lzy;
    seg[2*idx+1].lzy += seg[idx].lzy;
    seg[idx].lzy = 0;
}

void upd(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].lzy++;
        seg[idx].v += (seg[idx].r - seg[idx].l + 1);
        seg[idx].v %= MOD;
        return;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
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
    seg[idx].v = seg[2*idx].v + seg[2*idx+1].v;
    seg[idx].v %= MOD;
}

long long query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].v;
    }
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        return (query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1))%MOD;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        v.push_back({n, i});
    }
    sort(v.begin(), v.end());
    build(0, N, 1);
    long long ans = 0;
    for(auto p : v){
        long long idx = p.second;
        upd(idx, N, 1);
        ans += p.first*((idx*query(idx, N, 1) - (N-idx+1)*query(0, idx-1, 1))%MOD);
        ans %= MOD;
        if(ans < 0){
            ans += MOD;
        }
    }
    cout << ans << endl;
}