#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, mini;
};

Node seg[1000000];
int N, M, K, Q;
int arr[200005][2];
int quy[200005][2][2];
bool ans[200005];
vector<int> v[100005], q[100005];

void build(int l, int r, int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    if(l == r){
        seg[idx].mini = 0;
        return ;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    seg[idx].mini = min(seg[2*idx].mini, seg[2*idx+1].mini);
}

void upd(int p, int v, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].mini = v;
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(p <= mid){
        upd(p, v, 2*idx);
    }
    else{
        upd(p, v, 2*idx+1);
    }
    seg[idx].mini = min(seg[2*idx].mini, seg[2*idx+1].mini);
}

int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].mini;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
    }
}

void solve(int N, int M, int T){
//    cout << "solve: " << T << endl;
    build(1, M, 1);
    for(int n =1 ; n<=N; n++){
//            cout << "n: " << n << endl;
        for(int idx : v[n]){
//            cout << "   upd: " << idx << endl;
            upd(idx, n, 1);
        }
        for(int qu : q[n]){
//            cout << qu << " " << query(quy[qu][0][(T+1)&1], quy[qu][1][(T+1)&1], 1) << endl;
            ans[qu] |= query(quy[qu][0][(T+1)&1], quy[qu][1][(T+1)&1], 1) >= quy[qu][0][T];
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K >> Q;
    for(int i = 1; i<=K; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i = 1; i<=Q; i++){
        cin >> quy[i][0][0] >> quy[i][0][1] >> quy[i][1][0] >> quy[i][1][1];
    }
    for(int i = 1; i<=K; i++){
        v[arr[i][0]].push_back(arr[i][1]);
    }
    for(int  i = 1; i<=Q; i++){
        q[quy[i][1][0]].push_back(i);
    }
    solve(N, M, 0);
    for(int i = 1; i<=N; i++){
        q[i].clear();
        v[i].clear();
    }
    for(int i = 1; i <= K; i++){
        v[arr[i][1]].push_back(arr[i][0]);
    }
    for(int i = 1; i <= Q; i++){
        q[quy[i][1][1]].push_back(i);
    }
    solve(M, N, 1);
    for(int q = 1; q <= Q; q++){
        if(ans[q]){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}