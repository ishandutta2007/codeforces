#include<bits/stdc++.h>
using namespace std;
int n,m,q,id[500100],S,cnt=1;
struct Suffix_Automaton{int ch[26],len,fa;}t[1100100];
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
char s[500100];
int anc[1100100][20];

#define mid ((l+r)>>1)
int rt[1100100],tot;
struct dat{
	int mx,pos;
	dat(int X=0,int Y=0){mx=X,pos=Y;}
	friend dat operator+(const dat&x,const dat&y){
		if(x.mx>y.mx)return x;
		if(x.mx<y.mx)return y;
		return x.pos<y.pos?x:y;
	}
};
struct SegTree{
	int lson,rson;
	dat val;
}seg[20010000];
void modify(int &x,int l,int r,int P){
	if(l>P||r<P)return;
	if(!x)x=++tot;
	if(l==r){seg[x].val.mx++,seg[x].val.pos=P;return;}
	modify(seg[x].lson,l,mid,P),modify(seg[x].rson,mid+1,r,P),seg[x].val=seg[seg[x].lson].val+seg[seg[x].rson].val;
}
dat query(int x,int l,int r,int L,int R){
	if(l>R||r<L||!x)return dat();
	if(L<=l&&r<=R)return seg[x].val;
	return query(seg[x].lson,l,mid,L,R)+query(seg[x].rson,mid+1,r,L,R);
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x+y;
	int z=++tot;
	if(l==r)seg[z].val=dat(seg[x].val.mx+seg[y].val.mx,l);
	else seg[z].val=seg[seg[z].lson=merge(seg[x].lson,seg[y].lson,l,mid)].val+seg[seg[z].rson=merge(seg[x].rson,seg[y].rson,mid+1,r)].val;
	return z;
}
vector<int>v[1100100];
void dfs(int x){for(auto y:v[x])dfs(y),rt[x]=merge(rt[x],rt[y],1,m);}
int substring(int l,int r){
	int x=id[r-1];
	for(int i=19;i>=0;i--)if(anc[x][i]&&t[anc[x][i]].len>=r-l+1)x=anc[x][i];
	return x;
}
int main(){
	scanf("%s",s),n=strlen(s);
	for(int i=0,las=1;i<n;i++)las=id[i]=Add(las,s[i]-'a');
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",s),S=strlen(s);
		for(int j=0,las=1;j<S;j++)modify(rt[las=Add(las,s[j]-'a')],1,m,i);
	}
	for(int i=2;i<=cnt;i++)v[anc[i][0]=t[i].fa].push_back(i);
	dfs(1);
	for(int j=1;j<=19;j++)for(int i=1;i<=cnt;i++)anc[i][j]=anc[anc[i][j-1]][j-1];
	scanf("%d",&q);
	for(int i=1,l,r,L,R;i<=q;i++){
		scanf("%d%d%d%d",&L,&R,&l,&r);
		int x=substring(l,r);
		dat tmp=query(rt[x],1,m,L,R);
		if(tmp.mx==0)printf("%d %d\n",L,0);
		else printf("%d %d\n",tmp.pos,tmp.mx);
	}
	return 0;
}