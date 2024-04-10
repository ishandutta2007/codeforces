#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,m,val[200100],res;
vector<pair<int,int> >v[200100];
inline void read(int &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
inline void print(int x){
	if(x<=9)putchar('0'+x);
	else print(x/10),putchar('0'+x%10);
}
struct SegTree{
	int mx,tag;
}seg[800100];
void pushup(int x){
	seg[x].mx=max(seg[lson].mx,seg[rson].mx);
}
void ADD(int x,int y){
	seg[x].tag+=y,seg[x].mx+=y;
}
void pushdown(int x){
	ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;
}
void modify(int x,int l,int r,int L,int R,int vl){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){ADD(x,vl);return;}
	pushdown(x),modify(lson,l,mid,L,R,vl),modify(rson,mid+1,r,L,R,vl),pushup(x);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0x8080808080808080;
	if(L<=l&&r<=R)return seg[x].mx;
	pushdown(x);
	return max(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
void setup(int x,int l,int r,int P,int vl){
	if(l>P||r<P)return;
	if(l==r){seg[x].mx=vl,seg[x].tag=0;return;}
	pushdown(x),setup(lson,l,mid,P,vl),setup(rson,mid+1,r,P,vl),pushup(x);
}
void build(int x,int l,int r){
	if(l==r){seg[x].mx=0x8080808080808080;return;}
	build(lson,l,mid),build(rson,mid+1,r),pushup(x); 
}
signed main(){
	read(n),read(m);
	for(int i=1;i<=n;i++)read(val[i]);
	for(int i=1,l,r,x;i<=m;i++)read(l),read(r),read(x),v[r].push_back(make_pair(l,x));
	build(1,1,n+1),setup(1,1,n+1,1,0);
	for(int i=1;i<=n;i++){
		setup(1,1,n+1,i+1,query(1,1,n,1,i));
		modify(1,1,n+1,1,i,-val[i]);
		for(auto j:v[i])modify(1,1,n+1,1,j.first,j.second);
//		for(int j=0;j<=i;j++)printf("%lld ",f[i&1][j]);puts("");
	}
	print(query(1,1,n+1,1,n+1));
	return 0;
}