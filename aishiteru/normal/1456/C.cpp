#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int t,n,k,i,p,a[N],j;
long long ans,s,su[N],as=-1000000000000000000ll;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&k);
	++k;
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;++i)
		su[i]=su[i-1]+1ll*a[i]*((i-1)/k);
	for(i=n;i>=1;--i)
	{
		as=max(as,su[i]+ans+s*((i+k-1)/k));
		ans+=s;
		s+=a[i];
	}
	as=max(as,ans);
	cout<<as;
}