#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=1e7+3,O=7e5+3,P=1e9+7; 
basic_string<int>g[N],o[N];
using ar=int[N];
ar tp,sn,sz,fa,d,a;
int ans[N*2],w[N*2];
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;return r;}
void dfs1(int x,int y){
	sz[x]=1,d[x]=d[y]+1,fa[x]=y;
	for(int i:g[x])if(i!=y)if(dfs1(i,x),sz[x]+=sz[i],sz[i]>sz[sn[x]])sn[x]=i;
}
void dfs2(int x,int y){
	if(tp[x]=y,sn[x])dfs2(sn[x],y);
	for(int i:g[x])if(!tp[i])dfs2(i,i);
}
int lca(int x,int y){
	for(;tp[x]!=tp[y];x=fa[tp[x]])if(d[tp[x]]<d[tp[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
int p[O],ip[O],id[M];
bool b[M];
vector<int>v1[O],v2[O];
void xxs(){
	int i,j,k,t=0;
	for(i=2;i<M;++i){
		if(!b[i]){
			p[++t]=i,ip[t]=qp(i,P-2),id[i]=t;
			for(j=i,k=1;j*1ll*i<M;j*=i,++k);
			v1[t].assign(k,1),v2[t].assign(k,1);
		}
		for(j=1;j<=t&&(k=i*p[j])<M;++j)if(b[k]=1,i%p[j]==0)break;
	}
}
void dfs(int x,int y){
	int i,j=a[x],k,l,o;
	for(i=1;p[i]*p[i]<=j;++i)if(j%p[i]==0){
		k=-1;
		do j/=p[i],++k;while(j%p[i]==0);
		for(l=0,o=1;l<k;++l)o*=p[i],v1[i][l]=v1[i][l]*1ll*o%P;
		v2[i][l]=v2[i][l]*1ll*(o*p[i])%P;
	}
	if(j>1)i=id[j],v2[i][0]=v2[i][0]*1ll*p[i]%P;
	for(int u:(::o[x])){
		int&s=ans[u];
		for(i=1,j=w[u];p[i]*p[i]<=j;++i)if(j%p[i]==0){
			k=-1;
			do j/=p[i],++k;while(j%p[i]==0);
			for(l=0;l<=k;++l)s=s*1ll*v2[i][l]%P;
			s=s*1ll*v1[i][k]%P;
		}
		if(j>1)i=id[j],s=s*1ll*v2[i][0]%P,s=s*1ll*v1[i][0]%P;
	}
	for(int u:g[x])if(u!=y)dfs(u,x);
	for(i=1,j=a[x];p[i]*p[i]<=j;++i)if(j%p[i]==0){
		k=-1;
		do j/=p[i],++k;while(j%p[i]==0);
		for(l=0,o=1;l<k;++l)o=o*1ll*ip[i]%P,v1[i][l]=v1[i][l]*1ll*o%P;
		v2[i][l]=v2[i][l]*1ll*o%P*ip[i]%P;
	}
	if(j>1)i=id[j],v2[i][0]=v2[i][0]*1ll*ip[i]%P;
}
int main(){
	int n,q,i,j,k,l;
	scanf("%d",&n),xxs();
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	dfs1(1,0),dfs2(1,1);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	scanf("%d",&q);
	for(i=1;i<=q;++i){
		scanf("%d%d%d",&j,&k,w+i),l=lca(j,k),w[i+q]=w[i],ans[i]=ans[i+q]=1;
		o[j]+=i,o[k]+=i,o[l]+=i+q,o[fa[l]]+=i+q;
	}
	dfs(1,0);
	for(i=1;i<=q;++i)printf("%lld\n",ans[i]*1ll*qp(ans[i+q],P-2)%P);
	return 0;
}