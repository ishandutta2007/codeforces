#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,x,y;
int f[N];
vector<int> v;
inline void work(int n,int m)
{
	for (int i=0;i<=n;++i)
	{
		int j=x-i;
		if (j>=0&&j<=m)
			f[n-i+j]=1;
	}
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&x,&y);
		n=x+y;
		for (int i=0;i<=n;++i)
			f[i]=0;
		if (n%2==0)
			work(n/2,n/2);
		else
		{
			work(n/2,n/2+1);
			work(n/2+1,n/2);
		}
		v.clear();
		for (int i=0;i<=n;++i)
			if (f[i])
				v.push_back(i);
		printf("%u\n",v.size());
		for (int x:v)
			printf("%d ",x);
		puts("");
	}
	return 0;
}