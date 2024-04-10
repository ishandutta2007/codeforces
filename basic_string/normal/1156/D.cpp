#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int f[N],g[N],sf[N],sg[N];
int gf(int*a,int x){return a[x]==x?x:a[x]=gf(a,a[x]);}
int main(){
	int n,i,j,k,l;
	long long s=0;
	scanf("%d",&n),iota(f+1,f+n+1,1),iota(g+1,g+n+1,1);
	for(i=1;i<n;++i){
		scanf("%d%d%d",&j,&k,&l);
		if(l)f[gf(f,j)]=gf(f,k);
		else g[gf(g,j)]=gf(g,k);
	}
	for(i=1;i<=n;++i)++sf[gf(f,i)],++sg[gf(g,i)];
	for(i=1;i<=n;++i){
		if(f[i]==i)s+=sf[i]*(sf[i]-1ll);
		if(g[i]==i)s+=sg[i]*(sg[i]-1ll);
		s+=(sf[gf(f,i)]-1ll)*(sg[gf(g,i)]-1);
	}
	printf("%lld",s);
	return 0;
}