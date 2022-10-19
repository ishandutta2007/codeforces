#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
ll a[maxn],sum;
int main(){
	scanf("%d",&n);
	set<ll>s;
	for(ri i=1;i<=n;++i)scanf("%lld",a+i),s.insert(a[i]),sum+=a[i];
	scanf("%d",&m);
	while(m--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		auto it=s.lower_bound(x);
		ll ans1=LLONG_MAX,ans2=LLONG_MAX;
		if(it!=s.end()){
			ll atk=*it;
			ans1=max(x-atk,0ll)+max(y-(sum-atk),0ll);
		}
		if(it!=s.begin()){
			--it;
			ll atk=*it;
			ans2=max(x-atk,0ll)+max(y-(sum-atk),0ll);
		}
		printf("%lld\n",min(ans1,ans2));
	}
	return 0;
}