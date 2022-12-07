#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=105;
const LL MAX=(1<<30);
struct qq
{
	LL p,l;
}s[N];
LL n;
bool cmp (qq x,qq y)	{return x.p<y.p;}
void Up (LL &x,LL y)	{x=x>y?x:y;}
LL f[N][N][2];
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++) scanf("%lld%lld",&s[u].p,&s[u].l);
	sort(s+1,s+1+n,cmp);
	s[0].p=-MAX;LL ans=0;
	for (LL u=0;u<=n;u++)//
		for (LL i=0;i<=u;i++)
			for (LL d=0;d<=1;d++)
			{
				ans=max(ans,f[u][i][d]);
				LL now=s[i].p+d*s[i].l;
				//printf("%lld %lld %lld %lld\n",u,i,d,f[u][i][d]);
				if (s[u+1].p+s[u+1].l>=now)//
				{
					if (now<=s[u+1].p) Up(f[u+1][u+1][1],f[u][i][d]+s[u+1].l);
					else Up(f[u+1][u+1][1],f[u][i][d]+s[u+1].l-(now-s[u+1].p));
				}
				else Up(f[u+1][i][d],f[u][i][d]);
				LL mx=now,a=i,b=d;
				for (LL k=u+1;k<=n;k++)// 
				{
					LL t=s[k].p-s[k].l;
					if (s[k].p>mx)	{a=k;b=0;mx=s[k].p;}
					if (t<=s[u+1].p)//
					{
						if (t>=now) Up(f[k][a][b],f[u][i][d]+mx-t);
						else Up(f[k][a][b],f[u][i][d]+mx-now);
					}
					if (s[k].p+s[k].l>mx)	{a=k;b=1;mx=s[k].p+s[k].l;}
				}
			}
	printf("%lld\n",ans);
	return 0;
}