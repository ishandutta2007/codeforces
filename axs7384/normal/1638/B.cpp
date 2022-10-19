#include<bits/stdc++.h>
using namespace std;
int t,n;
vector<int> v[2];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		v[0].clear();
		v[1].clear();
		for (int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			v[x&1].push_back(x);
		}
		bool b=true;
		// for (int j=0;j<=1;++j)
		// 	for (int i=1;i<(int)v[j].size();++j)
		// 		if (v[j][i-1]>v[j][i])
		// 			b=false;
		for (int i=0;i<=1;++i)
			if (v[i].size()&&!is_sorted(v[i].begin(),v[i].end()))
				b=false;
		puts(b?"Yes":"No");
	}
	return 0;
}