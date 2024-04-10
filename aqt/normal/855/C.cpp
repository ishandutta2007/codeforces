#include <bits/stdc++.h>

using namespace std;

int N, M, H, K;
long long num0, num1, num2;
vector<int> graph[100005];
long long dp[100005][11][3];
long long MOD = 1e9+7;
long long temp[10];

long long mult(long long a, long long b){
    return (a%MOD*b%MOD)%MOD;
}

void dfs(int n, int p){
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
        }
    }
    dp[n][0][2] = num2;
    dp[n][0][0] = num0;
    dp[n][1][1] = 1;
    for(int e : graph[n]){
        if(e != p){
            for(int k = K; k>=0; k--){
                temp[k] = 0;
                for(int x = 0; x<=k; x++){
                    temp[k] += mult(dp[e][x][0] + dp[e][x][1] + dp[e][x][2], dp[n][k-x][0]);
                    temp[k]%=MOD;
                }
            }
            for(int k = K; k>=0; k--){
                dp[n][k][0] = temp[k]%MOD;
            }
            for(int k = K; k>=0; k--){
                temp[k] = 0;
                for(int x= 0; x<=k; x++){
                    temp[k] += mult(dp[e][x][0], dp[n][k-x][1]);
                    temp[k]%=MOD;
                }
            }
            for(int k = K; k>=0; k--){
                dp[n][k][1] = temp[k]%MOD;
            }
            for(int k = K; k>=0; k--){
                temp[k] = 0;
                for(int x = 0; x<=k; x++){
                    temp[k] += mult(dp[e][x][0] + dp[e][x][2], dp[n][k-x][2]);
                    temp[k]%=MOD;
                }
            }
            for(int k = K; k>=0; k--){
                dp[n][k][2] = temp[k]%MOD;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> H >> K;
    num0 = H-1;
    num2 = M-H;
    dfs(1, 0);
    long long tot =0;
    for(int t = 0; t<3; t++){
        for(int k = 0; k<=K; k++){
            tot += dp[1][k][t];
        }
    }
    tot %= MOD;
    cout << tot << endl;
}