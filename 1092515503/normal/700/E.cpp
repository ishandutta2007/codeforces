#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,rt[400100],f[400100],las[400100],pos[400100],res;
char s[200100];
struct Suffix_Automaton{int ch[26],len,fa;}t[400100];
int Add(int x,int c){
	int xx=++cnt;t[xx].len=t[x].len+1;
	for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
	if(!x){t[xx].fa=1;return xx;}
	int y=t[x].ch[c];
	if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
	int yy=++cnt;t[yy]=t[y],t[yy].len=t[x].len+1;
	t[xx].fa=t[y].fa=yy;
	for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
	return xx;
}

#define mid ((l+r)>>1)
int tot;
struct SegmentTree{
	int lson,rson;
}seg[20010000];
int merge(int x,int y){
	if(!x||!y)return x+y;
	int z=++tot;
	seg[z].lson=merge(seg[x].lson,seg[y].lson);
	seg[z].rson=merge(seg[x].rson,seg[y].rson);
	return z;
}
void modify(int &x,int l,int r,int P){
	if(l>P||r<P)return;
	if(!x)x=++tot;
	if(l!=r)modify(seg[x].lson,l,mid,P),modify(seg[x].rson,mid+1,r,P);
}
bool query(int x,int l,int r,int L,int R){
	if(l>R||r<L||!x)return false;
	if(L<=l&&r<=R)return true;
	return query(seg[x].lson,l,mid,L,R)|query(seg[x].rson,mid+1,r,L,R);
}

vector<int>v[400100];
void dfs1(int x){for(auto y:v[x])dfs1(y),rt[x]=merge(rt[x],rt[y]),pos[x]=pos[y];}
void dfs2(int x){
	res=max(res,f[x]);
	for(auto y:v[x]){
		if(query(rt[las[x]],0,n-1,pos[y]-t[y].len+t[las[x]].len,pos[y]-1))f[y]=f[x]+1,las[y]=y;
		else f[y]=f[x],las[y]=las[x];
		dfs2(y);
	}
}
int main(){
	scanf("%d%s",&n,s);
	for(int i=0,las=1;i<n;i++)las=Add(las,s[i]-'a'),modify(rt[las],0,n-1,i),pos[las]=i;
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	dfs1(1);
	for(auto y:v[1])f[y]=1,las[y]=y,dfs2(y);
	printf("%d\n",res);
	return 0;
}