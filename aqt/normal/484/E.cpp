#include <bits/stdc++.h>

using namespace std;

struct Query{
    int id, l, r;
    bool operator < (Query q){
        return l+r > q.l+q.r;
    }
};

struct Update{
    int p, v;
    bool operator < (Update u){
        return v > u.v;
    }
};

struct Node{
    int l, r, pre, suf, maxi;
};

Node seg[400005];
int N, Q;
int lft[100005], rht[100005], wid[100005], ans[100005];
vector<Update> ud;
vector<Query> qu[40];

void build(int l, int r, int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    seg[idx].pre = seg[idx].suf = seg[idx].maxi = 0;
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void upd(int p, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].pre = seg[idx].suf = seg[idx].maxi = 1;
        return;
    }
    int mid = seg[idx].l+seg[idx].r>>1;
    if(p <= mid){
        upd(p, 2*idx);
    }
    else{
        upd(p, 2*idx+1);
    }
    if(seg[2*idx].r-seg[2*idx].l+1 == seg[2*idx].pre){
        seg[idx].pre = seg[2*idx].pre + seg[2*idx+1].pre;
    }
    else{
        seg[idx].pre = seg[2*idx].pre;
    }
    if(seg[2*idx+1].r-seg[2*idx+1].l+1 == seg[2*idx+1].suf){
        seg[idx].suf = seg[2*idx].suf + seg[2*idx+1].suf;
    }
    else{
        seg[idx].suf = seg[2*idx+1].suf;
    }
    seg[idx].maxi = max(seg[2*idx].maxi, seg[2*idx+1].maxi);
    seg[idx].maxi = max(seg[idx].maxi, seg[2*idx].suf+seg[2*idx+1].pre);
}

Node query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx];
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        Node n = query(l, mid, 2*idx), m = query(mid+1, r, 2*idx+1);
        Node r;
        if(n.r-n.l+1 == n.pre){
            r.pre = n.pre + m.pre;
        }
        else{
            r.pre = n.pre;
        }
        if(m.r-m.l+1 == m.suf){
            r.suf = n.suf + m.suf;
        }
        else{
            r.suf = m.suf;
        }
        r.maxi = max(n.maxi, m.maxi);
        r.maxi = max(r.maxi, n.suf+m.pre);
        return r;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        ud.push_back({i, n});
    }
    cin >> Q;
    for(int i = 1; i<=Q; i++){
        cin >> lft[i] >> rht[i] >> wid[i];
        qu[34].push_back({i, 1, 1000000000});
    }
    sort(ud.begin(), ud.end());
    int C = 34;
    do{
        sort(qu[C].begin(), qu[C].end());
        build(1, N, 1);
        int idx = 0;
        for(Query n : qu[C]){
            int mid = n.l+n.r>>1;
            while(idx < N && ud[idx].v >= mid){
                upd(ud[idx++].p, 1);
            }
            if(query(lft[n.id], rht[n.id], 1).maxi < wid[n.id]){
                n.r = mid-1;
            }
            else{
                ans[n.id] = mid;
                n.l = mid+1;
            }
            if(n.r >= n.l){
                qu[C-1].push_back(n);
            }
        }
    }
    while(C--);
    for(int i =1; i<=Q; i++){
        cout << ans[i] << "\n";
    }
}