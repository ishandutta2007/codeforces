#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[1<<20];
long long MOD = 1e9+7;
long long pows[1<<20];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1; i<=N; i++){
        int n;
        cin >> n;
        dp[n]++;
    }
    pows[0] = 1;
    for(int i = 1; i<=N; i++){
        pows[i] = (pows[i-1]*2)%MOD;
    }
    for(int k = 0; k<20; k++){
        for(int m = (1<<20)-1; m>=0; m--){
            if(!((1<<k)&m)){
                dp[m] += dp[m^(1<<k)];
            }
        }
    }
    long long ans = 0;
    for(int m = 0; m<1<<20; m++){
        if(__builtin_popcount(m)&1){
            ans = sub(ans, pows[dp[m]]);
        }
        else{
            ans = add(ans, pows[dp[m]]);
        }
    }
    cout << ans << endl;
}