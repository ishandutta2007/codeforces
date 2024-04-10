#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
    int n;
    cin >> n;
    int q;
    cin >> q;
    bool f[10][10]={0};
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        f[a][b]=f[b][a]=1;
    }
    vector<vector<int> > to((1<<10),vector<int>(10));
    for(int i=0;i<10;i++){
        for(int j=0;j<(1<<10);j++){
            to[j][i]=j;
            if(!((j>>i)&1)){
                continue;
            }
            for(int k=0;k<10;k++){
                if(!f[i][k]){
                    to[j][i]|=(1<<k);
                }
            }
            for(int k=0;k<i;k++){
                if(((to[j][i]>>k)&1) && f[i][k]){
                    to[j][i]^=(1<<k);
                }
            }
        }
    }
    const int mod=998244353;
    auto add=[&](int& x,int y){
        x+=y;
        x-=mod*(x>=mod);
    };
    vector<vector<int> > dp(n+1,vector<int>(1<<10));
    dp[0][(1<<10)-1]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<10);j++){
            if(!dp[i][j]){
                continue;
            }
            for(int k=0;k<10;k++){
                if((j>>k)&1){
                    add(dp[i+1][to[j][k]],dp[i][j]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<10);i++){
        add(ans,dp[n][i]);
    }
    cout << ans << "\n";
	return 0;
}