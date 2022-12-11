#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
//#define P 998244353
using namespace std;
int T,n,a[300001],ans,f[300001];
signed main(){
//	srand(time(0));
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i-a[i]>=0) f[i]=f[i-a[i]]+1;
			else f[i]=0;
		}
		for(int i=1;i<=n;i++) ans=max(ans,f[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
/*

*/