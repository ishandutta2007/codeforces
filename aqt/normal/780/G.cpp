#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, mx, lw;
};

int H, N, M;
Node seg[300005];
long long MOD = 1e9+7;
stack<pair<int, int>> stk[100005];
vector<pair<pair<int, int>, pair<int, int>>> qu;

long long add(long long a, long long b){
    return (a+b)%MOD;
}

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    seg[idx].mx = 1;
    seg[idx].lw = H+1;
    if(l == r){
        stk[l].push({H+1, 1});
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void upd(int p, int v, int h, int idx){
    if(seg[idx].l == seg[idx].r){
        stk[seg[idx].l].push({h, v});
        seg[idx].mx = stk[seg[idx].l].size();
        seg[idx].lw = h;
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(p <= mid){
        upd(p, v, h, 2*idx);
    }
    else{
        upd(p, v, h, 2*idx+1);
    }
    seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
    seg[idx].lw = h;
}

int query(int l, int r, int t, int idx){
    if(seg[idx].mx == 0 || seg[idx].lw > t){
        return 0;
    }
    if(seg[idx].l == seg[idx].r){
        int n = 0;
        while(stk[seg[idx].l].size() && stk[seg[idx].l].top().first <= t){
            n = add(n ,stk[seg[idx].l].top().second);
            stk[seg[idx].l].pop();
        }
        seg[idx].mx = stk[seg[idx].l].size();
        if(stk[seg[idx].l].size()){
            seg[idx].lw = stk[seg[idx].l].top().first;
        }
        else{
            seg[idx].lw = INT_MAX;
        }
        return n;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    int ret = 0;
    if(r <= mid){
        ret = query(l, r, t, 2*idx);
    }
    else if(l > mid){
        ret = query(l, r, t, 2*idx+1);
    }
    else{
        ret = add(query(l, mid, t, 2*idx), query(mid+1, r, t, 2*idx+1));
    }
    seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
    seg[idx].lw = min(seg[2*idx].lw, seg[2*idx+1].lw);
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> N >> M;
    build(1, N, 1);
    for(int i = 1; i<=M; i++){
        int h, l, r, t;
        cin >> h >> l >> r >> t;
        t += h;
        qu.push_back({{h, t}, {l, r}});
    }
    sort(qu.begin(), qu.end(), greater<pair<pair<int, int>, pair<int, int>>>());
    for(auto p : qu){
        int s = query(p.second.first, p.second.second, p.first.second, 1);
        if(!s){
            continue;
        }
        if(p.second.first == 1){
            upd(p.second.second+1, 2*s%MOD, p.first.first, 1);
        }
        else if(p.second.second == N){
            upd(p.second.first-1, 2*s%MOD, p.first.first, 1);
        }
        else{
            upd(p.second.second+1, s, p.first.first, 1);
            upd(p.second.first-1, s, p.first.first, 1);
        }
    }
    cout << query(1, N, H+1, 1) << endl;
}