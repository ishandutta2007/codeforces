#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100100],b[100100],rt[100100],cnt,m;
vector<int>v[100100],u;
ll res[100100];
#define mid ((l+r)>>1)
struct Line{int k;ll b;Line(){k=0,b=0x3f3f3f3f3f3f3f3f;}Line(int K,ll B){k=K,b=B;}ll f(int x){return 1ll*k*x+b;}};
struct SegTree{int lson,rson;Line l;}seg[8001000];
void modify(int &x,int l,int r,Line L){
	if(!x)x=++cnt;
	if(seg[x].l.f(u[mid])>L.f(u[mid]))swap(L,seg[x].l);
	if(seg[x].l.f(u[l])>L.f(u[l]))modify(seg[x].lson,l,mid,L);
	if(seg[x].l.f(u[r])>L.f(u[r]))modify(seg[x].rson,mid+1,r,L);
}
void merge(int &x,int y,int l,int r){
	if(!x){x=y;return;}if(!y)return;
	if(l!=r)merge(seg[x].lson,seg[y].lson,l,mid),merge(seg[x].rson,seg[y].rson,mid+1,r);
	modify(x,l,r,seg[y].l);
}
ll query(int x,int l,int r,int P){
	if(l>P||r<P||!x)return 0x3f3f3f3f3f3f3f3f;
	ll ret=seg[x].l.f(u[P]);
	if(l!=r)ret=min(ret,min(query(seg[x].lson,l,mid,P),query(seg[x].rson,mid+1,r,P)));
	return ret;
}
void dfs(int x,int fa){
	for(auto y:v[x])if(y!=fa)dfs(y,x),merge(rt[x],rt[y],0,m-1);
	if(v[x].size()==1&&x!=1)res[x]=0;
	else res[x]=query(rt[x],0,m-1,a[x]);
	modify(rt[x],0,m-1,Line(b[x],res[x]));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),u.push_back(a[i]);
	sort(u.begin(),u.end()),u.resize(m=unique(u.begin(),u.end())-u.begin());
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),a[i]=lower_bound(u.begin(),u.end(),a[i])-u.begin();
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",res[i]);puts("");
	return 0;
}