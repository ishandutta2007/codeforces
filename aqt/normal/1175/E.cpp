#include <bits/stdc++.h>

using namespace std;

struct Node{
    int lft, rht, lzy;
};

int N, Q, M = 500000;
Node seg[21500000];
int cnt = 1;
int rt[500005], lst[500005];
vector<pair<int, int>> v;
deque<pair<int, int>> dq;

int cop(int idx){
    ++cnt;
    seg[cnt].lft = seg[idx].lft, seg[cnt].rht = seg[idx].rht;
    seg[cnt].lzy = seg[idx].lzy;
    return cnt;
}

void pd(int idx){
    seg[idx].lft = cop(seg[idx].lft);
    seg[seg[idx].lft].lzy += seg[idx].lzy;
    seg[idx].rht = cop(seg[idx].rht);
    seg[seg[idx].rht].lzy += seg[idx].lzy;
    seg[idx].lzy = 0;
}

void build(int l, int r, int idx){
    if(l ==r){
        return;
    }
    int mid = l+r>>1;
    seg[idx].lft = ++cnt;
    build(l, mid, seg[idx].lft);
    seg[idx].rht = ++cnt;
    build(mid+1, r, seg[idx].rht);
}

int upd(int nl, int nr, int l, int r, int idx, bool b){
//    cout << l << " " << r << " " << seg[idx].l << " " << seg[idx].r << endl;
    if(b){
        idx = cop(idx);
    }
    if(nl == l && nr == r){
        if(!b){
            idx = cop(idx);
        }
        seg[idx].lzy++;
        return idx;
    }
    b = 1;
//    cout << seg[idx].lzy << endl;
    if(seg[idx].lzy){
        pd(idx);
        b = 0;
    }
    int mid = nl + nr >> 1;
    if(r <= mid){
        seg[idx].lft = upd(nl, mid, l, r, seg[idx].lft, b);
    }
    else if(l > mid){
        seg[idx].rht = upd(mid+1, nr, l, r, seg[idx].rht, b);
    }
    else{
        seg[idx].lft = upd(nl, mid, l, mid, seg[idx].lft, b);
        seg[idx].rht = upd(mid+1, nr, mid+1, r, seg[idx].rht, b);
    }
    return idx;
}

int query(int nl, int nr, int p, int idx){
//    cout << p << " " << seg[idx].l << " " << seg[idx].r << endl;
    if(nl == nr){
        return seg[idx].lzy;
    }
//    cout << seg[idx].lzy << endl;
    if(seg[idx].lzy){
        pd(idx);
    }
    int mid = nl + nr >> 1;
    if(p <= mid){
        return query(nl, mid, p, seg[idx].lft);
    }
    else{
        return query(mid+1, nr, p, seg[idx].rht);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        int l, r;
        cin >> l >> r;
        l++;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());
    build(1, M, 1);
    rt[0] = 1;
    lst[1] = 1;
    int idx = 0;
    for(int i = 1; i<=M; i++){
        while(v[idx].first == i){
            while(dq.size() && dq.back().first == v[idx].first){
                dq.pop_back();
            }
            if(dq.empty() || dq.back().second < v[idx].second){
                dq.push_back(v[idx++]);
            }
            else{
                idx++;
            }
        }
        if(dq.empty()){
            lst[i] = i;
            rt[i] = cop(rt[i-1]);
            continue;
        }
        else{
            lst[i] = lst[i-1];
        }
        rt[i] = upd(1, M, 1, i, rt[dq.front().first-1], 1);
        while(dq.size() && dq.front().second <= i){
            dq.pop_front();
        }
    }
    while(Q--){
        int l, r;
        cin >> l >> r;
        l++;
        if(lst[r] >= l){
            cout << -1 << "\n";
        }
        else{
            cout << query(1, M, l, rt[r]) << "\n";
        }
    }
}