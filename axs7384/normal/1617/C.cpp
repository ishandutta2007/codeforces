#include<bits/stdc++.h>
using namespace std;
int t,n,x;
set<int> s;
vector<int> v;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			s.insert(i);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&x);
			if (s.count(x))
				s.erase(x);
			else
				v.push_back(x);
		}
		sort(v.begin(),v.end(),greater<int>());
		bool b=true;
		int ans=0;
		for (int x:v)
			if (*s.rbegin()>(x-1)/2)
				b=false;
			else
			{
				++ans;
				s.erase(*s.rbegin());
			}
		s.clear();
		v.clear();
		if (b)
			printf("%d\n",ans);
		else
			puts("-1");
	}
}