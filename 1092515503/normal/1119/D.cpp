#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,diff[100100],sum[100100],t1,t2,lim,len;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&diff[i]);
	sort(diff+1,diff+n+1);
	for(int i=1;i<n;i++)diff[i]=diff[i+1]-diff[i];
	sort(diff+1,diff+n);
	for(int i=1;i<n;i++)sum[i+1]=sum[i]+diff[i];
	scanf("%lld",&q);
	while(q--)scanf("%lld%lld",&t1,&t2),len=t2-t1+1,lim=lower_bound(diff+1,diff+n,len)-diff,printf("%lld\n",sum[lim]+(n-lim+1)*len);
	return 0;
}