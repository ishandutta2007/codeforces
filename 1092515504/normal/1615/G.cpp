#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
const int N=1200100,M=6001000;
namespace BLS{
int n,m,tot,qwq;
int q[N],l,r; 
int h[N],lk[N],tag[N],fa[N],pre[N],dfn[N];
struct edge{int t,n;}e[M];
V link(int x,int y){lk[x]=y,lk[y]=x;}
V add_edge(int x,int y){
	if(!lk[x]&&!lk[y])link(x,y);
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
}
V rev(int x){if(x)rev(x[pre][lk]),link(x,pre[x]);}
I find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
I lca(int x,int y){
	for(qwq++;;x=x[lk][pre],swap(x,y))
		if(dfn[x=find(x)]==qwq)return x;
		else if(x)dfn[x]=qwq;
}
V shrink(int x,int y,int p){
	for(;find(x)!=p;x=pre[y]){
		pre[x]=y,y=lk[x],fa[x]=fa[y]=p;
		if(tag[y]==2)tag[y]=1,q[r++]=y;
	}
}
int stk[N<<2],tp;
I blossom(int u){
	for(int i=0;i<r;i++)tag[q[i]]=pre[q[i]]=0,fa[q[i]]=q[i];
	for(int i=0;i<tp;i++)tag[stk[i]]=pre[stk[i]]=0,fa[stk[i]]=stk[i];tp=0;
	l=r=0;
	tag[u]=1,q[r++]=u;
	for(int p;l!=r;){
		REP(u=q[l++])
			if(tag[v]==1)
				p=lca(u,v),shrink(u,v,p),shrink(v,u,p),stk[tp++]=p,stk[tp++]=v;
			else if(!tag[v]){
				pre[v]=u,tag[v]=2,stk[tp++]=v;
				if(!lk[v])return rev(v),1;
				else tag[lk[v]]=1,q[r++]=lk[v];
			}
	}
	return 0;
}	
}using namespace BLS;
int a[N];
bool occ[N],acc[N];
int id=1;
vector<pair<int,int> >v;
int main(){
	scanf("%d",&n);
	FOR(i,1,(n<<1))fa[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),occ[a[i]]=true;
	for(int i=1;i<n;i++)if(a[i]&&a[i+1]&&a[i]==a[i+1])acc[a[i]]=true;
	for(int l=1,r;l<=n;l=r){
		while(l<=n&&a[l])l++;
		if(l>n)break;
		r=l;while(r<=n&&!a[r])r++;
		v.emplace_back(l,r);
		if((r-l)&1){
			if(l>1&&!acc[a[l-1]])add_edge(a[l-1],n+l);
			if(r<=n&&!acc[a[r]])add_edge(a[r],n+l);
		}else{
			if(l>1&&!acc[a[l-1]])add_edge(a[l-1],n+l);
			if(r<=n&&!acc[a[r]])add_edge(a[r],n+r-1);
			add_edge(n+l,n+r-1);
		}
	}
	FOR(i,1,n<<1)if(!lk[i])blossom(i);
	for(auto x:v){
		int l=x.first,r=x.second;
		if((r-l)&1){
			if(l>1&&lk[n+l]==a[l-1]){
				a[l]=a[l-1];
				for(int i=l+1;i+1<r;i+=2){
					while(occ[id])id++;
					a[i]=a[i+1]=id++;
				}
			}else{
				for(int i=l;i+1<r;i+=2){
					while(occ[id])id++;
					a[i]=a[i+1]=id++;
				}
				a[r-1]=a[r];
			}
		}else{
			if(lk[n+l]==n+r-1){
				for(int i=l;i+1<r;i+=2){
					while(occ[id])id++;
					a[i]=a[i+1]=id++;
				}
			}else{
				a[l]=a[l-1],a[r-1]=a[r];
				for(int i=l+1;i+1<r;i+=2){
					while(occ[id])id++;
					a[i]=a[i+1]=id++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]?a[i]:1);puts("");
	return 0;
}