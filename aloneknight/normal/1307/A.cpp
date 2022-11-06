#include<bits/stdc++.h>
using namespace std;
int n,d,a[105];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int s=a[1];
		for(int i=2;i<=n;i++)
		{
			int t=min(a[i],d/(i-1));
			s+=t;d-=t*(i-1);
		}
		printf("%d\n",s);
	}
	return 0;
}