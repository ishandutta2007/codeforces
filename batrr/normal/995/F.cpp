#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=3123,inf=1e18,mod=1e9+7,N=360360;
ll n,d,dp[maxn][maxn],p[maxn],c[maxn][maxn],ans;
ll binpow(ll n,ll p){
    ll res=1;
    while(p){
        if(p&1)           
            res=res*n%mod;
        n=n*n%mod;
        p>>=1;
    }
    return res;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif        
    for(int i=0;i<maxn;i++)
        c[0][i]=1;
    for(int i=1;i<maxn;i++)
        for(int j=1;j<=i;j++)
            c[j][i]=(c[j][i-1]+c[j-1][i-1])%mod;
    cin>>n>>d;
    for(int i=2;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=1;
    for(int d=1;d<=n;d++)
        for(int v=n;v>=1;v--)
            dp[p[v]][d]=dp[p[v]][d]*(dp[v][d]=(dp[v][d]+dp[v][d-1])%mod)%mod;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            dp[1][i]=(dp[1][i]-dp[1][j]*c[j][i]%mod+mod)%mod;
    ll C=d;
    for(int i=1;i<=min(n,d);i++){
        ans+=C*dp[1][i]%mod;
        C=C*(d-i)%mod*binpow(i+1,mod-2)%mod;
    } 
    cout<<ans%mod;
}