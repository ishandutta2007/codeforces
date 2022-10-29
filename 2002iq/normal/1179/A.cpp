#include <iostream>
#include <vector>
#include <deque>
using namespace std;
deque<int> d;
vector<pair<int,int> > v;
int main()
{
	int n,q,mx=0;
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		d.push_back(a);
		mx=max(mx,a);
	}
	while (d.front()!=mx)
	{
		int a=d[0],b=d[1];
		d.pop_front();
		d.pop_front();
		d.push_front(max(a,b));
		d.push_back(min(a,b));
		v.push_back({a,b});
	}
	while (q--)
	{
		long long m;
		scanf("%lld",&m);
		m--;
		if (m<v.size())
		printf("%d %d\n",v[m].first,v[m].second);
		else
		printf("%d %d\n",d[0],d[(m-(int)v.size())%(n-1)+1]);
	}
}