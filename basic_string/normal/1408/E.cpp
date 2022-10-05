#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
#define ll long long
int a[N],b[N],p[N],f[N],d[N];
struct P{
	int x,y,w;
	bool operator<(P a)const{return w>a.w;}
}c[N*2];
bool cmp1(int x,int y){
	return a[x]>a[y];
}
bool cmp2(int x,int y){
	return b[x]>b[y];
}
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){
	int m,n,i,j,k,l,u,w,t=0;
	ll s=0,o=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)scanf("%d",b+i);
	for(i=1;i<=m;++i)p[i]=i;
	sort(p+1,p+m+1,cmp1);
	for(i=1;i<=m;++i){
		scanf("%d",&j);
		while(j--){
			scanf("%d",&k),o+=a[i]+b[k];
			c[++t]={i,k,a[i]+b[k]};
		}
	}
	sort(c+1,c+t+1);
	for(i=1;i<=n;++i)f[i]=i;
	for(i=1;i<=t;++i){
		if(!d[c[i].x])d[c[i].x]=c[i].y,s+=c[i].w;
		else if(gf(d[c[i].x])!=gf(c[i].y))f[gf(c[i].y)]=gf(d[c[i].x]),s+=c[i].w;
	}
	printf("%lld",o-s);
	return 0;
}