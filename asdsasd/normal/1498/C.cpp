#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
bool tf[1010][1010];
int memo[1010][1010];
int nn = 0;

int cnt(int n, int k){
    if(tf[n][k]) return memo[n][k];
    if(k == 1 || n == 0){
        memo[n][k] = 1;
        tf[n][k] = true;
        return 1;
    }
    else{
        auto ret = cnt(n - 1, k) + cnt(nn - n, k - 1);
        ret %= MOD;
        tf[n][k] = true;
        memo[n][k] = ret;
        return ret;
    }
}

void solve(){
    int k;
    scanf("%d %d", &nn, &k);
    
    for(int i = 0; i <= nn; i++){
        for(int j = 0; j <= k ; j++){
            tf[i][j] = false;
        }
    }
    
    
    int ans = cnt(nn, k);
    printf("%d\n", ans);
    
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}