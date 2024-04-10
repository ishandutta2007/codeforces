#include<bits/stdc++.h>
using namespace std;
#define lson (x<<1)
#define rson (x<<1|1)
#define mid ((l+r)>>1)
int n,m,a[100001],b[100001],tag[400001],t1,t2,t3,t4;
void pushdown(int x,int l,int r){
	if(!tag[x])return;
	tag[lson]=tag[x],tag[rson]=mid+1-l+tag[x],tag[x]=0;
}
void modify(int x,int l,int r,int pos1,int pos2,int len){
	if(r<pos1||l>pos1+len-1)return;
//	printf("%d %d %d\n",x,l,r); 
	if(pos1<=l&&r<=pos1+len-1){tag[x]=pos2-pos1+l/*,printf("%d\n",pos2-pos1+l)*/;return;}
	pushdown(x,l,r),modify(lson,l,mid,pos1,pos2,len),modify(rson,mid+1,r,pos1,pos2,len);
}
int query(int x,int l,int r,int pos){
//	printf("%d:(%d %d):%d\n",x,l,r,tag[x]);
	if(pos>r||pos<l)return 0;
	if(l==r)return tag[x]?a[tag[x]]:b[l];
	pushdown(x,l,r);
	return query(lson,l,mid,pos)+query(rson,mid+1,r,pos);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	while(m--){
		scanf("%d",&t1);
		if(t1==1)scanf("%d%d%d",&t2,&t3,&t4),modify(1,1,n,t3,t2,t4);
		if(t1==2)scanf("%d",&t2),printf("%d\n",query(1,1,n,t2));
	}
	return 0;
}