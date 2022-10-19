#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,pov[300100],res;
signed main(){
	scanf("%lld%lld",&n,&m),pov[0]=1;
	for(int i=1;i<=n;i++)pov[i]=(1ll*pov[i-1]*i)%m;
	for(int i=0;i<n;i++)
		res+=1ll*(1ll*pov[i+1]*(n-i)%m)*(1ll*pov[n-i-1]*(n-i)%m)%m,res%=m;
	printf("%lld\n",res);
	return 0;
}