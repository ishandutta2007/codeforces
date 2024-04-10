#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=200005;
int a[N],b[N];
vector<int> v[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		set<int> s;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			v[i].clear();
			s.insert(i);
		}
		for (int i=1;i<=n;++i)
			v[a[i]].push_back(i);
		for (int i=0;i<n;++i)
		{
			vector<int> f;
			for (auto it=s.begin();it!=s.end();)
				if (v[*it].size()==i)
					it=s.erase(it);
				else
				{
					f.push_back(v[*it][i]);
					++it;
				}
			if (f.empty())break;
			b[f.back()]=a[f[0]];
			for (int i=0;i<(int)f.size()-1;++i)
				b[f[i]]=a[f[i+1]];
		}
		for (int i=1;i<=n;++i)
			printf("%d%c",b[i],i==n?'\n':' ');
	}
	return 0;
}