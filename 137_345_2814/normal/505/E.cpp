#include<cstdio>
#include<set>
using namespace std;
#define N 100050
struct sth{int id,ti;friend bool operator <(sth a,sth b){return a.ti==b.ti?a.id<b.id:a.ti>b.ti;}};
set<sth> tp;
int n,m,k,p,s[N],h[N],t1[N],ct1;
long long h1[N];
bool solve(long long st)
{
	tp.clear();
	for(int i=1;i<=n;i++)
	{
		h1[i]=st;t1[i]=m;
		long long s1=m-st/h[i];
		if(s1==m)return 0;
		if(s1>0)tp.insert((sth){i,(int)s1});
	}
	int ti=m,ct=0;
	while(!tp.empty())
	{
		sth sb=*tp.begin();
		if(sb.ti<=0)break;
		tp.erase(sb);
		ct+=k*(ti-sb.ti);ti=sb.ti;
		int a=sb.id;
		h1[a]-=1ll*(t1[a]-ti)*h[a];
		t1[a]=ti;
		int lct=ct;
		while(h1[a]<h[a])
		{
			if(ct==0)return 0;
			ct--,h1[a]+=p;ct1++;
		}
		int s1=ti-h1[a]/h[a];
		if(s1>0)tp.insert((sth){a,s1});
	}
	ct+=ti*k;
	for(int i=1;i<=n;i++)
	{
		h1[i]-=1ll*t1[i]*h[i];
		while(h1[i]<s[i])
		{
			if(ct==0)return 0;
			ct--;h1[i]+=p;
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)scanf("%d%d",&s[i],&h[i]);
	long long lb=0,rb=1e13,as=1e13;
	while(lb<=rb)
	{
		long long mid=(lb+rb)>>1;
		if(solve(mid))as=mid,rb=mid-1;
		else lb=mid+1;
	}
	printf("%lld\n",as);
}