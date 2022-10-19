#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=5000;
pair<int,int> a[N];
int b[N],n,r,q[N],ans,cnt;
inline int f(pair<int,int> x)
{
	return x.first*x.first+x.second*x.second;
}
inline int g(int x,int y)
{
	return f(mp(a[q[x]].first-a[q[y]].first,a[q[x]].second-a[q[y]].second));
}
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
	return f(x)>f(y);
}
inline void work()
{
	int sum=0;
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			sum+=g(i,j);
	if (sum>ans)
	{
		ans=sum;
		for (int i=1;i<=n;++i)
			b[i]=q[i];
	}
}
inline void dfs(int x)
{
	if (x>n)
	{
		work();
		return;
	}
	for (int i=q[x-1];i<=cnt;++i)
	{
		q[x]=i;
		dfs(x+1);
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	r=r*r;
	for (int i=-r;i<=r;++i)
		for (int j=-r;j<=r;++j)
			if (f(mp(i,j))<=r)
				a[++cnt]=mp(i,j);
	sort(a+1,a+1+cnt,cmp);
	cnt=min(18,cnt);
	q[0]=1;
	dfs(1);
	cout<<ans<<'\n';
	for (int i=1;i<=n;++i)
		cout<<a[b[i]].first<<' '<<a[b[i]].second<<'\n';
	return 0;
}