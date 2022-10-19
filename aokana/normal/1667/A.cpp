#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int n,t_case;
ll a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i);
	ll ans=LLONG_MAX;
	for(ri i=1;i<=n;++i){
		b[i]=0;
		ll sum=0;
		for(ri j=i+1;j<=n;++j){
			ll need=b[j-1]+1,cnt=(need+a[j]-1)/a[j];
			sum+=cnt,b[j]=cnt*a[j];
		}
		for(ri j=i-1;j;--j){
			ll need=b[j+1]+1,cnt=(need+a[j]-1)/a[j];
			sum+=cnt,b[j]=cnt*a[j];
		}
		ckmin(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}