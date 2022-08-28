//CF 938E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1e6+16;
const LL mod = 1e9+7;
int fpow(int x,int y=mod-2){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%mod;
	if(y&1)
		z=z*x%mod;
	return z;
}
int n,a[N];
LL fac[N],inv[N];
int main()
{
	int i,j,ans=0;
	scanf("%d",&n);
	fac[0]=1;
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),fac[i]=(LL)fac[i-1]*i%mod;
	inv[n]=fpow(fac[n]);
	for(i=n;i;i=i-1)
		inv[i-1]=(LL)inv[i]*i%mod;
	sort(a+1,a+n+1);
	for(i=1;a[i]<a[n];i=i+1){
		if(a[i]!=a[i-1])
			j=n-i+1;
		ans=(ans+(LL)fac[n]*inv[j]%mod*fac[j-1]%mod*(LL)a[i]%mod)%mod;
	}
	cout<<ans;
	return 0;
}