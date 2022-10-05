#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
using ll=long long;
struct P{
	ll x,y,a;
	bool operator<(P a)const{return x<a.x;}
}p[N];
int q[N];
ll f[N];
double sl(int i,int j){return(f[j]-f[i])*1./(p[j].x-p[i].x);}
int main(){
	int n,i,l=0,r=0;
	ll w=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].a);
	sort(p+1,p+n+1);
	for(i=1;i<=n;++i){
		while(l<r&&sl(q[l],q[l+1])>p[i].y)++l;
		f[i]=f[q[l]]+(p[i].x-p[q[l]].x)*p[i].y-p[i].a,w=max(w,f[i]);
		while(l<r&&sl(q[r],i)>=sl(q[r-1],q[r]))--r;
		q[++r]=i;
	}
	printf("%lld",w);
	return 0;
}