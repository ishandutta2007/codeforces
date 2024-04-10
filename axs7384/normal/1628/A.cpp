#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,t;
int a[N];
set<int> s[N];
vector<int> v;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<=n;++i)
			s[i].clear();
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			s[a[i]].insert(i);
		}
		v.clear();
		for (int l=1,r;l<=n;l=r+1)
		{
			r=l;
			for (int i=0;i<=n+1;++i)
			{
				auto p=s[i].lower_bound(l);
				if (p==s[i].end())
				{
					v.push_back(i);
					break;
				}
				else
				{
					// cout<<l<<' '<<i<<' '<<(*p)<<endl;
					r=max(r,*p);
				}
			}
		}
		printf("%d\n",(int)v.size());
		for (int i=0;i<(int)v.size();++i)
			printf("%d%c",v[i],i==(int)v.size()-1?'\n':' ');
	}
	return 0;
}