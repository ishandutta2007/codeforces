#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=998244353;
void add(int &x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int po(int x,int y){
    int z=1;
    while(y){
        if(y&1){
            z=mul(z,x);
        }
        x=mul(x,x);
        y>>=1;
    }
    return z;
}
int inv(int x){
    return po(x,mod-2);
}
int main(){
    AquA;
    const int z=2050;
    vector<vector<int> > dp(z+1,vector<int>(z+1));
    dp[0][0]=1;
    for(int i=0;i<z;i++){
        for(int j=0;j<=i;j++){
            add(dp[i+1][j],mul(j,dp[i][j]));
            if(j+1<=z){
                add(dp[i+1][j+1],dp[i][j]);
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int ans=0;
        int nw=1;
        int r=(m+1)/2;
        int l=m-r;
        for(int i=0;i<=k;i++){
            if(n<i){
                break;
            }
            add(ans,mul(mul(nw,dp[k][i]),mul(po(m,n-i),po(r,i))));
            nw=mul(nw,n-i);
        }
        cout << ans << "\n";
    }
    
    return 0;
}