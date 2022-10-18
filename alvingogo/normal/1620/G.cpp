#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=998244353;
void add(int& x,int y){
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
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<array<int,26> > a(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            a[i][j]=count(v[i].begin(),v[i].end(),char('a'+j));
        }
    }
    vector<int> dp(1<<n);
    for(int i=1;i<(1<<n);i++){
        dp[i]=1;
        for(int u=0;u<26;u++){
            int z=1e9;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    z=min(z,a[j][u]);
                }
            }
            dp[i]=mul(dp[i],z+1);
        }
        if(__builtin_popcount(i)%2==0){
            dp[i]=(mod-dp[i])%mod;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            if((j>>i)&1){
                add(dp[j],dp[j^(1<<i)]);
            }
        }
    }
    long long ans=0;
    for(int i=1;i<(1<<n);i++){
        int nw=0,tmp=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                nw++;
                tmp+=j+1;
            }
        }
        ans^=(1ll*nw*tmp*dp[i]);
    }
    cout << ans << "\n";
    return 0;
}