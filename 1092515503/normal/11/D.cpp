#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,lim,f[1<<20][20],res;
bool g[20][20];
signed main(){
	scanf("%lld%lld",&n,&m),lim=(1<<n);
	for(int i=1,x,y;i<=m;i++)scanf("%lld%lld",&x,&y),x--,y--,g[x][y]=g[y][x]=true;
	for(int i=0;i<n;i++)f[1<<i][i]=1;
	for(int i=1;i<lim;i++)for(int j=0;j<n;j++){
		if(!(i&(1<<j)))continue;
		for(int k=__builtin_ctz(i);k<n;k++){
			if(!g[j][k])continue;
			if(i&(1<<k))res+=f[i][j]*(__builtin_ctz(i)==k);
			else f[i|(1<<k)][k]+=f[i][j];
		}
	}
	printf("%lld\n",(res-m)/2);
	return 0;
}