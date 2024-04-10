#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p[300100],q[301000];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{
	int tag,mn,num;
	SegTree(){tag=mn=num=0;} 
	friend SegTree operator+(const SegTree&u,const SegTree&v){
		SegTree w;w.mn=min(u.mn,v.mn);
		if(w.mn==u.mn)w.num+=u.num;
		if(w.mn==v.mn)w.num+=v.num;
		return w;
	}
}seg[1200100];
void ADD(int x,int y){seg[x].tag+=y,seg[x].mn+=y;}
void pushdown(int x){ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;}
void build(int x,int l,int r){
	seg[x].num=r-l+1;
	if(l!=r)build(lson,l,mid),build(rson,mid+1,r); 
}
void modify(int x,int l,int r,int P,int val){
	if(l>P)return;if(r<=P)return ADD(x,val);
	pushdown(x),modify(lson,l,mid,P,val),modify(rson,mid+1,r,P,val);
	seg[x]=seg[lson]+seg[rson];
}
SegTree query(int x,int l,int r,int P){
	if(r<=P)return seg[x];
	pushdown(x);
	return P<=mid?query(lson,l,mid,P):seg[lson]+query(rson,mid+1,r,P);
}
ll res;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)scanf("%d%d",&x,&y),p[x]=y,q[y]=x;
	build(1,1,n);
	for(int i=1;i<=n;i++){
		modify(1,1,n,i,1);
		if(p[i]<n&&q[p[i]+1]<i)modify(1,1,n,q[p[i]+1],-1);
		if(p[i]>1&&q[p[i]-1]<i)modify(1,1,n,q[p[i]-1],-1);
		res+=query(1,1,n,i).num;
	}
	printf("%lld\n",res);
	return 0;
}