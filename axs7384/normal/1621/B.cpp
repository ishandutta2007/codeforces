#include<bits/stdc++.h>
using namespace std;
const int inf=2e9+7;
int n,l,r,x,t;
int c,Lc,Rc,L,R;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%d%d%d",&l,&r,&x);
		c=x;
		L=l;
		R=r;
		Lc=x;
		Rc=x;
		printf("%d\n",x);
		for (int i=2;i<=n;++i)
		{
			scanf("%d%d%d",&l,&r,&x);
			if (l<=L&&r>=R)
			{
				if (l==L&&r==R)
					c=min(c,x);
				else
					c=x;
				if (l==L)
					Lc=min(Lc,x);
				else
				{
					L=l;
					Lc=x;
				}
				if (r==R)
					Rc=min(Rc,x);
				else
				{
					R=r;
					Rc=x;
				}
			}
			else
			{
				if (l<=L)
				{
					if (l==L)
						Lc=min(Lc,x);
					else
					{
						L=l;
						Lc=x;
						c=inf;
					}
				}
				if (r>=R)
				{
					if (r==R)
						Rc=min(Rc,x);
					else
					{
						R=r;
						Rc=x;
						c=inf;
					}
				}
			}
			printf("%d\n",min(Lc+Rc,c));
		}
	}
	return 0;
}