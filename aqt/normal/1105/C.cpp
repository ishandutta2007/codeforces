#include <bits/stdc++.h>

using namespace std;

long long dp[3][200005], cnt[3];
long long MOD = 1000000007;

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

int main(){
    int N, l, r;
    cin >> N >> l >> r;
    dp[0][0] = 1;
    if(r-l<10){
        for(int i = l; i<=r; i++){
            cnt[i%3]++;
        }
    }
    else{
        while(l%3 != 0){
            cnt[l%3]++;
            l++;
        }
        while(r%3 != 0){
            cnt[r%3]++;
            r--;
        }
        cnt[0] += (r-l)/3+1;
        cnt[1] += (r-l)/3;
        cnt[2] += (r-l)/3;
    }
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<3; j++){
            for(int k = 0; k<3; k++){
                dp[j][i] = add(dp[j][i], mult(cnt[k], dp[(j-k+3)%3][i-1]));
            }
        }
    }
    cout << dp[0][N] << endl;
}