#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;
const int N=100003;

int n;
int a[N];
bool c[N];
vector<long long> b;
int main()
{
	///in
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	/////
	for(int i=1;i<=n;++i)
	{
		if(c[i])
			continue;
		long long x=1;
		c[i]=true;
		for(int j=a[i];j!=i;j=a[j])
		{
			c[j]=true;
			++x;
		}
		b.push_back(x);
	}
	/////
	long long ans=0;
	sort(b.begin(),b.end());
	if(b.size()==1)
	{
		ans=b[0]*b[0];
		cout<<ans<<endl;
		return 0;
	}
	for(int i=0;i<b.size()-2;++i)
		ans+=(b[i]*b[i]);
	ans+=((b[b.size()-1]+b[b.size()-2])*(b[b.size()-1]+b[b.size()-2]));
	cout<<ans<<endl;
	return 0;
}