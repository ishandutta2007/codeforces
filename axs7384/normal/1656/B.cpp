#include<bits/stdc++.h>
using namespace std;
int t,n,k;
const int N=2000005;
int a[N];
set<int> s;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&k);
		s.clear();
		bool b=false;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			s.insert(a[i]);
		}
		for (int i=1;i<=n;++i)
			if (s.count(a[i]+k))
				b=true;
		puts(b?"YES":"NO");
	}
	return 0;
}