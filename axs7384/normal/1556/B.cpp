#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int a[N],f[N];
vector<int> v[2];
ll ans;
int n,t;
inline void add(int x)
{
	for (;x<=n;x+=x&(-x))
		++f[x];
}
inline int ask(int x)
{
	int ans=0;
	for (;x;x-=x&(-x))
		ans+=f[x];
	return ans;
}
inline void clear()
{
	for (int i=0;i<=n;++i)
		f[i]=0;
}
inline void work(int x,int y)
{
	for (int i=1;i<=n;++i)
		if (i%2==1)
			a[v[x][i/2]]=i;
		else
			a[v[y][i/2-1]]=i;
	ll fans=0;
	for (int i=1;i<=n;++i)
	{
		add(a[i]);
		fans+=i-ask(a[i]);
	}
	ans=min(fans,ans);
	clear();
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		v[0].clear();v[1].clear();
		for (int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			v[x&1].push_back(i);
		}
		// cout<<v[0].size()<<' '<<v[1].size()<<endl;
		if (n%2==0)
		{
			if (v[0].size()==n/2)
			{
				ans=(ll)n*n;
				work(0,1);
				work(1,0);
				printf("%lld\n",ans);
			}
			else
				puts("-1");
		}
		else
		{
			if (v[0].size()==n/2)
			{
				ans=(ll)n*n;
				work(1,0);
				printf("%lld\n",ans);
			}
			else
			{
				if (v[1].size()==n/2)
				{
					ans=(ll)n*n;
					work(0,1);
					printf("%lld\n",ans);
				}
				else
					puts("-1");
			}
		}
	}
	return 0;
}