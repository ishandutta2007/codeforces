#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int s[N],a[N],ans,n,m,mod;
int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	ans=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[a[i]%mod]++;
		if(s[a[i]%mod]>=m)
			ans=a[i]%mod;
	}
	if(ans==-1)
		puts("No");
	else
	{
		puts("Yes");
		for(int i=1;i<=n;i++)
			if(a[i]%mod==ans)
			{
				cout<<a[i];
				putchar(' ');
				--m;
				if (!m)
					break;
			}
	}
	return 0;
}