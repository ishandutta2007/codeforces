#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
vector<LL> vec;
LL n;
void calc (int x)
{
	LL l=x+1,r;
	r=n-(n%x)+1;
	if (r==n+1) r-=x;
	if (l>r) vec.push_back(1);
	else
	{
		LL t=(r-l)/x+1;
		vec.push_back((l+r)*t/2+1);
	}
}
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u*u<=n;u++)
	{
		if (n%u==0)
		{
			calc(u);
			calc(n/u);
		}
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int siz=vec.size();
	for (int u=0;u<siz;u++) printf("%I64d ",vec[u]);
	return 0;
}