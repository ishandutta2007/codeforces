#include <bits/stdc++.h>
 
using namespace std;
 
int N, M, P;
long long K;
pair<int, long long> dp[1005][7005];
int par[1005][7005];
long long arr[1005];
long long brr[1005];
vector<long long> f;
vector<pair<long long, int>> lim;
vector<int> v[7005];
vector<long long> qikpow[50];
vector<int> ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    if(K == 1){
        int mini = 1;
        for(int i = 2; i<=N; i++){
            if(arr[mini] > arr[i]){
                mini = i;
            }
        }
        cout << 1 << endl;
        cout << mini << endl;
        return 0;
    }
    for(long long i = 1; i*i<=K; i++){
        if(K%i == 0){
            f.push_back(i);
            if(K/i != i){
                f.push_back(K/i);
            }
        }
    }
    sort(f.begin(), f.end());
    for(int i = 1; i<=N; i++){
        for(long long k : f){
            if(arr[i]%k == 0){
                brr[i] = k;
            }
        }
    }
    M = f.size();
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=M; j++){
            dp[i][j] = {N+1, LLONG_MAX>>2};
            par[i][j] = -1;
        }
    }
    long long t = K;
    for(long long k : f){
        if(k-1 && t%k == 0){
            int cnt = 0;
            while(t%k == 0){
                t/=k;
                cnt++;
            }
            lim.push_back({k, cnt});
        }
    }
    P = lim.size();
    for(int p = 0; p<P; p++){
        qikpow[p].push_back(1);
        for(int k = 1; k<=lim[p].second; k++){
            qikpow[p].push_back(qikpow[p].back()*lim[p].first);
        }
    }
    for(int j = 0; j<M; j++){
        for(int p = 0; p<P; p++){
            for(int k = lim[p].second; k>=0; k--){
                if(f[j]%qikpow[p][k] == 0){
                    v[j].push_back(k);
                    break;
                }
            }
        }
    }
    dp[0][0] = {0, 0};
    for(int i = 1; i<=N; i++){
        int t = lower_bound(f.begin(), f.end(), 1LL*brr[i]) - f.begin();
        for(int j = 0; j<M; j++){
            long long s = 1;
            for(int p = 0; p<P; p++){
                s *= qikpow[p][min(lim[p].second, v[t][p] + v[j][p])];
            }
            int idx = lower_bound(f.begin(), f.end(), s) - f.begin();
            if((dp[i-1][j].first + 1 < dp[i][idx].first)
               || (dp[i-1][j].first + 1 == dp[i][idx].first
                   && dp[i-1][j].second + arr[i] < dp[i][idx].second)){
                dp[i][idx].first = dp[i-1][j].first + 1;
                dp[i][idx].second = dp[i-1][j].second + arr[i];
                par[i][idx] = j;
            }
            if((dp[i-1][j].first < dp[i][j].first)
               || (dp[i-1][j].first == dp[i][j].first
                   && dp[i-1][j].second < dp[i][j].second)){
                dp[i][j].first = dp[i-1][j].first;
                dp[i][j].second = dp[i-1][j].second;
                par[i][j] = -1;
            }
        }
    }
    if(dp[N][M-1].second == LLONG_MAX>>2){
        cout << -1 << endl;
        return 0;
    }
    int crnt = M-1;
    for(int n = N; n; n--){
        if(par[n][crnt]+1){
            ans.push_back(n);
            crnt = par[n][crnt];
        }
    }
    cout << ans.size() << "\n";
    for(int n : ans){
        cout << n << " ";
    }
}