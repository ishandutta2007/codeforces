#include<bits/stdc++.h>
using namespace std;
int t,n,mx,x;
int f[3];
set<int> s;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		f[0]=f[1]=f[2]=0;
		mx=0;
		s.clear();
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&x);
			s.insert(x);
			mx=max(mx,x);
			++f[x%3];
		}
		if (mx%3==0)
		{
			if (f[1]==0&&f[2]==0)
				printf("%d\n",mx/3);
			else
				printf("%d\n",mx/3+1);
		}
		if (mx%3==1)
		{
			if (f[2]==0||(!s.count(1)&&!s.count(mx-1)))
				printf("%d\n",mx/3+1);
			else
				printf("%d\n",mx/3+2);
		}
		if (mx%3==2)
		{
			if (f[1]==0)
				printf("%d\n",mx/3+1);
			else
				printf("%d\n",mx/3+2);
		}
	}
	return 0;
}