//CF 920F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333333;
const int W = 11;
struct node{
	LL x[W+1];
	int y;
}T[N<<2];
int n,a[N],f[1<<20];
void mrg(int k){
	for(int i=0;i<=W;i=i+1)
		T[k].x[i]=T[k<<1].x[i]+T[k<<1|1].x[i];
}
void shft(int k,int e){
	for(int i=0;i<=W;i=i+1)
		T[k].x[i]=T[k].x[min(i+e,W)];
}
void pushd(int k){
	if(!T[k].y)
		return;
	int e=T[k].y;
	T[k<<1].y=min(T[k<<1].y+e,W);
	shft(k<<1,e);
	T[k<<1|1].y=min(T[k<<1|1].y+e,W);
	shft(k<<1|1,e);
	T[k].y=0;
}
void build(int k=1,int l=1,int r=n){
	if(l==r){
		int i;
		T[k].x[0]=a[l];
		for(i=1;i<=W;i=i+1)
			T[k].x[i]=f[T[k].x[i-1]];
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	mrg(k);
}
void modify(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		T[k].y++;
		shft(k,1);
		return;
	}
	pushd(k);
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,k<<1,l,h);
	if(h<R)
		modify(L,R,k<<1|1,h+1,r);
	mrg(k);
}
LL query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return T[k].x[0];
	pushd(k);
	int h=l+r>>1;
	LL o=0;
	if(L<=h)
		o+=query(L,R,k<<1,l,h);
	if(h<R)
		o+=query(L,R,k<<1|1,h+1,r);
	return o;
}
int main()
{
	int m,t,i,j;
	n=1e6;
	for(i=1;i<=n;i=i+1)
		for(j=i;j<=n;j=j+i)
			f[j]++;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	build();
	while(m--){
		scanf("%d%d%d",&t,&i,&j);
		if(t==1)
			modify(i,j);
		else
			cout<<query(i,j)<<endl;
	}
	return 0;
}