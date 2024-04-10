#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
#define ll long long
ll a[N];
 
struct Q{
	ll x,y,w;
	bool operator<(Q a)const{return w<a.w;}
};
priority_queue<Q>q;
ll calc(ll x,ll y){
	if(x<y)return 1ll<<62;
	ll z=x/y,a,b;
	a=y*z+y-x,b=y-a;
	return a*z*z+b*(z+1)*(z+1);
}
int main(){
	int n,m,i,j,k;
	Q b;
	ll ans=0,w;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",a+i),ans+=a[i]*a[i];
		w=calc(a[i],1)-calc(a[i],2);
		q.push({a[i],1,w});
	}
	for(i=n+1;i<=m;++i){
		b=q.top(),q.pop();
		ans-=b.w;
		w=calc(b.x,b.y+1)-calc(b.x,b.y+2);
		q.push({b.x,b.y+1,w});
	}
	printf("%lld",ans);
	return 0;
}