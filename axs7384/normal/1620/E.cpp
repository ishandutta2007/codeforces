#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,opt[N],x[N],y[N],f[N];
vector<int> ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&opt[i],&x[i]);
		if (opt[i]==2)
			scanf("%d",&y[i]);
	}
	for (int i=1;i<=500000;++i)
		f[i]=i;
	for (int i=n;i>=1;--i)
		if (opt[i]==1)
			ans.push_back(f[x[i]]);
		else
			f[x[i]]=f[y[i]];
	for (int i=(int)ans.size()-1;i>=0;--i)
		printf("%d%c",ans[i],i?' ':'\n');
	return 0;
}