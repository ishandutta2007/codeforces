#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<pair<int,int>,int> > v1,v2;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (a>b)
		v1.push_back({{a,b},i});
		else
		v2.push_back({{a,b},i});
	}
	bool rev=0;
	if (v2.size()>v1.size())
	{
		v1=v2;
		rev=1;
	}
	sort(v1.begin(),v1.end());
	if (rev)
	reverse(v1.begin(),v1.end());
	printf("%d\n",v1.size());
	for (auto p:v1)
	printf("%d ",p.second+1);
}