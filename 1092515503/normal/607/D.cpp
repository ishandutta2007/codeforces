#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,a[200100],q,sz[200100],dfn[200100],rev[200100],tot,fa[200100],deg[200100];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{int sum,tag;SegTree(){sum=0,tag=1;}}seg[800100];
void MUL(int x,int y){seg[x].sum=1ll*seg[x].sum*y%mod,seg[x].tag=1ll*seg[x].tag*y%mod;}
void pushdown(int x){MUL(lson,seg[x].tag),MUL(rson,seg[x].tag),seg[x].tag=1;}
void pushup(int x){seg[x].sum=(seg[lson].sum+seg[rson].sum)%mod;}
void multiply(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){MUL(x,val);return;}
	pushdown(x),multiply(lson,l,mid,L,R,val),multiply(rson,mid+1,r,L,R,val),pushup(x);
}
void turnon(int x,int l,int r,int P){
	if(l>P||r<P)return;
	if(l==r){seg[x].sum=1ll*a[rev[P]]*seg[x].tag%mod;return;}
	pushdown(x),turnon(lson,l,mid,P),turnon(rson,mid+1,r,P),pushup(x);
}
int querytag(int x,int l,int r,int P){
	if(l>P||r<P)return 0;
	if(l==r)return seg[x].tag;
	pushdown(x);return querytag(lson,l,mid,P)+querytag(rson,mid+1,r,P);
}
int querysum(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R)return seg[x].sum;
	pushdown(x);return (querysum(lson,l,mid,L,R)+querysum(rson,mid+1,r,L,R))%mod;
}
vector<int>v[200100];
int tp[200100],pos[200100];
void dfs(int x){
	dfn[x]=++tot,rev[tot]=x,sz[x]=1;
	for(auto y:v[x])fa[y]=x,dfs(y),sz[x]+=sz[y];
}
int main(){
	scanf("%d%d",&a[n=1],&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&tp[i],&pos[i]);
		if(tp[i]==1)scanf("%d",&a[++n]),v[pos[i]].push_back(n),pos[i]=n;
	}
	for(int i=1;i<=n;i++)deg[i]=1;
	dfs(1),turnon(1,1,n,1);
	for(int i=1,x;i<=q;i++){
		if(tp[i]==1){
			x=fa[pos[i]];
			multiply(1,1,n,dfn[x],dfn[x]+sz[x]-1,1ll*(deg[x]+1)*ksm(deg[x])%mod),deg[x]++;
			turnon(1,1,n,dfn[pos[i]]);
		}else x=pos[i],printf("%d\n",1ll*querysum(1,1,n,dfn[x],dfn[x]+sz[x]-1)*(x==1?1:ksm(querytag(1,1,n,dfn[fa[x]])))%mod);
	}
	return 0;
}