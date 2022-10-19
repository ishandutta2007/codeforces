#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,m;
struct SegTree{
int ls[2],rs[2],ms[2],P[2],Q[2],L[2],R[2],sum[2];
bool rev;
void REV(){
	swap(ls[0],ls[1]),swap(rs[0],rs[1]),swap(ms[0],ms[1]),swap(sum[0],sum[1]);
	swap(P[0],P[1]),swap(Q[0],Q[1]),swap(L[0],L[1]),swap(R[0],R[1]),rev^=1;
}
friend SegTree operator+(const SegTree&u,const SegTree&v){
	SegTree w;w.rev=false;
	for(int t=0;t<2;t++){
		w.ms[t]=w.ls[t]=w.rs[t]=w.P[t]=w.Q[t]=w.L[t]=w.R[t]=-1;
		w.sum[t]=u.sum[t]+v.sum[t];
		if(u.ms[t]>w.ms[t])w.ms[t]=u.ms[t],w.P[t]=u.P[t],w.Q[t]=u.Q[t];
		if(v.ms[t]>w.ms[t])w.ms[t]=v.ms[t],w.P[t]=v.P[t],w.Q[t]=v.Q[t];
		if(u.rs[t]>=0&&v.ls[t]>=0&&u.rs[t]+v.ls[t]>w.ms[t])
			w.ms[t]=u.rs[t]+v.ls[t],w.P[t]=u.R[t],w.Q[t]=v.L[t];
			
		if(u.ls[t]>=0&&u.ls[t]>w.ls[t])w.ls[t]=u.ls[t],w.L[t]=u.L[t];
		if(v.ls[t]>=0&&u.sum[t]+v.ls[t]>w.ls[t])w.ls[t]=u.sum[t]+v.ls[t],w.L[t]=v.L[t];
			
		if(v.rs[t]>=0&&v.rs[t]>w.rs[t])w.rs[t]=v.rs[t],w.R[t]=v.R[t];
		if(u.rs[t]>=0&&v.sum[t]+u.rs[t]>w.rs[t])w.rs[t]=v.sum[t]+u.rs[t],w.R[t]=u.R[t];
	}
	return w;
}
void print()const{
	for(int t=0;t<2;t++)
		printf("%d:%d][%d,%d:%d][%d:%d ||%d\n",L[t],ls[t],P[t],Q[t],ms[t],R[t],rs[t],sum[t]);
}
}seg[400100];
void pushdown(int x){if(seg[x].rev)seg[lson].REV(),seg[rson].REV(),seg[x].rev=false;}
void build(int x,int l,int r){
	if(l==r){
		scanf("%d",&seg[x].sum[0]),seg[x].sum[1]=-seg[x].sum[0];
		for(int t=0;t<2;t++)
			if(seg[x].sum[t]>=0)seg[x].ms[t]=seg[x].ls[t]=seg[x].rs[t]=seg[x].sum[t],
				seg[x].P[t]=seg[x].Q[t]=seg[x].L[t]=seg[x].R[t]=l;
			else seg[x].ms[t]=seg[x].ls[t]=seg[x].rs[t]=-1,
				seg[x].P[t]=seg[x].Q[t]=seg[x].L[t]=seg[x].R[t]=-1;
	}else build(lson,l,mid),build(rson,mid+1,r),seg[x]=seg[lson]+seg[rson];
//	printf("%d[%d,%d]\n",x,l,r);seg[x].print();
}
void reset(int x,int l,int r,int P){
	if(l==r){
		scanf("%d",&seg[x].sum[0]),seg[x].sum[1]=-seg[x].sum[0];
		for(int t=0;t<2;t++)
			if(seg[x].sum[t]>=0)seg[x].ms[t]=seg[x].ls[t]=seg[x].rs[t]=seg[x].sum[t],
				seg[x].P[t]=seg[x].Q[t]=seg[x].L[t]=seg[x].R[t]=l;
			else seg[x].ms[t]=seg[x].ls[t]=seg[x].rs[t]=-1,
				seg[x].P[t]=seg[x].Q[t]=seg[x].L[t]=seg[x].R[t]=-1;
	}else P<=mid?reset(lson,l,mid,P):reset(rson,mid+1,r,P),seg[x]=seg[lson]+seg[rson];
}
void inverse(int x,int l,int r,int L,int R){
	if(l>R||r<L)return;
	if(L<=l&&r<=R)return seg[x].REV();
	pushdown(x),inverse(lson,l,mid,L,R),inverse(rson,mid+1,r,L,R),seg[x]=seg[lson]+seg[rson];
}
SegTree query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return seg[x];
	pushdown(x);
	if(R<=mid)return query(lson,l,mid,L,R);
	if(mid+1<=L)return query(rson,mid+1,r,L,R);
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}
vector<pair<int,int> >v;
int main(){
	scanf("%d",&n),build(1,1,n),scanf("%d",&m);
	for(int i=1,tp,l,r,x;i<=m;i++){
		scanf("%d",&tp);
		if(tp==0)scanf("%d",&x),reset(1,1,n,x);
		else{
			scanf("%d%d%d",&l,&r,&x);int sum=0;
			SegTree s=query(1,1,n,l,r);
			while(s.ms[0]>0&&x--){
//				printf("[%d,%d]:%d\n",s.P[0],s.Q[0],s.ms[0]);
				sum+=s.ms[0];
				v.emplace_back(s.P[0],s.Q[0]);
				inverse(1,1,n,s.P[0],s.Q[0]);
				s=query(1,1,n,l,r);
			}
			printf("%d\n",sum);
			for(auto k:v)inverse(1,1,n,k.first,k.second);
			v.clear();
		}
	}
	return 0;
}