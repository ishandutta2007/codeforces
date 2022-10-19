#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,id[300100],S,val[300100];
struct AC_Automaton{
	int ch[26],fail;
}t[300100];
char s[300100];
int Add(){
	int x=1;
	for(int i=0;i<S;i++){
		if(!t[x].ch[s[i]-'a'])t[x].ch[s[i]-'a']=++cnt;
		x=t[x].ch[s[i]-'a'];
	}
	return x;
}
queue<int>q;
void buildAC(){
	for(int i=0;i<26;i++){
		if(t[1].ch[i])t[t[1].ch[i]].fail=1,q.push(t[1].ch[i]);
		else t[1].ch[i]=1;
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(t[x].ch[i])t[t[x].ch[i]].fail=t[t[x].fail].ch[i],q.push(t[x].ch[i]);
			else t[x].ch[i]=t[t[x].fail].ch[i];
		}
	}
}
multiset<int>st[300100];
vector<int>v[300100];
int fa[300100],son[300100],sz[300100],dep[300100],dfn[300100],rev[300100],top[300100],tot;
void dfs1(int x){
	sz[x]=1;
	for(auto y:v[x]){
		fa[y]=x,dep[y]=dep[x]+1;
		dfs1(y);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x){
	dfn[x]=++tot,rev[tot]=x;if(!top[x])top[x]=x;
	if(son[x])top[son[x]]=top[x],dfs2(son[x]);
	for(auto y:v[x])if(y!=son[x])dfs2(y);
}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int mx[1200100];
#define pushup mx[x]=max(mx[lson],mx[rson])
void build(int x,int l,int r){
	if(l==r){mx[x]=(st[rev[l]].empty()?-1:0);return;}
	build(lson,l,mid),build(rson,mid+1,r),pushup;
}
void reset(int x,int l,int r,int P){
	if(l>P||r<P)return;
	if(l==r){mx[x]=(st[rev[P]].empty()?-1:*st[rev[P]].rbegin());return;}
	reset(lson,l,mid,P),reset(rson,mid+1,r,P),pushup;
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return -1;
	if(L<=l&&r<=R)return mx[x];
	return max(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
int chainquery(int x){
	int ret=-1;
	while(x)ret=max(ret,query(1,1,cnt,dfn[top[x]],dfn[x])),x=fa[top[x]];
	return ret;
}
int solve(){
	int ret=-1,x=1;
	for(int i=0;i<S;i++){
		x=t[x].ch[s[i]-'a'];
		ret=max(ret,chainquery(x));
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s),S=strlen(s),st[id[i]=Add()].insert(0);
	buildAC();
	for(int i=2;i<=cnt;i++)v[t[i].fail].push_back(i);
	dfs1(1),dfs2(1);
	build(1,1,cnt);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d",&x);
		if(x==2)scanf("%s",s),S=strlen(s),printf("%d\n",solve());
		else scanf("%d%d",&y,&z),st[id[y]].erase(st[id[y]].find(val[y])),val[y]=z,st[id[y]].insert(val[y]),reset(1,1,cnt,dfn[id[y]]);
	}
	return 0;
}