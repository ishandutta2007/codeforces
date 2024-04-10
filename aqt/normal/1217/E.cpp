#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r;
    vector<int> b, s;
};

int N, Q, K = 10;
Node seg[600005];
int arr[200005], msk[200005];

int getmsk(int n){
    int ret = 0;
    for(int k = 0; k<K; k++){
        if(n%10){
            ret |= (1<<k);
        }
        n/=10;
    }
    return ret;
}

void pu(int idx){
    for(int k = 0; k<K; k++){
        seg[idx].b[k] = seg[2*idx].b[k];
        seg[idx].s[k] = seg[2*idx].s[k];
        if(seg[2*idx+1].b[k] <= seg[idx].b[k]){
            seg[idx].s[k] = seg[idx].b[k];
            seg[idx].b[k] = seg[2*idx+1].b[k];
        }
        else if(seg[2*idx+1].b[k] < seg[idx].s[k]){
            seg[idx].s[k] = seg[2*idx+1].b[k];
        }
        if(seg[2*idx+1].s[k] < seg[idx].s[k]){
            seg[idx].s[k] = seg[2*idx+1].s[k];
        }
    }
}

void build(int l, int r, int idx){
    seg[idx].l =l, seg[idx].r = r;
    seg[idx].b.resize(K, INT_MAX), seg[idx].s.resize(K, INT_MAX);
    if(l == r){
        for(int k = 0; k<K; k++){
            if((msk[l]>>k)&1){
                seg[idx].b[k] = arr[l];
            }
        }
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    pu(idx);
}

void upd(int p, int idx){
    if(seg[idx].l == seg[idx].r){
        for(int k = 0; k<K; k++){
            if((msk[p]>>k)&1){
                seg[idx].b[k] = arr[p];
            }
            else{
                seg[idx].b[k] = INT_MAX;
            }
        }
        return;
    }
    if(p <= (seg[idx].l+seg[idx].r)>>1){
        upd(p, 2*idx);
    }
    else{
        upd(p, 2*idx+1);
    }
    pu(idx);
}

pair<int, int> query(int l, int r, int k, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return {seg[idx].b[k], seg[idx].s[k]};
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, k, 2*idx);
    }
    else if(l > mid){
        return query(l, r, k, 2*idx+1);
    }
    else{
        auto p = query(l, mid, k, 2*idx);
        auto q = query(mid+1, r, k, 2*idx+1);
        if(q.first <= p.first){
            p.second = p.first;
            p.first = q.first;
        }
        else if(q.first < p.second){
            p.second = q.first;
        }
        if(q.second < p.second){
            p.second = q.second;
        }
        return p;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i =1 ;i<=N; i++){
        cin >> arr[i];
        msk[i] = getmsk(arr[i]);
        //cout << "msk: " << i << " " << msk[i] << endl;
    }
    build(1, N, 1);
    while(Q--){
        int c, x, y;
        cin >> c >> x >> y;
        //cout << c << " " << x << " " << y << "\n";
        if(c == 2){
            int ans = 2e9;
            for(int k = 0; k<K; k++){
                auto p = query(x, y, k, 1);
                if(p.second <= 1e9){
                    ans = min(p.first+p.second, ans);
                }
            }
            if(ans >= 2e9){
                ans = -1;
            }
            cout << ans <<"\n";
        }
        else{
            arr[x] = y;
            msk[x] = getmsk(y);
            //cout << "upd: " << msk[x] << "\n";
            upd(x, 1);
        }
    }
}