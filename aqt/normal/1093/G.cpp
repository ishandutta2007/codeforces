#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, mini, maxi;
};

Node seg[800005][32];
int N, K, Q;
int arr[200005][5];

inline void build(int l, int r, int idx, int m){
    seg[idx][m].l = l;
    seg[idx][m].r = r;
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx, m);
    build(mid+1, r, 2*idx+1, m);
}

inline void upd(int p, int v, int idx, int m){
    if(seg[idx][m].l == seg[idx][m].r){
        seg[idx][m].mini = seg[idx][m].maxi = v;
        return;
    }
    int mid = seg[idx][m].l + seg[idx][m].r >> 1;
    if(p <= mid){
        upd(p, v, 2*idx, m);
    }
    else{
        upd(p, v, 2*idx+1, m);
    }
    seg[idx][m].mini = min(seg[2*idx][m].mini, seg[2*idx+1][m].mini);
    seg[idx][m].maxi = max(seg[2*idx][m].maxi, seg[2*idx+1][m].maxi);
}

inline int query(int l, int r, int t, int idx, int m){
    if(seg[idx][m].l == l && seg[idx][m].r == r){
        if(t == 1){
            return seg[idx][m].maxi;
        }
        else{
            return -seg[idx][m].mini;
        }
    }
    int mid = (seg[idx][m].l + seg[idx][m].r) >> 1;
    if(r <= mid){
        return query(l, r, t, 2*idx, m);
    }
    else if(l > mid){
        return query(l, r, t, 2*idx+1, m);
    }
    else{
        return max(query(l, mid, t, 2*idx, m), query(mid+1, r, t, 2*idx+1, m));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int k = 0; k<1<<K; k++){
        build(1, N, 1, k);
    }
    for(int i =1; i<=N; i++){
        for(int j= 0; j<K; j++){
            cin >> arr[i][j];
        }
        for(int m = 0; m<1<<K; m++){
            int sum = 0;
            for(int d = 0; d<K; d++){
                if((1<<d)&m){
                    sum += arr[i][d];
                }
                else{
                    sum -= arr[i][d];
                }
            }
            upd(i, sum, 1, m);
        }
    }
    cin >> Q;
    while(Q--){
        int c;
        cin >> c;
        if(c == 1){
            int p;
            cin >> p;
            for(int k = 0; k<K; k++){
                cin >> arr[p][k];
            }
            for(int m = 0; m<1<<K; m++){
                int sum = 0;
                for(int d = 0; d<K; d++){
                    if((1<<d)&m){
                        sum += arr[p][d];
                    }
                    else{
                        sum -= arr[p][d];
                    }
                }
                upd(p, sum, 1, m);
            }
        }
        else{
            int l,r;
            cin >> l >> r;
            int ans = 0;
            for(int m = 0; m<1<<K; m++){
                ans = max(query(l, r, 1, 1, m) + query(l, r, -1, 1, m), ans);
            }
            cout << ans << "\n";
        }
    }
}