#include <bits/stdc++.h>

using namespace std;

int N, K;
long long ans;
vector<int> vpre[1000005], vsuf[1000005];
int tbl[20][300005];
long long pre[300005], suf[300005];
int arr[300005];

inline void solve(int l, int r){
    if(l > r){
        return ;
    }
    int rng = r-l+1;
    int k = 31-__builtin_clz(rng);
    int mid = tbl[k][l];
    mid = (arr[mid] > arr[tbl[k][r-(1<<k)+1]] ? mid : tbl[k][r-(1<<k)+1]);
    solve(l, mid-1);
    solve(mid+1, r);
    if(mid-1-l >= r-mid-1){
        for(int i = mid; i<=r; i++){
            int tar = pre[i] - arr[mid]%K;
            if(tar < 0){
                tar += K;
            }
            ans += upper_bound(vpre[tar].begin(), vpre[tar].end(), mid-1)
            -lower_bound(vpre[tar].begin(), vpre[tar].end(), l-1);
        }
    }
    else{
        for(int i = mid; i>=l; i--){
            int tar = suf[i] - arr[mid]%K;
            if(tar < 0){
                tar += K;
            }
            ans += upper_bound(vsuf[tar].begin(), vsuf[tar].end(), r+1)
            -lower_bound(vsuf[tar].begin(), vsuf[tar].end(), mid+1);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    ans = -N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        tbl[0][i] = i;
    }
    vpre[0].push_back(0);
    for(int i = 1; i<=N; i++){
        pre[i] = pre[i-1] + arr[i];
        pre[i] %= K;
        vpre[pre[i]].push_back(i);
    }
    vsuf[0].push_back(N+1);
    for(int i = N; i; i--){
        suf[i] = suf[i+1] + arr[i];
        suf[i] %= K;
        vsuf[suf[i]].push_back(i);
    }
    for(int i = 0; i<K; i++){
        reverse(vsuf[i].begin(), vsuf[i].end());
    }
    for(int d = 1; d<20; d++){
        for(int n = 1; n<=N-(1<<d)+1; n++){
            tbl[d][n] = (arr[tbl[d-1][n]] > arr[tbl[d-1][n+(1<<(d-1))]] ?
                         tbl[d-1][n] : tbl[d-1][n+(1<<(d-1))]);
        }
    }
    solve(1, N);
    cout << ans;
}