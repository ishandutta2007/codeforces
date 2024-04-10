#include<bits/stdc++.h>
using namespace std;
int n,m,id[400100],cnt=1;
struct Suffix_Automaton{
	int ch[26],fa,len;
}t[800100];
int Add(int x,int c){
	if(t[x].ch[c]){
		int y=t[x].ch[c];
		if(t[y].len==t[x].len+1)return y;//(x,c) has been added into the tree already.
		int yy=++cnt;t[yy]=t[y];
		t[yy].len=t[x].len+1,t[y].fa=yy;
		for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
		return yy;
	}
	int xx=++cnt;t[xx].len=t[x].len+1;
	for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
	if(!x){t[xx].fa=1;return xx;}
	int y=t[x].ch[c];
	if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
	int yy=++cnt;t[yy]=t[y];
	t[yy].len=t[x].len+1;
	t[y].fa=t[xx].fa=yy;
	for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
	return xx;
}
char s[400100];
int pos[400100],stt[400100],len[400100],res[400100];
vector<int>q[400100],v[800100],g[400100];
int dfn[800100],rev[800100],sz[800100],tot;
void dfs(int x){dfn[x]=++tot,rev[tot]=x,sz[x]=1;for(auto y:v[x])dfs(y),sz[x]+=sz[y];}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int sum[3200100];
void modify(int x,int l,int r,int P,int val){
	if(l>P||r<P)return;
	sum[x]+=val;
	if(l!=r)modify(lson,l,mid,P,val),modify(rson,mid+1,r,P,val);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R)return sum[x];
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}
void solve(int ip){
	int x=1;
	for(int i=stt[ip];i<stt[ip+1];i++){
		if(!t[x].ch[s[i]-'a'])return;
		x=t[x].ch[s[i]-'a'];
	}
	res[ip]=query(1,1,tot,dfn[x],dfn[x]+sz[x]-1);
}
void dfs2(int x){
	modify(1,1,tot,dfn[id[x]],1);
	for(auto i:q[x])solve(i);
	for(auto i:g[x])dfs2(i);
	modify(1,1,tot,dfn[id[x]],-1);
}
int main(){
	scanf("%d",&n),id[0]=1;
	for(int i=1,a,b;i<=n;i++){
		scanf("%d",&a);
		if(a==1)scanf("%s",s),b=0;
		else scanf("%d%s",&b,s);
		id[i]=Add(id[b],s[0]-'a');
		g[b].push_back(i);
	}
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	dfs(1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%s",&pos[i],s+stt[i]),stt[i+1]=stt[i]+(len[i]=strlen(s+stt[i])),q[pos[i]].push_back(i);
	dfs2(0);
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}