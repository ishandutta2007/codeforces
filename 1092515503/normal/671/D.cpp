#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,dep[300100],lim;
vector<int>v[300100];
void dfs1(int x,int fa){lim=max(lim,dep[x]=dep[fa]+1);for(auto y:v[x])if(y!=fa)dfs1(y,x);}
vector<pair<int,int> >u[300100];
#define lson seg[x].ch[0]
#define rson seg[x].ch[1]
#define mid ((l+r)>>1)
int rt[300100],cnt,bin[6001000],tp;
struct SegTree{int ch[2];ll mn,tag;SegTree(){ch[0]=ch[1]=tag=0,mn=inf;}}seg[6001000];
void destroy(int&x){seg[x].mn=inf,seg[x].tag=0,bin[++tp]=x,x=0;}
void abandon(int&x){if(x)abandon(lson),abandon(rson),destroy(x);}
void ADD(int&x,ll y){
	if(!x)return;
	if(y>=inf)abandon(x);
	else seg[x].mn+=y,seg[x].tag+=y;
}
void pushdown(int&x){ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;}
void pushup(int&x){
	if(!lson&&!rson)return destroy(x);
	seg[x].mn=min(seg[lson].mn,seg[rson].mn);
}
void modify(int&x,int l,int r,int P,ll val){
	if(!x)x=(tp?bin[tp--]:++cnt);
	seg[x].mn=min(seg[x].mn,val);
	if(l!=r)pushdown(x),P<=mid?modify(lson,l,mid,P,val):modify(rson,mid+1,r,P,val);
}
void erase(int&x,int l,int r,int P){
	if(!x)return;
	if(l==r)destroy(x);
	else pushdown(x),P<=mid?erase(lson,l,mid,P):erase(rson,mid+1,r,P),pushup(x);
}
void merge(int&x,int&y,int l,int r,ll X,ll Y){
	if(!y)return ADD(x,Y);
	if(!x){swap(y,x),ADD(x,X);return;}
	if(l==r){
		X=min(X,seg[x].mn),Y=min(Y,seg[y].mn);
		ADD(x,Y),ADD(y,X);
		seg[x].mn=min(seg[x].mn,seg[y].mn);
		if(y)destroy(y);
		return;
	}
	pushdown(x),pushdown(y);
	merge(lson,seg[y].ch[0],l,mid,min(X,seg[seg[x].ch[1]].mn),min(Y,seg[seg[y].ch[1]].mn));
	merge(rson,seg[y].ch[1],mid+1,r,X,Y);
	pushup(x);
	if(y)destroy(y);
}
ll query(int x,int l,int r,int L,int R){
	if(l>R||r<L||!x)return inf;
	if(L<=l&&r<=R)return seg[x].mn;
	pushdown(x);
	return min(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
/*void iterate(int x,int l,int r){
	if(!x)return;
	if(l==r)printf("[%d:%lld]",l,seg[x].mn);
	pushdown(x),iterate(lson,l,mid),iterate(rson,mid+1,r);
}*/
void dfs2(int x,int fa){
	modify(rt[x],1,lim,dep[x],0);
	for(auto y:v[x])if(y!=fa)
		dfs2(y,x),erase(rt[y],1,lim,dep[y]),merge(rt[x],rt[y],1,lim,inf,inf);
	for(auto i:u[x]){
		ll tmp=query(rt[x],1,lim,i.first,dep[x]);
		if(tmp>=inf)continue;
		modify(rt[x],1,lim,i.first,tmp+i.second);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs1(1,0);
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),u[x].emplace_back(dep[y],z);
	dfs2(1,0);
	printf("%lld\n",seg[rt[1]].mn>=inf?-1:seg[rt[1]].mn);
	return 0;
}