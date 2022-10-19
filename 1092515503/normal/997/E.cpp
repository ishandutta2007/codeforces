#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define lson (x<<1)
#define rson (x<<1|1)
#define mid ((l+r)>>1)
#define fi first
#define se second
int n,q,num[500011],ans[500011],mx,mn,cur,res[500011],idx[500011];
pii& operator +=(pii &x,const int &y){
	x.fi+=y;
	return x;
}
pii operator +(const pii &x,const pii &y){
	pii z=make_pair(min(x.fi,y.fi),0ll);
	if(z.fi==x.fi)z.se+=x.se;
	if(z.fi==y.fi)z.se+=y.se;
	return z;
}
struct node{
	int l,r,ord;
}p[500011];
struct Node{
	pii val;
	int tag1,tag2,cnt;
}seg[2000011];
void pushup(int x){
	seg[x].cnt=seg[lson].cnt+seg[rson].cnt;
	seg[x].val=seg[lson].val+seg[rson].val;
}
void update1(int x,int val){
	seg[x].val+=val;
	seg[x].tag1+=val;
}
void update2(int x,int val){
	seg[x].cnt+=seg[x].val.se*val;
	seg[x].tag2+=val;
}
void pushdown(int x){
	update1(lson,seg[x].tag1),update1(rson,seg[x].tag1),seg[x].tag1=0;
	if(seg[x].val.fi==seg[lson].val.fi)update2(lson,seg[x].tag2);
	if(seg[x].val.fi==seg[rson].val.fi)update2(rson,seg[x].tag2);
	seg[x].tag2=0;
}
void build(int x,int l,int r){
	seg[x].val=make_pair(0,1);
	if(l==r)return;
	build(lson,l,mid),build(rson,mid+1,r),pushup(x);
}
void modify1(int x,int l,int r,int L,int R,int val){
	if(r<L||l>R)return;
	if(L<=l&&r<=R){update1(x,val);return;}
	pushdown(x),modify1(lson,l,mid,L,R,val),modify1(rson,mid+1,r,L,R,val),pushup(x);
}
void modify2(int x,int l,int r,int L,int R,int val){
	if(r<L||l>R||seg[x].val.fi>1)return;
	if(L<=l&&r<=R){update2(x,val);return;}
	pushdown(x),modify2(lson,l,mid,L,R,val),modify2(rson,mid+1,r,L,R,val),pushup(x);
}
int query(int x,int l,int r,int L,int R){
	if(r<L||l>R)return 0;
	if(L<=l&&r<=R)return seg[x].cnt;
	pushdown(x);
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}
bool cmp(node p1,node p2){
	return p1.r<p2.r;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]),idx[num[i]]=i;
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)scanf("%lld%lld",&p[i].l,&p[i].r),p[i].ord=i;
	sort(p+1,p+q+1,cmp),build(1,1,n);
	for(int i=1,k=1;i<=n;i++){
		modify1(1,1,n,1,i,1);
		if(num[i]>1&&idx[num[i]-1]<i)modify1(1,1,n,1,idx[num[i]-1],-1);
		if(num[i]<n&&idx[num[i]+1]<i)modify1(1,1,n,1,idx[num[i]+1],-1);
		modify2(1,1,n,1,i,1);
		while(p[k].r<i&&k<=q)k++;
		while(p[k].r==i&&k<=q)res[p[k].ord]=query(1,1,n,p[k].l,i),k++;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",res[i]);
	return 0;
}