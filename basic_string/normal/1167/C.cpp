#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int f[N],g[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){
	int n,m,k,i,j;
	scanf("%d%d",&n,&m),iota(f+1,f+n+1,1);
	while(m--){
		scanf("%d",&k);
		if(k){
			scanf("%d",&i);
			while(--k)scanf("%d",&j),f[gf(j)]=gf(i);
		}
	}
	for(i=1;i<=n;++i)++g[gf(i)];
	for(i=1;i<=n;++i)printf("%d ",g[gf(i)]);
	return 0;
}