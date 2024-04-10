#include<bits/stdc++.h>
#include<algorithm>
#define P 998244353
#define int long long
using namespace std;
int n,a[300001],g[300001],pg,K,p,ans,ans1=1;
signed main(){
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>p;
		a[p]=i;
	}
	for(int i=n;i>=n-K+1;i--){
		ans+=i;
		g[++pg]=a[i];
	}
	sort(g+1,g+pg+1);
	for(int i=2;i<=pg;i++){
		ans1*=(g[i]-g[i-1]);
		ans1%=P;
	}
	printf("%lld %lld\n",ans,ans1);
	return 0;
}