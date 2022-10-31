#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j,a[N],T;
long long w;
vector<int> g;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %lld",&n,&w);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=n;++i)
			if(a[i]>=(w+1)/2&&a[i]<=w)
			{
				printf("1\n%d\n",i);
				break;
			}
		if(i>n)
		{
			long long s=0;
			for(i=1;i<=n;++i)
				if(s+a[i]<=w)
					s+=a[i];
			if(s>=(w+1)/2)
			{
				s=0;
				g.clear();
				for(i=1;i<=n;++i)
					if(s+a[i]<=w)
					{
						s+=a[i];
						g.push_back(i);
					}
				printf("%d\n",g.size());
				for(auto it:g)
					printf("%d ",it);
				printf("\n");
			}
			else
				puts("-1");
		}
	}
}