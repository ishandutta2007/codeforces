#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+3;
int a[N],c[N],n,t[N];
struct P{
	int x,y;
	bool operator<(P a)const{return x<a.x;}
}p[N];
void add(int x){
	for(;x<=n;x+=x&-x)++t[x];
}
int sum(int x){
	int r=0;
	for(;x;x-=x&-x)r+=t[x];
	return r;
}
ll calc(){
	int i,j,l;
	ll s=0;
	memset(t,0,n+1<<2);
	for(i=1;i<=n;++i)p[i].x=a[i],p[i].y=i;
	sort(p+1,p+n+1);
	c[p[1].y]=l=1;
	for(i=2;i<=n;++i){
		if(p[i].x!=p[i-1].x)l=i;
		c[p[i].y]=l;
	}	
	for(i=1;i<=n;++i){
		j=c[i];
		add(j);
		s+=i-sum(j);
	}
	return s;
}
int main(){
	int i,j,k,s=0;
	ll w,u;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	w=calc();
	for(i=0;i<31;++i){
		j=1<<i;
		for(k=1;k<=n;++k)a[k]^=j;
		u=calc();
		if(u>=w){
			for(k=1;k<=n;++k)a[k]^=j;
		}else w=u,s|=j;
	}
	printf("%lld %d",w,s);
	return 0;
}//2log