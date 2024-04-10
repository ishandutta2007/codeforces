#include<bits/stdc++.h>
using namespace std;
int n,m,c,q,U[500100],V[500100],nex[500100],las[500100],id[500100],col[500100];
bool res[500100];

struct dat{int u,v,lu,lv;bool ru,rv;dat(int a,int b,int c,int d,bool e,bool f){u=a,v=b,lu=c,lv=d,ru=e,rv=f;}};
struct UFS{
	int dsu[500100],len[500100];
	bool rev[500100];
	stack<dat>s;
	void init(){for(int i=1;i<=n;i++)dsu[i]=i;}
	int findfa(int x){return dsu[x]==x?x:findfa(dsu[x]);}
	bool findcol(int x){return dsu[x]==x?rev[x]:findcol(dsu[x])^rev[x];}
	bool merge(int u,int v){
		bool cu=findcol(u),cv=findcol(v);
		u=findfa(u),v=findfa(v);
		if(u==v)return false;
		if(len[u]>len[v])swap(u,v),swap(cu,cv);
		s.push(dat(u,v,len[u],len[v],rev[u],rev[v]));
		len[v]=max(len[v],len[u]+1),dsu[u]=v,rev[u]^=(cu==cv);
		return true;
	}
	bool ask(int u,int v){return findfa(u)!=findfa(v)||findcol(u)!=findcol(v);}
	void undo(){
		dsu[s.top().u]=s.top().u,len[s.top().u]=s.top().lu,rev[s.top().u]=s.top().ru;
		dsu[s.top().v]=s.top().v,len[s.top().v]=s.top().lv,rev[s.top().v]=s.top().rv;
		s.pop();
	}	
}t[51];

#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
vector<int>v[2001000];
void modify(int x,int l,int r,int L,int R,int k){if(l>R||r<L)return;if(L<=l&&r<=R)v[x].push_back(k);else modify(lson,l,mid,L,R,k),modify(rson,mid+1,r,L,R,k);}
void solve(int x,int l,int r){
//	printf("%d[%d,%d]\n",x,l,r);
	vector<int>u;
	for(auto i:v[x])if(t[col[i]].merge(U[id[i]],V[id[i]]))u.push_back(col[i]);
	if(l==r){
		if(t[col[l]].ask(U[id[l]],V[id[l]]))res[l]=true,modify(1,1,q,l+1,nex[l]-1,l);
		else{
			res[l]=false;
			if(las[l])modify(1,1,q,l+1,nex[l]-1,las[l]);
			if(nex[l]<=q)las[nex[l]]=las[l];
		}
	}else solve(lson,l,mid),solve(rson,mid+1,r);
	for(auto i:u)t[i].undo();
}
int main(){
	scanf("%d%d%d%d",&n,&m,&c,&q);
	for(int i=1;i<=c;i++)t[i].init();
	for(int i=1;i<=m;i++)scanf("%d%d",&U[i],&V[i]);
	for(int i=1;i<=q;i++)scanf("%d%d",&id[i],&col[i]),nex[las[id[i]]]=i,las[id[i]]=i;
	memset(las,0,sizeof(las));for(int i=1;i<=q;i++)if(!nex[i])nex[i]=q+1;else las[nex[i]]=i;
	solve(1,1,q);
	for(int i=1;i<=q;i++)puts(res[i]?"YES":"NO");
	return 0;
}
/*
4 4 2 4
1 3
3 4
2 4
1 4

2 2
3 2
1 2
4 2
*/