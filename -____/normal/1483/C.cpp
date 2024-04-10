#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 333333;
const int W = 1<<20;
const LL inf = 1e18;
int n,a[N],b[N],c[N];
int t[W];
void build(int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=a[l];
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	t[k]=min(t[k<<1],t[k<<1|1]);
}
int query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return t[k];
	int h=l+r>>1,o=n+1;
	if(L<=h)
		o=min(o,query(L,R,k<<1,l,h));
	if(h<R)
		o=min(o,query(L,R,k<<1|1,h+1,r));
	return o;
}
struct node{
	LL f[2][2];
	node(){
		memset(f,0,sizeof(f));
	}
};
void cmax(LL&x,LL y){
	if(x<y)
		x=y;
}
node solve(int l,int r){
	if(r<l)
		return node();
	int x=b[query(l,r)],i,j;
	node s=solve(l,x-1),t=solve(x+1,r),o;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			o.f[i][j]=-inf;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			cmax(o.f[i][j],c[x]+s.f[i][1]+t.f[1][j]);
	for(i=0;i<2;i++)
		cmax(o.f[i][1],s.f[i][1]);
	for(j=0;j<2;j++)
		cmax(o.f[1][j],t.f[1][j]);
	return o;
}
int main(){
	int i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),b[a[i]]=i;
	for(i=1;i<=n;i++)
		scanf("%d",c+i);
	build();
	cout<<solve(1,n).f[0][0];
	return 0;
}