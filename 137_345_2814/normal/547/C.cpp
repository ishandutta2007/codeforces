#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int v[200001],ans[500001],ch[500001],pri[40001],cnt,n,m,g[500001],tmp,sum[500001];
long long as;
vector <int> lsj[200001];
void prime(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!ch[i])
		pri[++cnt]=i;
		for(int j=1;pri[j]*i<=n&&j<=cnt;j++)
		{
			ch[i*pri[j]]=1;
			if(i%pri[j]==0)
			break;
		}
	}
}
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		int x=i;
		for(int j=1;pri[j]*pri[j]<=x;j++)
		if(x%pri[j]==0)
		{
			ans[i]++;
			while(x%pri[j]==0)
			x/=pri[j];
		}
		if(x>1)
		ans[i]++;
	}
}
void pt(int n)
{
	for(int i=1;i<=n;i++)
	{
	if(v[i]>1)
	lsj[i].push_back(v[i]);
	for(int j=2;j*j<=v[i];j++)
	if(v[i]%j==0)
	{
		lsj[i].push_back(j);
		if(j*j!=v[i])
		lsj[i].push_back(v[i]/j);
	}
	}
}
long long pw(long long a,long long p)
{
	long long ans=1;
	while(p)
	{
		if(p&1) ans=ans*a;
		a=a*a;
		p>>=1;
	}
	return ans;
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	prime(500000);
	for(int i=1;i<=n;i++)
	for(int j=1;pri[j]*pri[j]<=v[i];j++)
	if(v[i]%pri[j]==0)
	{
		while(v[i]%pri[j]==0)
		v[i]/=pri[j];
		v[i]*=pri[j];
	}
	pt(n);
	init(500000);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a);
		if(!g[a])
		{
			int tp=0;
			for(int j=0;j<lsj[a].size();j++)
			{
				int sb=lsj[a][j];
				tp+=pw(-1,ans[sb])*sum[sb];
				sum[sb]++;
			}
			as=as+tmp+tp;
			tmp++;
			g[a]=1;
		}
		else
		{
			int tp=0;
			for(int j=0;j<lsj[a].size();j++)
			{
				int sb=lsj[a][j];
				sum[sb]--;
				tp+=pw(-1,ans[sb])*sum[sb];
			}
			tmp--;
			as=as-tmp-tp;
			g[a]=0;
		}
		printf("%lld\n",as);
	}
}//wkr