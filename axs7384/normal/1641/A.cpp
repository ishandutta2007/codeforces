#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,x;
ll p;
multiset<ll> s;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&x);
		s.clear();
		for (int i=1;i<=n;++i)
		{
			scanf("%lld",&p);
			s.insert(p);
		}
		int ans=0;
		while (!s.empty())
		{
			auto it=s.begin();
			// cout<<*it<<endl;
			ll p=*it;
			s.erase(it);
			if (!s.empty()&&s.find(p*x)!=s.end())
				s.erase(s.find(p*x));
			else
				++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}