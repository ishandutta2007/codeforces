#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int t,n,a[N];
vector<int> v;
inline bool check()
{
	for (int i=1;i<=n;++i)
		if (a[i]%2!=i%2)
			return true;
	return false;
}
inline int ask(int x)
{
	for (int i=1;i<=n;++i)
		if (a[i]==x)
			return i;
	return -1;
}
inline void work(int pos)
{
	if (pos<=1)
		return;
	v.push_back(pos);
	for (int i=1;i<=pos/2;++i)
		swap(a[i],a[pos-i+1]);
	int p=v.size()-1;
	if (v[p]==v[p-1])
		v.resize(p-1);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		if (check())
		{
			puts("-1");
			continue;
		}
		v.clear();
		for (int i=n,pos;i>=3;i-=2)
		{
			work(ask(i));
			work(ask(i-1)-1);
			work(ask(i-1)+1);
			work(ask(i));
			work(i);
		}
		printf("%u\n",v.size());
		for (int x:v)
			printf("%d ",x);
		puts("");
	}
	return 0;
}