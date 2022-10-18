#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=1e9+7;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int inv(int x){
    return x==1?1:mul(mod-mod/x,inv(mod%x));
}
int conb(int n,int k){
    int re=1;
    for(int i=1;i<=k;i++){
        re=mul(re,inv(i));
        re=mul(re,n-i+1);
    }
    return re;
}
int main(){
    AquA;
    int n,k;
    cin >> n >> k;
    vector<vector<int> > C(2*k+5,vector<int>(2*k+5)),dp=C;
    vector<int> ans(2*k+5);
    C[0][0]=1;
    for(int i=1;i<=2*k;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j];
            add(C[i][j],C[i-1][j-1]);
        }
    }
    for(int i=1;i<=2*k;i++){
        dp[i][0]=1;
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            add(dp[i][j],mul(i-1,dp[i-1][j-1]));
        }
    }
    ans[0]=1;
    for(int j=1;j<=k;j++){
        if(j>=2){
            ans[j]=ans[j-2];
        }
        for(int i=1;i<=min(n,2*j);i++){
            int cnt=0;
            for(int l=0;l<=i;l++){
                int z=mul(C[i][l],dp[i-l][j]);
                if(l%2){
                    z=(mod-z)%mod;
                }
                add(cnt,z);
            }
            
            add(ans[j],mul(conb(n,i),cnt));
        }
        cout << ans[j] << " ";
    }
    cout << "\n";
    return 0;
}