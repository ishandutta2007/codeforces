#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, v;
};

int pre[100005];
long long arr[100005];
Node seg[500005];
int dp[100005];
vector<long long> v;

void build(int l, int r,int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

void upd(int p, int v, int idx){
    if(seg[idx].l == seg[idx].r){
        seg[idx].v = v;
        return;
    }
    int mid = seg[idx].l+seg[idx].r>>1;
    if(p <= mid){
        upd(p, v, 2*idx);
    }
    else{
        upd(p, v, 2*idx+1);
    }
    seg[idx].v = (dp[seg[2*idx].v] > dp[seg[2*idx+1].v]) ? seg[2*idx].v : seg[2*idx+1].v;
}

int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r ==r){
        return seg[idx].v;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        int idx1 = query(l, mid, 2*idx), idx2 = query(mid+1, r, 2*idx+1);
        if(dp[idx1] > dp[idx2]){
            return idx1;
        }
        else{
            return idx2;
        }
    }
}

int main(){
    int N;
    long long D;
    cin >> N >> D;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    build(0, N+2, 1);
    dp[1] = 1;
    upd(lower_bound(v.begin(), v.end(), arr[1])-v.begin()+1, 1, 1);
//    cout << lower_bound(v.begin(), v.end(), arr[1])-v.begin()+1 << endl;
    int maxi = 1;
    for(int i = 2; i<=N; i++){
        int l = upper_bound(v.begin(), v.end(), arr[i]-D) - v.begin();
        int r = lower_bound(v.begin(), v.end(), arr[i]+D) - v.begin() + 1;
        int p = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
//        cout << "idx: " << i << " " << l << " " << r << " " << p << endl;
        int idx1 = query(0, l, 1), idx2 = query(r, N+2, 1);
        int idx, q;
        if(dp[idx1] > dp[idx2]){
            idx = idx1;
            q = dp[idx1];
        }
        else{
            idx = idx2;
            q = dp[idx2];
        }
        dp[i] = q + 1;
        pre[i] = idx;
        if(dp[query(p, p, 1)] < q + 1){
            upd(p, i, 1);
            if(dp[i] > dp[maxi]){
                maxi = i;
            }
        }
    }
    stack<int> stk;
    cout << dp[maxi] << endl;
    while(maxi){
        stk.push(maxi);
        maxi = pre[maxi];
    }
    while(stk.size()){
        cout << stk.top() << " ";
        stk.pop();
    }
}