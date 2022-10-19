#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,f[1<<11][1<<11],lim,res;
bool g[11][11];
signed main(){
	scanf("%lld%lld%lld",&n,&m,&p),lim=(1<<n);
	for(int i=1,x,y;i<=m;i++)scanf("%lld%lld",&x,&y),x--,y--,g[x][y]=g[y][x]=true,f[(1<<x)|(1<<y)][(1<<x)|(1<<y)]=2;
	for(int S=1;S<lim;S++)for(int s=S;s;s=(s-1)&S){
		f[S][s]/=__builtin_popcount(s);
		for(int i=0;i<n;i++){
			if(!(S&(1<<i)))continue;
			int t=s&((lim-1)^(1<<i));
			for(int j=0;j<n;j++){
				if(S&(1<<j))continue;
				if(!g[i][j])continue;
				f[S|(1<<j)][t|(1<<j)]+=f[S][s];
			}
		}		
	}
	for(int i=0;i<lim;i++)if(__builtin_popcount(i)==p)res+=f[lim-1][i];
	printf("%lld\n",res);
	return 0;
}