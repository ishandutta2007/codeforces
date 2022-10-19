#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int N=1000003;

int n;
long long a[N];
pair<int,int> b[N];

bool ham(pair<int,int> x,pair<int,int> y)
{
	return max(a[x.first],a[x.second])<max(a[y.first],a[y.second]);
}

int p[N];
long long q[N];
void pp()
{
	for(int i=1;i<=n;++i)
	{
		p[i]=i;
		q[i]=1;
	}
}
int fi(int x)
{
	if(x==p[x])
		return x;
	return p[x]=fi(p[x]);
}
void kp(int x,int y,long long& ans)
{
	int cx=x,cy=y;
	x=fi(x);
	y=fi(y);
	/////////////////////////
	ans+=(q[x]*q[y]*max(a[cx],a[cy]));
	/////////////////////////
	if(q[x]<q[y])
	{
		p[x]=y;
		q[y]+=q[x];
	}
	else
	{
		p[y]=x;
		q[x]+=q[y];
	}
}

long long solv()
{
	long long ans=0;
	sort(b,b+n-1,ham);
	pp();
	for(int i=0;i<n-1;++i)
	{
		kp(b[i].first,b[i].second,ans);
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<n-1;++i)
		scanf("%d%d",&b[i].first,&b[i].second);
	long long ans=solv();
	for(int i=1;i<=n;++i)
		a[i]=-a[i];
	ans+=solv();
	cout<<ans<<endl;
	return 0;
}