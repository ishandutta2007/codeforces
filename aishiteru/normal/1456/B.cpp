#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,k,i,s[N],ans=1<<30,a[N],j,p[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(n>100)
	{
		puts("1");
		return 0;
	}
	for(i=1;i<=n;++i)
		s[i]=s[i-1]^a[i];
	for(i=n;i>=1;--i)
		p[i]=p[i+1]^a[i];
	for(i=1;i<=n;++i)
		for(j=i;j>=1;--j)
			for(k=i+1;k<=n;++k)
				if((p[i+1]^p[k+1])<(s[i]^s[j-1]))
					ans=min(ans,k-i-1+i-j);
	if(ans>n)
		puts("-1");
	else
		cout<<ans;
}