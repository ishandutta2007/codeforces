#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,m,num[200100],t1,t2,t3;
struct node{
	int tag,mn;
}seg[1001001];
void pushup(int x){
	seg[x].mn=min(seg[lson].mn,seg[rson].mn);
}
void pushdown(int x){
	seg[lson].mn+=seg[x].tag,seg[lson].tag+=seg[x].tag;
	seg[rson].mn+=seg[x].tag,seg[rson].tag+=seg[x].tag;
	seg[x].tag=0;
}
void build(int x,int l,int r){
	if(l==r){seg[x].mn=seg[x].tag=num[l];return;}
	build(lson,l,mid),build(rson,mid+1,r),pushup(x);
}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){seg[x].mn+=val,seg[x].tag+=val;return;}
	pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0x3f3f3f3f;
	if(L<=l&&r<=R)return seg[x].mn;
	pushdown(x);
	return min(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
bool read(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0')f=(c=='-'?-f:f),c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=f;
	return c!='\n';
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
	build(1,1,n);
	scanf("%lld",&m);
	while(m--){
		read(t1);
		if(read(t2)){
			read(t3);
			if(t2>=t1)modify(1,1,n,t1+1,t2+1,t3);
			else modify(1,1,n,1,t2+1,t3),modify(1,1,n,t1+1,n,t3);
		}else{
			if(t2>=t1)printf("%lld\n",query(1,1,n,t1+1,t2+1));
			else printf("%lld\n",min(query(1,1,n,1,t2+1),query(1,1,n,t1+1,n)));
		}
	}
	return 0;
}
/*
4
1 2 3 4
4
3 0
3 0 -1
0 1
2 1
*/