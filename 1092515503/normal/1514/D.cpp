#include<bits/stdc++.h>
using namespace std;
int n,m,a[300100];
struct SegTree{
	int val,tms;
	SegTree(int X=1,int Y=0){val=X,tms=Y;}
	friend SegTree operator+(const SegTree&u,const SegTree&v){
		if(u.val==v.val)return SegTree(u.val,u.tms+v.tms);
		if(u.tms>=v.tms)return SegTree(u.val,u.tms-v.tms);
		return SegTree(v.val,v.tms-u.tms);
	}
}seg[1200100];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
void build(int x,int l,int r){if(l==r)seg[x]=SegTree(a[l],1);else build(lson,l,mid),build(rson,mid+1,r),seg[x]=seg[lson]+seg[rson];}
SegTree query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return SegTree();
	if(L<=l&&r<=R)return seg[x];
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}
vector<int>v[300100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v[a[i]].push_back(i);
	build(1,1,n);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		int col=query(1,1,n,l,r).val;
		int tms=upper_bound(v[col].begin(),v[col].end(),r)-lower_bound(v[col].begin(),v[col].end(),l);
		int smt=(r-l+1)-tms;
		printf("%d\n",1+max(0,tms-(smt+1)));
	}
	return 0;
}