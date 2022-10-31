#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
long long i,l,r,n,k,A,B,a[1000005];
long long dp(long long l,long long r,long long ll,long long rr)
{
	long long mid=(l+r)/2;
	if(ll>rr)
		return A;
	if(l==r)
		return 1ll*B*(rr-ll+1)*(r-l+1);
	long long ml=ll,mr=rr+1;
	while(ml<mr)
	{
		long long m=(ml+mr)/2;
		if(a[m]>mid)
			mr=m;
		else
			ml=m+1;
	}
	long long ans=dp(l,mid,ll,ml-1)+dp(mid+1,r,ml,rr);
	return min(ans,1ll*B*(rr-ll+1)*(r-l+1));
}
int main(){
	cin>>n>>k>>A>>B;
	for(i=1;i<=k;i++)
		cin>>a[i];
	sort(a+1,a+1+k);
	a[k+1]=(1<<n)+1;
	cout<<dp(1,1<<n,1,k);
}