#include<bits/stdc++.h>

#define maxn 100100
#define id(x,y) ((x)*2+(y))

using namespace std;

typedef pair<int,int> pii;

struct edge{int r,nxt;}e[maxn<<1];
struct data{
	int lc,rc,cnt;
	vector<int>v;
}s[maxn<<2];

int dy[maxn],anses[maxn],dep[maxn],ptr;
int Q[maxn],Qsz,bel[maxn],idsz,A[maxn],Asz;
int ai[maxn],rt[maxn],bi[maxn],ci[maxn],di[maxn];
int fa[maxn],dfn[maxn],son[maxn];
int n,m,head[maxn],top[maxn],rig[maxn],tim,esz,vis[maxn];

void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}

int dfs1(int u){
	int sz=1,s=0,mxsize=0;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u]){
		fa[e[t].r]=u,s=dfs1(e[t].r),sz+=s;
		if(mxsize<s)mxsize=s,son[u]=e[t].r;
	}
	return sz;
}

void dfs2(int u,int tp){
	top[u]=tp,dfn[u]=++tim,dep[u]=dep[fa[u]]+1;
	rig[tp]=max(rig[tp],tim);
	if(son[u])dfs2(son[u],tp);
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u]&&e[t].r!=son[u])
		dfs2(e[t].r,e[t].r);
}

void build(int& o,int l,int r){
	o=++ptr;
	if(l==r)return ;
	int mid=l+r>>1;
	build(s[o].lc,l,mid);
	build(s[o].rc,mid+1,r);
}

void ins(int o,int l,int r,int ql,int qr,int id,int flg){
	if(ql>qr)return ;
	s[o].cnt+=flg;

	if(ql<=l&&r<=qr){
		if(flg==1)s[o].v.push_back(id);//,printf("ins:{%d}",id);
		return ;
	}
	int mid=l+r>>1;
	if(ql<=mid)ins(s[o].lc,l,mid,ql,qr,id,flg);
	if(qr>mid)ins(s[o].rc,mid+1,r,ql,qr,id,flg);
}

void instree(int u,int v,int id,int flg){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		ins(rt[top[u]],dfn[top[u]],rig[top[u]],dfn[top[u]],dfn[u],id,flg);
		u=fa[top[u]];
	}
	if(dfn[u]>dfn[v])swap(u,v);
	ins(rt[top[u]],dfn[top[u]],rig[top[u]],dfn[u]+1,dfn[v],id,flg);
}

void init(int flg){
	for(int i=1;i<=ptr;++i)
		s[i].v.clear(),s[i].cnt=0;
	for(int i=1;i<=m;++i){
		if(flg==0){
			instree(ai[i],bi[i],id(i,1),1);
			instree(ci[i],di[i],id(i,0),1);	
		} else {
			instree(ai[i],bi[i],id(i,0),1);
			instree(ci[i],di[i],id(i,1),1);
		}
	}
}

int qry(int o,int l,int r,int ql,int qr){
	if(!s[o].cnt)return -1;
	if(ql>qr)return -1;
	while(s[o].v.size()){
		int x=s[o].v.back();
		if(!vis[x])return x;
		else s[o].v.pop_back();
	}
	int mid=l+r>>1,ret=-1;
	if(ql<=mid)ret=qry(s[o].lc,l,mid,ql,qr);
	if(qr>mid&&ret==-1)ret=qry(s[o].rc,mid+1,r,ql,qr);
	return ret;
}

int qtree(int fr,int flg){
	int u,v;
	if(fr%2==flg)u=ai[fr>>1],v=bi[fr>>1];
	else u=ci[fr>>1],v=di[fr>>1];	
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		int x=qry(rt[top[u]],dfn[top[u]],rig[top[u]],dfn[top[u]],dfn[u]);
		if(x!=-1)return x;
		u=fa[top[u]];
	}
	if(dfn[u]>dfn[v])swap(u,v);
	int x=qry(rt[top[u]],dfn[top[u]],rig[top[u]],dfn[u]+1,dfn[v]);
	return x;
}

void era(int fr,int flg){
	vis[fr]=1;
	int u,v;
	if(fr%2==!flg)u=ai[fr>>1],v=bi[fr>>1];
	else u=ci[fr>>1],v=di[fr>>1];
	instree(u,v,fr,-1);
}

void _ins(int fr,int flg){
	vis[fr]=0;
	int u,v;
	if(fr%2==!flg)u=ai[fr>>1],v=bi[fr>>1];
	else u=ci[fr>>1],v=di[fr>>1];
	instree(u,v,fr,1);
}

void dfs(int u,int flg=0){
	if(flg==1)bel[u]=idsz,A[++Asz]=u;
	vis[u]=1,era(u,flg);
	while(true){
		if(vis[u^1]){
			int nxt=qtree(u,flg);
			if(nxt!=-1)dfs(nxt,flg);
			else break;
		} else {
			era(u^1,flg);
			int nxt=qtree(u,flg);
			_ins(u^1,flg);
			if(nxt!=-1)dfs(nxt,flg);
			else break;
		}
	}
	if(flg==0)Q[++Qsz]=u;
}

int main(){
	cin>>n;
	for(int i=2,u,v;i<=n;++i){
		cin>>u>>v;
		addedge(u,v);
	}
	cin>>m;
	for(int i=1;i<=m;++i)
		cin>>ai[i]>>bi[i]>>ci[i]>>di[i];
	dfs1(1),dfs2(1,1);
	for(int i=1;i<=n;++i)if(top[i]==i)
		build(rt[i],dfn[i],rig[i]);
	init(0);
	for(int i=id(1,0);i<=id(m,1);++i)
             if(!vis[i])
                dfs(i);
	init(1);
	memset(vis,0,sizeof(vis));
	for(int i=Qsz;i>=1;--i)
           if(!vis[Q[i]])
               ++idsz,dfs(Q[i],1);
	for(int i=1;i<=m;++i)
            if(bel[id(i,0)]==bel[id(i,1)])
               return cout<<"NO",0;
	cout<<"YES"<<endl;
	for(int i=Asz;i>=1;--i)
            if(!dy[A[i]]){
		dy[A[i]]=dy[A[i]^1]=1;
		anses[A[i]>>1]=(A[i]%2==0?1:2);
	}
	for(int i=1;i<=m;++i)
            cout<<anses[i]<<endl;
}