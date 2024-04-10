#include<bits/stdc++.h>
using namespace std;
const int N=3009;
int f[N],w[N],s[N];
struct E{
	int u,v,w;
	inline bool operator<(E a)const{return w<a.w;}
}e[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){
	int n,i,v=0,x,y;
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(i=1;i<=n;++i)scanf("%d",w+i),f[i]=i,v+=w[i],s[i]=1;
	sort(e+1,e+n);
	for(i=1;i<n;++i){
		x=gf(e[i].u),y=gf(e[i].v);
		f[x]=y,s[y]+=s[x],w[y]+=w[x];
		if(s[y]>v-w[y])return printf("%d",e[i].w),0;
	}
	printf("%d",e[n-1].w);
	return 0;
}