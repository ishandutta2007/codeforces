// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

void my_assert(int message){
	if(!message){
		cerr<<"\n";
		while(1);
	}
}

const int N=200005;
const int M=30000005;

vector<pii> adj[N];
int p[N],n,q;

int sz[N],son[N],dep[N],dad[N];
ll dval[N],dsum[N],fuck[N];
void dfs1(int u,int fa){
	sz[u]=1,dep[u]=dep[fa]+1,dad[u]=fa;
	for(auto [v,w]:adj[u]){
		if(v==fa)continue;
		dval[v]=w;
		dsum[v]=dsum[u]+w;
		dfs1(v,u),sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
int bl[N],dfn[N],idfn[N],dtot;
void dfs2(int u,int topf){
	bl[u]=topf,dfn[u]=++dtot,idfn[dtot]=u;
	if(son[u])dfs2(son[u],topf);
	for(auto [v,w]:adj[u]){
		if(v==dad[u]||v==son[u])continue;
		dfs2(v,v);
	}
}

int rt[N];
int ls[M],rs[M],tag[M],tot,tmptot;
ll sum[M],pre[N];
void ins(int &u,int v,int l,int r,int ql,int qr,int dlt){
	my_assert(ql<=qr&&tot<M);
	if(u<=tmptot)u=++tot,ls[u]=ls[v],rs[u]=rs[v],sum[u]=sum[v],tag[u]=tag[v];
	else u=v;
	sum[u]+=1ll*(fuck[min(r,qr)]-fuck[max(l,ql)-1])*dlt;
	if(ql<=l&&r<=qr){tag[u]+=dlt;return;}
	int mid=l+r>>1;
	if(ql<=mid)ins(ls[u],ls[v],l,mid,ql,qr,dlt);
	if(qr>mid)ins(rs[u],rs[v],mid+1,r,ql,qr,dlt);
}	
ll query(int u,int l,int r,int ql,int qr){
	if(!u)return 0ll;
	if(ql<=l&&r<=qr)return sum[u];
	int mid=l+r>>1;
	ll carry=1ll*tag[u]*(fuck[min(r,qr)]-fuck[max(l,ql)-1]);
	if(ql<=mid)carry+=query(ls[u],l,mid,ql,qr);
	if(qr>mid)carry+=query(rs[u],mid+1,r,ql,qr);
	return carry;
}
ll query(int pos,int x){
	int u=x;
	ll ans=pre[pos]+1ll*dsum[x]*pos;
	while(u){
		ans-=2*query(rt[pos],1,n,dfn[bl[u]],dfn[u]);
		u=dad[bl[u]];
	}
	return ans;
}

void REMAKE(){
	while(tot){
		ls[tot]=rs[tot]=tag[tot]=sum[tot]=0;
		tot--;
	}
	rep(i,1,n){
		rt[i]=rt[i-1],pre[i]=pre[i-1]+dsum[p[i]];
		tmptot=tot;
		int u=p[i];
		while(u){
			ins(rt[i],rt[i],1,n,dfn[bl[u]],dfn[u],1);
			u=dad[bl[u]];
		}
	}
}

int main(){
	n=read(),q=read();
	rep(i,1,n)p[i]=read();
	rep(i,1,n-1){
		int u=read(),v=read(),w=read();
		adj[u].pb({v,w}),adj[v].pb({u,w});
	}
	dfs1(1,0),dfs2(1,1);
	rep(i,1,n)fuck[i]=fuck[i-1]+dval[idfn[i]];
	rep(i,1,n){
		rt[i]=rt[i-1],pre[i]=pre[i-1]+dsum[p[i]];
		tmptot=tot;
		int u=p[i];
		while(u){
			ins(rt[i],rt[i],1,n,dfn[bl[u]],dfn[u],1);
			u=dad[bl[u]];
		}
	}
	ll lastans=0;
	while(q--){
		int opt=read();
		if(opt==1){
			int l=read()^(lastans&((1<<30)-1));
			int r=read()^(lastans&((1<<30)-1));
			int x=read()^(lastans&((1<<30)-1));
			my_assert(l>=1&&l<=n&&r>=l&&r<=n&&x>=1&&x<=n);
			print(lastans=query(r,x)-query(l-1,x),'\n');
		}else{
			int x=read()^(lastans&((1<<30)-1));
			my_assert(x>=1&&x<n);
			rt[x]=rt[x-1],pre[x]=pre[x-1]+dsum[p[x+1]];
			swap(p[x],p[x+1]);
			tmptot=tot;
			int u=p[x];
			while(u){
				ins(rt[x],rt[x],1,n,dfn[bl[u]],dfn[u],1);
				u=dad[bl[u]];
			}
		}
		if(tot>28000000){
			REMAKE();
		}
	}
	return 0;
}