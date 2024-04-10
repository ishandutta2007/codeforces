#include<bits/stdc++.h>
using namespace std;
int n,a,b,A,B,f[1010][1010],c;
const int mod=1e9+7;
int ksm(int x,int y){
    int z=1;
    for(;y;x=(1ll*x*x)%mod,y>>=1)if(y&1)z=(1ll*z*x)%mod;
    return z;
}
int dfs(int x,int y){
    if(x+y>=n)return x+y+c;
    if(f[x][y]!=-1)return f[x][y];
    int &res=f[x][y];res=0;
    (res+=1ll*dfs(x+1,y)*A%mod)%=mod;
    (res+=1ll*dfs(x,x+y)*B%mod)%=mod;
    return res;
}
int main(){
    scanf("%d%d%d",&n,&a,&b),A=1ll*a*ksm(a+b,mod-2)%mod,B=1ll*b*ksm(a+b,mod-2)%mod,c=1ll*a*ksm(b,mod-2)%mod,memset(f,-1,sizeof(f));
    printf("%d\n",dfs(1,0));
    return 0;
}