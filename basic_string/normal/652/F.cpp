#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
struct P{
	long long x;
	int id;
	bool f;
	bool operator<(P a)const{return x<a.x;} 
}p[N];
int q[N],w[N];
signed main(){
	int n,m,i,j;
	long long t,s=0;
	char c;
	scanf("%d%d%lld",&n,&m,&t);
	for(i=1;i<=n;++i)scanf("%lld %c",&p[i].x,&c),--p[i].x,p[i].f=c=='R',p[i].id=i;
	sort(p+1,p+n+1);
	for(i=1;i<=n;++i){
		q[i]=p[i].id;
		if(p[i].f)p[i].x+=t;else p[i].x-=t;
		s+=p[i].x/m,(s-=((p[i].x%=m)<0))%=n,(p[i].x+=m)%=m;
	}
	sort(p+1,p+n+1),(s+=n)%=n;
	for(i=s+1;i<=n;++i)w[q[i-s]]=p[i].x;
	for(i=1;i<=s;++i)w[q[i-s+n]]=p[i].x;
	for(i=1;i<=n;++i)printf("%d ",w[i]+1);
	return 0;
}