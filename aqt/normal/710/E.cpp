#include <bits/stdc++.h>

using namespace std;

int N;
long long x, y;
long long dp[20000005];
deque<int> dq;

void pu(int n){
    if(dq.size() && dp[n] <= dp[dq.front()]){
        dq.push_front(n);
    }
    else{
        dq.push_back(n);
    }
}

int main(){
    cin >> N >> x >> y;
    fill(dp, dp+2*N+1, LLONG_MAX);
    dp[1] = x;
    dq.push_back(1);
    while(dq.size()){
        int n = dq.front();
        dq.pop_front();
        if(n-1){
            if(dp[n-1] > dp[n] + x){
                dp[n-1] = dp[n] + x;
                pu(n-1);
            }
        }
        if(n+1 <=2*N){
            if(dp[n+1] > dp[n] + x){
                dp[n+1] = dp[n] + x;
                pu(n+1);
            }
        }
        if(2*n <= 2*N){
            if(dp[2*n] > dp[n] + y){
                dp[2*n] = dp[n] + y;
                pu(2*n);
            }
        }
    }
    cout << dp[N] << endl;
}