#include<bits/stdc++.h>
#define N 1010
using namespace std;
int f[N],sz[N],c[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fx]=fy;
		sz[fy]+=sz[fx];
	}
}
int main(){
	int n,m,k,a,b,ans=0,lf,mx=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i,sz[i]=1;
	for(int i=0;i<k;i++) scanf("%d",&c[i]);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		uni(a,b);
	}
	lf=n;
	for(int i=0;i<k;i++){
		b=sz[find(c[i])];
		lf-=b;
		mx=max(mx,b);
		ans+=b*(b-1)/2;
	}
	ans+=mx*lf+lf*(lf-1)/2;
	ans-=m;
	printf("%d\n",ans);
	return 0;
}