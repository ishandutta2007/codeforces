#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    long long b, t, mx, lzy;
    bool haslzy;
};

int N, Q;
Node seg[400005];
long long pre[400005];
long long arr[400005];

void pu(int idx){
    seg[idx].b = seg[2*idx].b + seg[2*idx+1].b;
    seg[idx].t = seg[2*idx].t + seg[2*idx+1].t;
    seg[idx].mx = seg[2*idx+1].mx;
}

void pd(int idx){
    if(seg[idx].haslzy){
        seg[2*idx].b = seg[idx].lzy*(seg[2*idx].r-seg[2*idx].l+1);
        seg[2*idx].lzy = seg[idx].lzy;
        seg[2*idx].mx = seg[idx].lzy;
        seg[2*idx].haslzy = 1;
        seg[2*idx+1].b = seg[idx].lzy*(seg[2*idx+1].r-seg[2*idx+1].l+1);
        seg[2*idx+1].lzy = seg[idx].lzy;
        seg[2*idx+1].mx = seg[idx].lzy;
        seg[2*idx+1].haslzy = 1;
        seg[idx].haslzy = 0;
    }
}

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    if(l == r){
        seg[idx].b = arr[l] - pre[l];
        seg[idx].t = pre[l];
        seg[idx].mx = seg[idx].b;
        //cout << l << " " << seg[idx].b << " " << seg[idx].t << endl;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    pu(idx);
}

/*
void add(int p, long long v, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].b += v;
        seg[idx].mx = seg[idx].b;
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    pd(idx);
    if(p <= mid){
        add(p, v, 2*idx);
    }
    else{
        add(p, v, 2*idx+1);
    }
    pu(idx);
}
*/

void upd(int l, int r, long long v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].b = v*(seg[idx].r - seg[idx].l + 1);
        seg[idx].lzy = v;
        seg[idx].mx = v;
        seg[idx].haslzy = 1;
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        upd(l, r, v, 2*idx);
    }
    else if(l > mid){
        upd(l, r, v, 2*idx+1);
    }
    else{
        upd(l, mid, v, 2*idx);
        upd(mid+1, r, v, 2*idx+1);
    }
    pu(idx);
}

int getidx(long long v, int idx){
    if(seg[idx].l == seg[idx].r){
        return seg[idx].l;
    }
    pd(idx);
    if(seg[2*idx].mx >= v){
        return getidx(v, 2*idx);
    }
    else{
        return getidx(v, 2*idx+1);
    }
}

long long query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].b + seg[idx].t;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    pd(idx);
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
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    arr[N+1] = LLONG_MAX/2;
    for(int i = 2; i<=N; i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    build(1, N+1, 1);
    cin >> Q;
    int cnt = 0;
    while(Q--){
        char c;
        cin >> c;
        if(c == '+'){
            int p, x;
            cin >> p >> x;
            if(!x){
                continue;
            }
            long long s = query(p, p, 1) - pre[p] + x;
            int e = getidx(s, 1);
            //cout << e << "\n";
            upd(p, e-1, s, 1);
            //add(p, x, 1);
            //add(e, -x, 1);
        }
        else{
            int l, r;
            cin>> l >> r;
            cout << query(l, r, 1) << "\n";
        }
    }
}