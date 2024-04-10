#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,M2=1004535809,M3=469762049,E=524288,N=1000005;
int t,n,m,a[N],b[N],z,x,y,u,v,w;
long long g[505][505],f[505][505],s[505];
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i){
            s[i]=1ll<<50;
            for(int j=1;j<=n;++j)
                f[i][j]=g[i][j]=(1ll<<50);
            f[i][i]=0;
        }
        for(int i=1;i<=m;++i){
            scanf("%d %d %d",&u,&v,&w);
            g[v][u]=g[u][v]=min(g[u][v],1ll*w);
            f[u][v]=f[v][u]=1;
        }
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                s[i]=min(s[i],f[1][j]+f[i][j]+f[j][n]);
        long long ans=1ll<<50;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;++j){
                long long z=min({s[i]+1,s[j]+1,f[i][1]+f[j][n],f[i][n]+f[j][1]});
                if(z<=n*3){
                    // cout<<i<<' '<<j<<' '<<z<<endl;
                    ans=min(ans,(z+1)*g[i][j]);
                }
            }
        printf("%lld\n",ans);
    }
}