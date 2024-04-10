#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=4e5+10;
int a[maxn],n,t_case;
ll ans;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		a[0]=a[n+1]=0;
		ans=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=n;++i)ans+=a[i]-min(a[i],max(a[i-1],a[i+1])),a[i]=min(a[i],max(a[i-1],a[i+1]));
		for(ri i=0;i<=n;++i)ans+=abs(a[i+1]-a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}