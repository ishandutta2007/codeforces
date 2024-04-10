#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    long long msk, prod;
    long long lzyp, lzym;
};

long long MOD = 1e9+7;
Node seg[2000000];
int N, Q, M = 300;
long long fact[305], inv[305];
int arr[1000000];
int prime[305];
int cnt = 0;
vector<int> lst;

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(b, e>>1);
    ret = mult(ret, ret);
    if(e&1){
        ret = mult(ret, b);
    }
    return ret;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

void pu(int idx){
    seg[idx].msk = seg[2*idx].msk | seg[2*idx+1].msk;
    seg[idx].prod = mult(seg[2*idx].prod, seg[2*idx+1].prod);
}

void pd(int idx){
    int lft = idx<<1, rht = lft|1;
    seg[lft].prod = mult(seg[lft].prod,
                           qikpow(seg[idx].lzyp, seg[lft].r - seg[lft].l + 1));
    seg[rht].prod = mult(seg[rht].prod,
                             qikpow(seg[idx].lzyp, seg[rht].r - seg[rht].l + 1));
    seg[lft].msk |= seg[idx].lzym;
    seg[rht].msk |= seg[idx].lzym;
    seg[lft].lzyp = mult(seg[lft].lzyp, seg[idx].lzyp);
    seg[rht].lzyp = mult(seg[rht].lzyp, seg[idx].lzyp);
    seg[lft].lzym |= seg[idx].lzym, seg[rht].lzym |= seg[idx].lzym;
    seg[idx].lzym = 0;
    seg[idx].lzyp = 1;
}

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    seg[idx].lzyp = 1;
    if(l == r){
        seg[idx].msk = fact[arr[l]];
        seg[idx].prod = arr[l];
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    pu(idx);
}

void upd(int l, int r, int v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].prod = mult(seg[idx].prod, qikpow(v, r-l+1));
        seg[idx].lzyp = mult(seg[idx].lzyp, v);
        seg[idx].msk |= fact[v];
        seg[idx].lzym |= fact[v];
        return;
    }
    if(seg[idx].lzyp != 1 || seg[idx].lzym != 0){
        pd(idx);
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

pair<long long, long long> query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return {seg[idx].prod, seg[idx].msk};
    }
    if(seg[idx].lzyp != 1 || seg[idx].lzym != 0){
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
        auto p = query(l, mid, 2*idx), q = query(mid+1, r, 2*idx+1);
        return {mult(p.first, q.first), p.second | q.second};
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lst.push_back(1);
    for(int i = 2; i<=M; i++){
        if(!prime[i]){
            prime[i] = ++cnt;
            lst.push_back(i);
            inv[cnt] = divd(1, i);
            for(int j = 2*i; j<=M; j+=i){
                prime[j] = -1;
            }
        }
    }
    for(int i = 1; i<=M; i++){
        for(int j = 1; j<=i; j++){
            if(i%j == 0 && prime[j] != -1){
                fact[i] |= (1LL<<prime[j]);
            }
        }
    }
    cin >> N >> Q;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    build(1, N, 1);
    while(Q--){
        string s;
        int l, r;
        cin >> s >> l >> r;
        if(s == "MULTIPLY"){
            int v;
            cin >> v;
            upd(l, r, v, 1);
        }
        else{
            auto p = query(l, r, 1);
            //cout << p.second << "\n";
            for(int i = 1; i<=cnt; i++){
                if((p.second&(1LL<<i))){
                    //cout << lst[i] << endl;
                    p.first = mult(p.first, lst[i]-1);
                    p.first = mult(p.first, inv[i]);
                }
            }
            cout << p.first << "\n";
        }
    }
}