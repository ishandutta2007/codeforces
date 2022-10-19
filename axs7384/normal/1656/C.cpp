#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=2000005;
int a[N];
set<int> s;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		s.clear();
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			s.insert(a[i]);
		}
		if (s.count(1))
		{
			bool b=true;
			for (int i=1;i<=n;++i)
				if (s.count(a[i]+1))
					b=false;
			puts(b?"YES":"NO");
		}
		else
			puts("YES");
	}
	return 0;
}