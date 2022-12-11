#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, v;
};

int T, N;
Node seg[2000000];
vector<int> a;
vector<int> pos[300005];
int idx[300005];
string ans = "YES";

void build(int l, int r, int idx){
    seg[idx].l =l, seg[idx].r = r;
    if(l ==r){
        seg[idx].v = a[l-1];
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);
}

int query(int l, int r, int idx){
    //cout << l << " " << r << " " << seg[idx].l << " " << seg[idx].r << endl;
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].v;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(mid >= r){
        return query(l, r, 2*idx);
    }
    else if(mid < l){
        return query(l, r, 2*idx+1);
    }
    else{
        return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
    }
}

void upd(int p, int v, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].v = v;
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(p <= mid){
        upd(p, v, 2*idx);
    }
    else{
        upd(p, v, 2*idx+1);
    }
    seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        ans = "YES";
        for(int i = 1; i<=N; i++){
            int n;
            cin >> n;
            a.push_back(n);
            pos[a[i-1]].push_back(i);
        }
        //cout << "here" << endl;
        build(1, N, 1);
        for(int i = 1; i<=N; i++){
            int n;
            cin >> n;
            //cout << "idx: " << i << endl;
            if(idx[n] >= pos[n].size()){
                ans = "NO";
                continue;
            }
            if(query(1, pos[n][idx[n]], 1) < n){
                ans = "NO";
            }
            upd(pos[n][idx[n]], INT_MAX, 1);
            idx[n]++;
        }
        cout << ans << "\n";
        fill(idx+1, idx+1+N, 0);
        a.clear();
        for(int i =1 ; i<=N; i++){
            pos[i].clear();
        }
    }
}