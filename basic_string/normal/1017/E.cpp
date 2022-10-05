#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
struct P{
	ll x,y;
	inline P operator-(P a)const{return{x-a.x,y-a.y};}
	inline bool operator<(P a)const{return x<a.x||(x==a.x&&y<a.y);}
}u[N],v[N];
inline ll dj(P a,P b){return a.x*b.x+a.y*b.y;}
inline ll cj(P a,P b){return a.x*b.y-a.y*b.x;}
inline ll ds(P a){return a.x*a.x+a.y*a.y;}
struct CH{
	P st[N];
	ll a[N],b[N],c[N];
	int work(P*p,int n){
		int tp=0,i,j;
		sort(p+1,p+n+1),st[0]=p[1];
		for(i=2;i<=n;++i){
			while(tp&&cj(st[tp]-st[tp-1],p[i]-st[tp])<=0)--tp;
			st[++tp]=p[i];
		}
		j=tp;
		for(i=n-1;i;--i){
			while(tp>j&&cj(st[tp]-st[tp-1],p[i]-st[tp])<=0)--tp;
			st[++tp]=p[i];
		}
		return tp;
	}
	void get(int n){
		st[n+1]=st[1];
		for(int i=0;i<=n;++i)st[i]=st[i+1]-st[i];
		for(int i=1;i<=n;++i)a[i]=ds(st[i]),b[i]=dj(st[i-1],st[i]),c[i]=cj(st[i-1],st[i]);
	}
}A,B;
int f[N];
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%lld%lld",&u[i].x,&u[i].y);
	for(i=1;i<=m;++i)scanf("%lld%lld",&v[i].x,&v[i].y);
	n=A.work(u,n),m=B.work(v,m);
	if(n!=m)return puts("NO"),0;
	A.get(n),B.get(n),m=n<<1;
	for(i=1;i<=n;++i)A.a[i+n]=A.a[i],A.b[i+n]=A.b[i],A.c[i+n]=A.c[i];
	for(j=0,i=2;i<=n;++i){
		while(j&&(B.a[i]!=B.a[j+1]||B.b[i]!=B.b[j+1]||B.c[i]!=B.c[j+1]))j=f[j];
		if(B.a[i]==B.a[j+1]&&B.b[i]==B.b[j+1]&&B.c[i]==B.c[j+1])++j;
		f[i]=j;
	}
	for(j=0,i=1;i<=m;++i){
		while(j&&(A.a[i]!=B.a[j+1]||A.b[i]!=B.b[j+1]||A.c[i]!=B.c[j+1]))j=f[j];
		if(A.a[i]==B.a[j+1]&&A.b[i]==B.b[j+1]&&A.c[i]==B.c[j+1])++j;
		if(j==n)return puts("YES"),0;
	}
	puts("NO");
	return 0;
}