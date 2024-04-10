#include<bits/stdc++.h>
using namespace std;const int N=1e6+4;
struct P{
	int x,y,w;
}p[N];
basic_string<int>g[N];
int r,pr[N],nx[N],n,fa[N],h[N],f[N],fg[N],e[N],f2[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
bool b[N];
void dfs(int x){fa[x]=r;
	basic_string<int>tmp;
	for(int i:g[x])b[i]=1;
	for(int i=nx[0];i!=n+1;i=nx[i])if(!b[i]){
		tmp+=i;
		nx[pr[i]]=nx[i],pr[nx[i]]=pr[i];
	}
	for(int i:g[x])b[i]=0;
	for(int i:tmp)if(!fa[i])dfs(i);
}int gg(int x){return fg[x]==x?x:fg[x]=gg(fg[x]);}
int main(){
	int m,i,j,k,l,w=0,jj,kk;
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)nx[i-1]=i,pr[i+1]=i;
	nx[n]=n+1; 
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&j,&k,&p[i].w);p[i].x=j,p[i].y=k;
		w^=p[i].w;
		g[j]+=k,g[k]+=j;
	}
	for(i=1;i<=n;++i)if(!fa[i])dfs(r=i);
	for(i=1;i<=n;++i)++h[fa[i]];
	for(i=1;i<=m;++i){
		j=fa[p[i].x],k=fa[p[i].y];
		if(j==k)++e[j];
	}
	for(i=1;i<=n;++i)if(fa[i]==i&&h[i]*1ll*(h[i]-1)/2-e[i]>h[i]-1)w=0;
	sort(p+1,p+m+1,[](P a,P b){return a.w<b.w;});
	iota(f,f+N,0);iota(fg,fg+N,0);
	int fl=1;
	for(i=1;i<=m;++i){
		j=gf(fa[p[i].x]),k=gf(fa[p[i].y]);
		jj=gg(p[i].x),kk=gg(p[i].y);
		if(j!=k){
			ans+=p[i].w;
			f[j]=k;
		}else{
			if(jj!=kk)w=min(w,p[i].w);
		}
		fg[jj]=kk;
	}
	cout<<ans+w;
	return 0;
}