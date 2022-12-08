#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2+5;
const ll mod = 1e9+7;

int n,b[N],c[N],f[N][N*N];
int ssumb[N],sumb[N],sumc[N];

ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return r;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i],sumc[i]=sumc[i-1]+c[i];
    for(int i=1;i<n;++i)cin>>b[i];
    for(int i=1;i<=n;++i)sumb[i]=sumb[i-1]+b[i];
    for(int i=1;i<=n;++i)ssumb[i]=ssumb[i-1]+sumb[i];
    f[0][0]=1;
    int q,x;
    cin>>q>>x;
    for(int i=0;i<n;++i)
    for(int j=0;j<=sumc[i];++j)
    if(f[i][j]){
        for(int k=0;k<=c[i+1];++k)
        if(j+k>=ssumb[i]+x*(i+1)){
            (f[i+1][j+k]+=f[i][j])%=mod;
        }
    }
    int ans=0;
    for(int i=0;i<=10000;++i)(ans+=f[n][i])%=mod;
    cout<<ans<<endl;
}