#include <bits/stdc++.h>

using namespace std;

int N, M, D;
string s, t;
long long dp[2005][2005];
long long MOD = 1e9+7;
long long pows[2005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long solve(int n, int m, bool b){
    //cout << n << " " << m << endl;
    if(n == -1){
        return (!m ? 1 : 0);
    }
    if(!b && dp[n][m] != -1){
        return dp[n][m];
    }
    long long ret = 0;
    int lim = 9;
    if(b){
        lim = s[N-n-1]-'0';
    }
    if((N-n)%2 == 0){
        if(D <= lim){
            ret = solve(n-1, (m+pows[n]*D)%M, (b&&D==lim));
        }
        else{
            return 0;
        }
    }
    else{
        for(int d = 0; d<=lim; d++){
            if(d != D){
                ret = add(ret, solve(n-1, (m+pows[n]*d)%M, (b && d == lim)));
            }
        }
    }
    if(!b){
        dp[n][m] = ret;
    }
    return ret;
}

int main(){
    cin >> M >> D >> s >> t;
    N = s.size();
    pows[0] = 1;
    for(int i =1; i<=N; i++){
        pows[i] = pows[i-1]*10%M;
    }
    for(int i =0 ; i<=N; i++){
        for(int j = 0; j<M; j++){
            dp[i][j] = -1;
        }
    }
    long long ans = -solve(N-1, 0, 1);
    swap(s, t);
    ans = add(ans, solve(N-1, 0, 1));
    bool k = 1;
    long long sum = 0;
    for(int i = 0; i<N; i++){
        if(i%2 == 1 && t[i]-'0' != D){
            k = 0;
        }
        else if(i%2 == 0 && t[i]-'0' == D){
            k = 0;
        }
        sum = (sum + pows[N-i-1]*(t[i]-'0'))%M;
    }
    if(k && !sum){
        ans = add(ans, 1);
    }
    if(ans < 0){
        ans += MOD;
    }
    cout << ans << endl;
}