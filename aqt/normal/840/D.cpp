#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, sum, lft, rht;
};

int N, Q;
Node seg[20000000];
int arr[300005];
int rt[300005];
int id;
pair<int, pair<int, int>> temp;

inline int build(int l, int r){
    ++id;
    int crnt = id;
    seg[id].l = l, seg[id].r = r;
    if(l == r){
        return crnt;
    }
    int mid = l + r >> 1;
    seg[crnt].lft = build(l, mid);
    seg[crnt].rht = build(mid+1, r);
    return crnt;
}

inline int upd(int p, int idx){
    id++;
    seg[id].l = seg[idx].l, seg[id].r = seg[idx].r;
    seg[id].sum = seg[idx].sum;
    seg[id].lft = seg[idx].lft, seg[id].rht = seg[idx].rht;
    idx = id;
    if(seg[idx].l == seg[idx].r){
        seg[idx].sum++;
        return idx;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(p <= mid){
        seg[idx].lft = upd(p, seg[idx].lft);
    }
    else{
        seg[idx].rht = upd(p, seg[idx].rht);
    }
    seg[idx].sum = seg[seg[idx].lft].sum + seg[seg[idx].rht].sum;
    return idx;
}

inline void query(int t, int lidx, int ridx){
    if(seg[lidx].l == seg[lidx].r){
        temp.first = seg[lidx].l;
        temp.second.first = seg[ridx].sum - seg[lidx].sum;
        temp.second.second = t;
        return;
    }
    int s = seg[seg[ridx].lft].sum - seg[seg[lidx].lft].sum;
    if(s <= t){
        query(t-s, seg[lidx].rht, seg[ridx].rht);
    }
    else{
        query(t, seg[lidx].lft, seg[ridx].lft);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    rt[0] = build(0, N+1);
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        rt[i] = upd(arr[i], rt[i-1]);
    }
    while(Q--){
        int lft, rht, k;
        cin >> lft >> rht >> k;
        int tot = 0;
        int t = (rht-lft+1)/k;
        k--;
        int out = INT_MAX;
        while(k--){
            query(tot+t, rt[lft-1], rt[rht]);
            if(temp.second.first > t){
                out = temp.first;
                break;
            }
            tot = tot + t - temp.second.second + temp.second.first;
        }
        if(out > N){
            cout << -1 << "\n";
        }
        else{
            cout << out << "\n";
        }
    }
}