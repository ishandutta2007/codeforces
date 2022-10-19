#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int n,x,t,t_case;
inline ll calc(int k){
	if(k<1)return 0;
	return 1ll*k*(k+1)>>1;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&x,&t);
		ri k=min(n-1,t/x);
		ll ans=1ll*n*k;
		ans-=calc(k);
		printf("%lld\n",ans);
	}
	return 0;
}