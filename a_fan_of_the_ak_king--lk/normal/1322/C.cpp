#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=500005,E=262144;
#define inf 2147483647
int n,i,j,t,p[N],m,u,v;
long long s,ans,c[N];
vector<int> g[N];
struct str{
	int d;
	long long x,y;
}a[N];
bool cmp(str a,str b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		s=0;
		for(i=1;i<=n;++i)
		{
			scanf("%lld",&c[i]);
			g[i].clear();
		}
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&u,&v);
			g[v].push_back(u);
			s^=u;
			s^=v;
		}
		srand(((s+time(0))%M+M)%M);
		int bs=rand()*2+3001;
		for(i=1;i<=n;++i)
		{
			int k=0;
			for(auto j:g[i])
				p[++k]=j;
			sort(p+1,p+1+k);
			long long s=0,s2=0;
			for(j=1;j<=k;++j)
			{
				s=(s*bs+p[j])%M;
				s2^=p[j];
			}
			a[i]=(str){i,s,s2};
		}
		sort(a+1,a+1+n,cmp);
		ans=0;
		for(i=1;i<=n;)
		{
			s=0;
			for(j=i;j<=n&&a[i].x==a[j].x&&a[i].y==a[j].y;++j)
				s+=c[a[j].d];
			if(a[i].x!=0||a[i].y!=0) 
				ans=__gcd(ans,s);
			i=j;
		}
		printf("%lld\n",ans);
	}
}