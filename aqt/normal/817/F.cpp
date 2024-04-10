#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    long long sum;
    bool add, rem, flp;
};

int Q, N;
long long lft[100005], rht[100005], typ[100005];
Node seg[5000000];
vector<long long> cmp;

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
    for(int i = 2*idx; i<=2*idx+1; i++){
        if(seg[idx].add){
            seg[i].flp = seg[i].rem = 0;
            seg[i].add = 1;
            seg[i].sum = seg[i].r-seg[i].l+1;
        }
        if(seg[idx].rem){
            seg[i].flp = seg[i].add = 0;
            seg[i].rem = 1;
            seg[i].sum = 0;
        }
        if(seg[idx].flp){
            seg[i].flp ^= 1;
            seg[i].sum = seg[i].r-seg[i].l+1-seg[i].sum;
        }
    }
    seg[idx].add = seg[idx].rem = seg[idx].flp = 0;
}

void upd(int l, int r, int t, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        if(t == 1){
            seg[idx].flp = seg[idx].rem = 0;
            seg[idx].add = 1;
            seg[idx].sum = seg[idx].r-seg[idx].l+1;
        }
        else if(t == 2){
            seg[idx].flp = seg[idx].add = 0;
            seg[idx].rem = 1;
            seg[idx].sum = 0;
        }
        else{
            seg[idx].flp ^= 1;
            seg[idx].sum = seg[idx].r-seg[idx].l+1-seg[idx].sum;
        }
        return;
    }
    pd(idx);
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        upd(l, r, t, 2*idx);
    }
    else if(l > mid){
        upd(l, r, t, 2*idx+1);
    }
    else{
        upd(l, mid, t, 2*idx);
        upd(mid+1, r, t, 2*idx+1);
    }
    seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

int getidx(int idx){
    if(seg[idx].l == seg[idx].r){
        return seg[idx].l;
    }
    pd(idx);
    return ((seg[2*idx].r-seg[2*idx].l+1-seg[2*idx].sum) ? getidx(2*idx) : getidx(2*idx+1));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    cmp.push_back(1);
    for(int q = 1; q<=Q; q++){
        cin >> typ[q] >> lft[q] >> rht[q];
        cmp.push_back(lft[q]);
        cmp.push_back(rht[q]);
        cmp.push_back(rht[q]+1);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    N = cmp.size();
    build(1, N, 1);
    for(int q = 1; q<=Q; q++){
        lft[q] = lower_bound(cmp.begin(), cmp.end(), lft[q]) - cmp.begin() + 1;
        rht[q] = lower_bound(cmp.begin(), cmp.end(), rht[q]) - cmp.begin() + 1;
        upd(lft[q], rht[q], typ[q], 1);
        assert(seg[1].sum >= 0);
        cout << cmp[getidx(1)-1] << "\n";
    }
}