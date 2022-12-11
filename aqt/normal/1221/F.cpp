#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, idx;
    long long mx, lzy;
};

int N, M;
Node seg[4000005];
int pos[600005], val[600005];
pair<int, int> arr[600005];
vector<int> cmp;

int getidx(int n){
    return lower_bound(cmp.begin(), cmp.end(), n) - cmp.begin() + 1;
}

void pd(int idx){
    if(seg[idx].lzy){
        seg[2*idx].mx += seg[idx].lzy;
        seg[2*idx+1].mx += seg[idx].lzy;
        seg[2*idx].lzy += seg[idx].lzy;
        seg[2*idx+1].lzy += seg[idx].lzy;
        seg[idx].lzy = 0;
    }
}

void pu(int idx){
    if(seg[2*idx].mx > seg[2*idx+1].mx){
        seg[idx].mx = seg[2*idx].mx;
        seg[idx].idx = seg[2*idx].idx;
    }
    else{
        seg[idx].mx = seg[2*idx+1].mx;
        seg[idx].idx = seg[2*idx+1].idx;
    }
}

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    if(l == r){
        seg[idx].mx = cmp[l-1];
        seg[idx].idx = cmp[l-1];
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    pu(idx);
}

void upd(int l, int r, int v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].mx += v;
        seg[idx].lzy += v;
        return;
    }
    int mid = seg[idx].l+seg[idx].r>>1;
    pd(idx);
    if(l > mid){
        upd(l, r, v, 2*idx+1);
    }
    else if(r <= mid){
        upd(l, r, v, 2*idx);
    }
    else{
        upd(l, mid, v, 2*idx);
        upd(mid+1, r, v, 2*idx+1);
    }
    pu(idx);
}

pair<long long, int> query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return {seg[idx].mx, seg[idx].idx};
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
        auto p = query(l, mid, 2*idx), q = query(mid+1, r, 2*idx+1);
        if(p.first > q.first){
            return p;
        }
        else{
            return q;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> pos[i] >> arr[i].first >> val[i];
        if(pos[i] > arr[i].first){
            swap(pos[i], arr[i].first);
        }
        arr[i].second = i;
        cmp.push_back(pos[i]);
        cmp.push_back(arr[i].first);
    }
    sort(arr+1, arr+1+N);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    M = cmp.size();
    long long ans = 0, v1 = 2e9, v2 = 2e9;
    build(1, M, 1);
    int idx = 1;
    for(int i = 1; i<=M; i++){
        //cout << i << endl;
        while(idx <= N && arr[idx].first == cmp[i-1]){
            //cout << "ping: " << arr[idx].first << " " << pos[arr[idx].second] << endl;
            upd(1, getidx(pos[arr[idx].second]), val[arr[idx].second], 1);
            idx++;
        }
        auto p = query(1, i, 1);
        //cout << p.first << " " << cmp[i-1] << " " << p.second << endl;
        //cout << "ding: " << query(1, 1, 1).first << endl;
        if(p.first-cmp[i-1] > ans){
            ans = p.first - cmp[i-1];
            v1 = p.second;
            v2 = cmp[i-1];
        }
    }
    cout << ans << "\n";
    cout << v1 << " " << v1 << " " << v2 << " " << v2 << "\n";
}