#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x0f0f0f0f0f0f0f0f;
int n,K,g[100100],w[100100],res;
ll pre[100100],suf[100100];
vector<int>v[100100];
int nex[100100],stk[100100],tp;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
#define X x,l,r
#define LSON lson,l,mid
#define RSON rson,mid+1,r
struct SegTree{ll msf,mn,tag,rmn;}seg[400100];
void ADD(int x,ll y){seg[x].mn+=y,seg[x].tag+=y,seg[x].rmn-=y;}
void pushdown(int x){ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;}
ll pushup(int x,int l,int r,ll mn){
	if(l==r)return seg[x].msf-mn;
	pushdown(x);
	if(mn<=seg[lson].mn)return min(seg[lson].msf-mn,pushup(RSON,mn));
	return min(pushup(LSON,mn),seg[x].rmn);
}
void pushup(int x,int l,int r){
	seg[x].mn=min(seg[lson].mn,seg[rson].mn);
	seg[x].rmn=pushup(RSON,seg[lson].mn);
}
void build(int x,int l,int r){
	if(l==r){seg[x].msf=seg[x].mn=suf[l];return;}
	build(LSON),build(RSON),seg[x].msf=min(seg[lson].msf,seg[rson].msf),pushup(X);
}
int retrieve(int x,int l,int r,ll mn){
	if(l==r){return seg[x].msf-mn<=K?l:-1;}pushdown(x);
	return seg[rson].msf-mn<=K?retrieve(RSON,mn):retrieve(LSON,mn);
}
int query(int x,int l,int r,ll mn){
//	printf("QUERY%d[%d,%d]%lld\n",x,l,r,mn);
	if(l==r){return seg[x].msf-mn<=K?l:-1;}
	pushdown(x);
	if(mn<=seg[lson].mn){
		int ret=query(RSON,mn);
		if(ret!=-1)return ret;
		return retrieve(LSON,mn);
	}
	if(seg[x].rmn<=K)return query(RSON,seg[lson].mn);
	return query(LSON,mn);
}
void modify(int x,int l,int r,int P,ll val){
	if(r<P)return;if(l>=P)return ADD(x,val);
	pushdown(x),modify(LSON,P,val),modify(RSON,P,val),pushup(X);
}
void iterate(int x,int l,int r){
	if(l==r)printf("%lld ",seg[x].mn);
	else pushdown(x),iterate(lson,l,mid),iterate(rson,mid+1,r);
}
ll sum[100100];
void dfs(int x){
	stk[++tp]=x;
	for(auto y:v[x]){
		modify(1,1,n,x-1,pre[y]-pre[x]);
		sum[y]=sum[x]+pre[x]-pre[y];
		int l=1,r=tp;
		while(l<r){
			int md=(l+r+1)>>1;
			if(sum[y]-sum[stk[md]]>K)l=md;else r=md-1;
		}
//		printf("%d:%d\n",y,stk[l]);
		modify(1,1,n,1,inf);
		modify(1,1,n,y,-inf);
		modify(1,1,n,stk[l]-1,-inf);
//		iterate(1,1,n),puts("");
		res=max(res,query(1,1,n,inf)-y+1);
		modify(1,1,n,stk[l]-1,inf);
		modify(1,1,n,y,inf);
		modify(1,1,n,1,-inf);
		dfs(y);
		modify(1,1,n,x-1,pre[x]-pre[y]);
	}
	tp--;
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)scanf("%d",&g[i]);
	for(int i=2;i<=n;i++)pre[i]=pre[i-1]+w[i-1]-g[i-1],suf[i]=suf[i-1]+w[i-1]-g[i];
//	for(int i=1;i<=n;i++)printf("%lld ",pre[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%lld ",suf[i]);puts("");
	build(1,1,n);
	for(int i=1;i<=n;i++){
		while(tp&&pre[stk[tp]]<pre[i])nex[stk[tp--]]=i;
		stk[++tp]=i;
	}
	while(tp)nex[stk[tp--]]=n+1;
	for(int i=1;i<=n;i++)v[nex[i]].push_back(i);
//	for(int i=1;i<=n;i++)printf("%d ",nex[i]);puts("");
	dfs(n+1);
	printf("%d\n",res);
	return 0;
}