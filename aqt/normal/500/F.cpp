#include <bits/stdc++.h>

using namespace std;

struct item{
    int c, v, t;
    bool operator < (item i) const{
        return t < i.t;
    }
};

int N, T, Q;
item arr[4005];
int lft[20005], rht[20005], b[20005];
vector<int> v[100000];
int dp[4005][4005][2];
int ans[20005];

void solve(int l, int r, int idx){
    if(v[idx].empty()){
        return;
    }
    int K = r-l+1;
    for(int k = 1; k<=K; k++){
        for(int c = 1; c<=4000; c++){
            dp[k][c][0] = dp[k][c][1] = 0;
        }
    }
    int mid = l+r>>1;
    for(int n = mid; n>=l; n--){
        for(int c = 4000; c>=arr[n].c; c--){
            dp[mid-n+1][c][0] = max(dp[mid-n][c][0], dp[mid-n][c-arr[n].c][0] + arr[n].v);
        }
        for(int c = arr[n].c-1; c>0; c--){
            dp[mid-n+1][c][0] = dp[mid-n][c][0];
        }
    }
    for(int n = mid+1; n<=r; n++){
        for(int c = 4000; c>=arr[n].c; c--){
            dp[n-mid][c][1] = max(dp[n-mid-1][c][1], dp[n-mid-1][c-arr[n].c][1] + arr[n].v);
        }
        for(int c = arr[n].c-1; c>0; c--){
            dp[n-mid][c][1] = dp[n-mid-1][c][1];
        }
    }
    for(int n : v[idx]){
        if(lft[n] <= mid+1 && rht[n] >= mid){
            //cout << "here: " << n << " " << mid-lft[n]+1 << " " << rht[n]-mid << "\n";
            for(int k = 0; k<=b[n]; k++){
                //cout << k << " " << b[n]-k << "\n";
                //cout << n << " " << dp[mid-lft[n]+1][k][0] << " " << dp[rht[n]-mid][b[n]-k][1] << "\n";
                ans[n] = max(ans[n], dp[mid-lft[n]+1][k][0] + dp[rht[n]-mid][b[n]-k][1]);
            }
        }
        else if(rht[n] < mid){
            v[2*idx].push_back(n);
        }
        else{
            v[2*idx+1].push_back(n);
        }
    }
    solve(l, mid-1, 2*idx);
    solve(mid+2, r, 2*idx+1);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].c >> arr[i].v >> arr[i].t;
    }
    sort(arr+1, arr+1+N);
    cin >> Q;
    for(int i = 1; i<=Q; i++){
        int t;
        cin >> t >> b[i];
        int l = 1, r = N;
        while(l <= r){
            int mid = l+r>>1;
            if(arr[mid].t + T - 1 >= t){
                lft[i] = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        l = 1, r = N;
        while(l <= r){
            int mid = l+r>>1;
            if(arr[mid].t <= t){
                rht[i] = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        //cout << " " << lft[i] << " " << rht[i] << "\n";
        if(lft[i] <= rht[i] && lft[i]){
            v[1].push_back(i);
        }
    }
    solve(1, N, 1);
    for(int i = 1; i<=Q; i++){
        cout << ans[i] << "\n";
    }
}