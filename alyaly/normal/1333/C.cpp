#include<bits/stdc++.h>
#include<set>
#define int long long
using namespace std;
int T,n,m,K,a[200001],s[200001],ans,dp[200001],np;
set<int> se;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	se.insert(0);
	for(int i=1;i<=n;i++){
		while(se.find(s[i])!=se.end()){
			se.erase(s[np++]);
		}
		ans+=(i-np);
		se.insert(s[i]);
	}
	printf("%lld\n",ans);
	return 0;
}