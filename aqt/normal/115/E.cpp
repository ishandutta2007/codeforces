#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    long long maxi, lzy, maxiwthpre;
};

struct Line{
    int l, r, v;
    bool operator < (Line L) const{
        return l < L.l;
    }
};

int N, M;
Node seg[800050];
long long pre[200005];
Line arr[200005];

void build(int l, int r, int idx){
    seg[idx].l  = l;
    seg[idx].r = r;
    seg[idx].maxi = seg[idx].maxiwthpre = LLONG_MIN>>2;
    if(l == r){
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void pd(int idx){
    seg[2*idx].maxi += seg[idx].lzy;
    seg[2*idx].maxiwthpre += seg[idx].lzy;
    seg[2*idx].lzy += seg[idx].lzy;
    seg[2*idx+1].maxi += seg[idx].lzy;
    seg[2*idx+1].maxiwthpre += seg[idx].lzy;
    seg[2*idx+1].lzy += seg[idx].lzy;
    seg[idx].lzy = 0;
}

void pu(int idx){
    seg[idx].maxi = max(seg[2*idx].maxi, seg[2*idx+1].maxi);
    seg[idx].maxiwthpre = max(seg[2*idx].maxiwthpre, seg[2*idx+1].maxiwthpre);
}

void add(int l, int r, long long v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].lzy += v;
        seg[idx].maxi += v;
        seg[idx].maxiwthpre += v;
        return;
    }
    int mid = (seg[idx].l + seg[idx].r)>>1;
    if(seg[idx].lzy){
        pd(idx);
    }
    if(r <= mid){
        add(l, r, v, 2*idx);
    }
    else if(l > mid){
        add(l, r, v, 2*idx+1);
    }
    else{
        add(l, mid, v, 2*idx);
        add(mid+1, r, v, 2*idx+1);
    }
    pu(idx);
}

void setval(int p, long long v, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].maxi = v;
        seg[idx].maxiwthpre = v + pre[p];
        return;
    }
    int mid = (seg[idx].l + seg[idx].r)>>1;
    if(seg[idx].lzy){
        pd(idx);
    }
    if(p <= mid){
        setval(p, v, 2*idx);
    }
    else{
        setval(p, v, 2*idx+1);
    }
    pu(idx);
}

long long query(int l, int r, int withpre, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return withpre ? seg[idx].maxiwthpre : seg[idx].maxi;
    }
    int mid = (seg[idx].l + seg[idx].r)>>1;
    if(seg[idx].lzy){
        pd(idx);
    }
    if(r <= mid){
        return query(l, r, withpre, 2*idx);
    }
    else if(l > mid){
        return query(l, r, withpre, 2*idx+1);
    }
    else{
        return max(query(l, mid, withpre, 2*idx), query(mid+1, r, withpre, 2*idx+1));
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    for(int i = 1; i<=M; i++){
        cin >> arr[i].l >> arr[i].r >> arr[i].v;
    }
    sort(arr+1, arr+1+M);
    build(0, 200000, 1);
    setval(0, 0, 1);
    for(int i = 1; i<=M; i++){
        add(arr[i].r, 200000, arr[i].v, 1);
        long long n = query(arr[i].r, arr[i].r, 0, 1);
        if(arr[i].l != arr[i].r){
            n = max(n, query(arr[i].l, arr[i].r-1, 1, 1) - pre[arr[i].r] + arr[i].v);
        }
        n = max(n, query(0, arr[i].l-1, 0, 1) - pre[arr[i].r] + pre[arr[i].l-1] + arr[i].v);
        setval(arr[i].r, n, 1);
    }
    cout << seg[1].maxi << endl;
}