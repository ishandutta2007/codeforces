#include<bits/stdc++.h>
using namespace std;
#define ll __int128
#define gg long long
const ll P=10000000000ll;
ll g(ll x){
	return x*(x+1)*(2*x+1)/6;
}
ll f(ll x,ll y){
	ll u,v;
	if(x<y){
		u=g(y-1)-g(x-1)+y-x;
		v=u+(x-1)*(y-x);
		return (1+x*x)*x*x/2+(u+v)*x/2;
	}else{
		u=g(x)-g(y);
		v=u-(y-1)*(x-y);
		return (1+y*y)*y*y/2+(u+v)*y/2;
	}
}
int main(){
	int T,x1,y1,x2,y2;
	ll ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2),--x1,--y1;
		ans=f(x2,y2)-f(x1,y2)-f(x2,y1)+f(x1,y1);
		if(ans<P)printf("%lld\n",(gg)ans);
		else printf("...%010lld\n",(gg)(ans%P));
	}
	return 0;
}