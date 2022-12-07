#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const int N=100005;
multiset<int> s;
set<int> :: iterator it;
int n,c;
LL f[N];
int a[N];
int main()
{
	scanf("%d%d",&n,&c);
	LL sum=0;
	for (int u=1;u<=n;u++) 	
	{
		scanf("%d",&a[u]);
		sum=sum+a[u];
	}
	for (int u=1;u<=n;u++)
	{
		f[u]=f[u-1];s.insert(a[u]);
		if (u>=c)
		{
			f[u]=max(f[u],f[u-c]+(*s.begin()));
			int tt=a[u-c+1];
			it=s.find(tt);
			s.erase(it);
		}
	}
	printf("%I64d\n",sum-f[n]);
	return 0;
}