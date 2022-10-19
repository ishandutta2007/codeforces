#include<bits/stdc++.h>
#define int long long
#define N
using namespace std;
int t,n,x,y;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&x,&y);
		printf("%lld %lld\n",min(max(1ll,x+y-n+1),n),min(x+y-1,n));
	}
	return 0;
}