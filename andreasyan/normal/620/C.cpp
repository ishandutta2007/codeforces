#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;

int n,m;
vector<pair<int,int> > a;
map<int,int> b;
int main()
{
	int i,j,x,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(b[x])
		{
			if(!a.size())
				a.push_back(make_pair(1,i));
			else
				a.push_back(make_pair(a[a.size()-1].second+1,i));
			b.clear();
		}
		else
		{
			b[x]=i;
		}
	}
	if(a.size()==1)
	{
		printf("1\n1 %d\n",n);
		return 0;
	}
	if(a.size()==0)
	{
		printf("-1\n");
		return 0;
	}
	if(a[a.size()-1].second!=n)
	{
		a[a.size()-1].second=n;
	}
	printf("%d\n",a.size());
	for(i=0;i<a.size();++i)
	{
		printf("%d %d\n",a[i].first,a[i].second);
	}
	return 0;
}