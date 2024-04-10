#include <bits/stdc++.h>
using namespace std;
long long query(int t,int i,int j,int k)
{
	printf("%d %d %d %d\n",t,i,j,k);
	fflush(stdout);
	long long ans;
	scanf("%I64d",&ans);
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a=2;
	for (int i=3;i<=n;i++)
	{
		if (query(2,1,a,i)==-1)
		a=i;
	}
	vector<pair<long long,int> > v({{0,a}});
	vector<int> d[2];
	for (int i=2;i<=n;i++)
	{
		if (i!=a)
		v.push_back({query(1,1,a,i),i});
	}
	sort(v.begin(),v.end());
	for (auto p:v)
	{
		if (p!=v.back())
		d[(query(2,1,v.back().second,p.second)+1)/2].push_back(p.second);
	}
	printf("0 1");
	for (int i:d[0])
	printf(" %d",i);
	printf(" %d",v.back().second);
	reverse(d[1].begin(),d[1].end());
	for (int i:d[1])
	printf(" %d",i);
}