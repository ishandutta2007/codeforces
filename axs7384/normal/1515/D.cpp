#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,l,r,_l[N],_r[N],x,ans;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&l,&r);
		for (int i=1;i<=n;++i)
			_l[i]=_r[i]=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&x);
			if (i<=l)
				++_l[x];
			else
				++_r[x];
		}
		int p=0,q;
		// for (int i=1;i<=n;++i)
		// 	printf("%d %d %d\n",i,_l[i],_r[i]);
		for (int i=1;i<=n;++i)
		{
			q=min(_l[i],_r[i]);
			_l[i]-=q;
			_r[i]-=q;
			p+=q;
		}
		l-=p;
		r-=p;
		// printf("%d??\n",p);
		// for (int i=1;i<=n;++i)
		// 	printf("%d %d %d\n",i,_l[i],_r[i]);
		if (l<=r)
		{
			ans=r;
			int tmp=0;
			for (int i=1;i<=n;++i)
				tmp+=_r[i]/2;
			ans-=min(tmp,(r-l)/2);
		}
		else
		{
			ans=l;
			int tmp=0;
			for (int i=1;i<=n;++i)
				tmp+=_l[i]/2;
			ans-=min(tmp,(l-r)/2);
		}
		cout<<ans<<endl;
	}
}