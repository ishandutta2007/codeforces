#include<bits/stdc++.h>
using namespace std;
bool f[67];
long long g[67];
int main(){
	long long n,s,b,a;
	int m,i,j,T;
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
		scanf("%lld%d",&n,&m),s=a=0;
		for(i=0;i<63;++i)if(n&(1ll<<i))f[i]=1;
		for(i=1;i<=m;++i){
			scanf("%d",&j),s+=j,++g[__lg(j)];
		}
		if(n>s){
			puts("-1");
			continue;
		}
		for(i=62;i;--i){
			if(f[i])--g[i];
			b=(s-n)/(1ll<<i);
			if(b>g[i])b=g[i];
			g[i]-=b,s-=b*(1ll<<i);
			a+=g[i],g[i-1]+=g[i]<<1ll;
		}
		printf("%lld\n",a);
	}
	return 0;
}//