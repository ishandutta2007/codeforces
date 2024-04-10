#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int c,he[N],to[N],ne[N],p[N],ans[N],a[N],w[N<<1],t[N<<1],u[N],v[N],d[N];
void add(int x,int y){for(;x<=c;x+=x&-x)t[x]=max(y,t[x]);}
int get(int x){int r=0;for(;x;x-=x&-x)r=max(r,t[x]);return r;}
int main(){
	int n,m,i,j,k=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i),w[i]=a[i];
	for(i=1;i<=m;++i)scanf("%d%d",p+i,to+i),ne[i]=he[p[i]],he[p[i]]=i,w[n+i]=to[i];
	sort(w+1,w+n+m+1),c=unique(w+1,w+n+m+1)-w-1;
	for(i=1;i<=n;++i)a[i]=lower_bound(w+1,w+c+1,a[i])-w;
	for(i=1;i<=m;++i)to[i]=lower_bound(w+1,w+c+1,to[i])-w;
	for(i=1;i<=n;++i){
		for(j=he[i];j;j=ne[j])ans[j]=get(to[j]-1);
		add(a[i],u[i]=get(a[i]-1)+1);
	}
	memset(t,0,sizeof(t));
	for(i=n;i;--i){
		for(j=he[i];j;j=ne[j])ans[j]+=get(c-to[j]);
		add(c-a[i]+1,v[i]=get(c-a[i])+1),k=max(k,u[i]+v[i]);
	}
	for(i=1;i<=n;++i)if(u[i]+v[i]==k)++d[u[i]];
	for(i=1;i<=m;++i)j=p[i],printf("%d\n",max(ans[i]+1,k-2+(u[j]+v[j]!=k||d[u[j]]>1)));
	return 0;
}