#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[300005],sum[300005],cum[2][300005],l[65];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		long long a;
		scanf("%I64d",&a);
		arr[i]=__builtin_popcountll(a);
	}
	cum[0][0]++;
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+arr[i];
		cum[0][i]=cum[0][i-1];
		cum[1][i]=cum[1][i-1];
		cum[sum[i]%2][i]++;
		l[arr[i]]=i;
		vector<int> v;
		for (int x=0;x<=60;x++)
		{
			if (l[x])
			v.push_back(l[x]);
		}
		v.push_back(0);
		sort(v.begin(),v.end(),greater<int>());
		int mx=0;
		for (int x=0;x<v.size()-1;x++)
		{
			mx=max(mx,arr[v[x]]);
			int pos=v[x];
			while (pos>v[x+1] && sum[i]-sum[pos-1]<2*mx)
			pos--;
			if (pos==v[x+1])
			continue;
			ans+=cum[sum[i]%2][pos-1]-(v[x+1]? cum[sum[i]%2][v[x+1]-1]:0);
		}
	}
	printf("%I64d",ans);
}