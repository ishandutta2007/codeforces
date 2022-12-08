#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int T;
int n;
ll a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld%lld",&a[i],&b[i]);
		ll tot=0;
		ll ans=1e18;
		b[0]=b[n];
		for(int i=1;i<=n;++i){
			tot+=max(a[i]-b[i-1],0ll);
		}
		for(int i=1;i<=n;++i){
			ans=min(ans,tot-max(a[i]-b[i-1],0ll)+a[i]);
		}
		printf("%lld\n",ans);
	}
}