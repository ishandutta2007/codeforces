#include <bits/stdc++.h>
using namespace std;
int n,x,a,y,b,arr[200005];
long long k;
bool check(int m)
{
	long long l=1LL*a*b/__gcd(a,b),cur=0;
	int cnt=m/l;
	for (int i=0;i<cnt;i++)
	cur+=arr[i]/100*(x+y);
	for (int i=cnt;i<m/b;i++)
	cur+=arr[i]/100*y;
	for (int i=m/b;i<m/a+m/b-cnt;i++)
	cur+=arr[i]/100*x;
	return (cur>=k);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		scanf("%d%d%d%d%I64d",&x,&a,&y,&b,&k);
		if (x>y)
		{
			swap(x,y);
			swap(a,b);
		}
		sort(arr,arr+n);
		reverse(arr,arr+n);
		int st=0,en=n+1;
		while (st!=en)
		{
			int mid=(st+en)/2;
			if (check(mid))
			en=mid;
			else
			st=mid+1;
		}
		if (st==n+1)
		st=-1;
		printf("%d\n",st);
	}
}