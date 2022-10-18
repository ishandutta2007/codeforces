#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=1e9+7;
void add(int &x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int main(){
    AquA;
    int n;
    cin >> n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    vector<vector<pair<int,int> > > dp(n,vector<pair<int,int> >(n));
    for(int i=0;i<n;i++){
        dp[i][i].fs=dp[i][i].sc=1;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(v[i][j]){
                for(int k=i;k<j;k++){
                    add(dp[i][j].fs,mul(dp[i][k].sc,dp[k+1][j].sc)); 
                }
            }
            for(int k=i+1;k<=j;k++){
                if(v[i][k]){
                    add(dp[i][j].sc,mul(dp[i][k].fs,dp[k][j].sc));
                }
            }
            //add(dp[i][j].sc,dp[i][j].fs);
        }
    }
    cout << dp[0][n-1].sc << "\n";
    return 0;
}