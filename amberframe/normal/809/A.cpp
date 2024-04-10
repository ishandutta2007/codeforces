#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 300005;
const LL mod = 1e9+7;

int a[maxn],n;LL pw2[maxn],ans;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("date.in","r",stdin);
		freopen("date.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	pw2[0]=1ll;
	for (int i=1;i<=n;i++)
		pw2[i]=(pw2[i-1]<<1)%mod;
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++)
		(ans+=(a[i+1]-a[i])*(pw2[i]-1)%mod*(pw2[n-i]-1))%=mod;
	printf("%lld",ans<0?ans+mod:ans);
	return 0;
}