#include<bits/stdc++.h>
using namespace std;
int t,n,a[20];
inline int getans(int x)
{
	int ans=0;
	for (int i=0;i<n;++i)
		if (x&(1<<i))
			ans+=a[i];
	return ans;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d",&a[i]);
		bool b=false;
		for (int i=1;i<1<<n;++i)
		{
			int p=getans(i);
			for (int j=i;j;j=(j-1)&i)
				if (getans(j)*2==p)
					b=true;
		}
		puts(b?"YES":"NO");
	}
	return 0;
}