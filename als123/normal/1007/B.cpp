#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
LL f[N];
LL C1[300][300];
LL gcd (LL x,LL y)	{return x==0?y:gcd(y%x,x);}
LL cnt[8];
LL g[10];
bool check1 (LL x,LL y,LL z)
{
	g[0]=g[1]=g[2]=0;
	if (x==0||x==3||x==6||x==5) g[0]++;
	if (y==1||y==4||y==6||y==3) g[1]++;
	if (z==2||z==5||z==6||z==4) g[2]++;
	return g[0]*g[1]*g[2]>0;
}
bool check (LL x,LL y,LL z)
{
	if (check1(x,y,z)) return true;
	if (check1(x,z,y)) return true;
	if (check1(y,z,x)) return true;
	if (check1(y,x,z)) return true;
	if (check1(z,x,y)) return true;
	if (check1(z,y,x)) return true;
	return false;
}
int main()
{
	for (LL u=1;u<N;u++)
		for (LL i=u;i<N;i=i+u)
			f[i]++;
	C1[0][0]=1;
	for (LL u=1;u<=250;u++)
	{
		C1[u][0]=1;
		for (LL i=1;i<=u;i++)	C1[u][i]=C1[u-1][i-1]+C1[u-1][i];
	}
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		LL a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		LL A=f[a],B=f[b],C=f[c];
		LL AB=f[gcd(a,b)],AC=f[gcd(a,c)],BC=f[gcd(b,c)];
		LL ABC=f[gcd(gcd(a,b),gcd(b,c))];
		cnt[0]=A-AB-AC+ABC;
		cnt[1]=B-AB-BC+ABC;
		cnt[2]=C-AC-BC+ABC;
		cnt[3]=AB-ABC;
		cnt[4]=BC-ABC;
		cnt[5]=AC-ABC;
		cnt[6]=ABC;
		/*for (LL u=0;u<=6;u++)	printf("%lld ",cnt[u]);
		printf("\n");*/
		LL ans=0;
		for (LL u=0;u<=6;u++)
			for (LL i=u;i<=6;i++)
				for (LL j=i;j<=6;j++)
					if (check(u,i,j))
					{
					//	printf("%lld %lld %lld\n",u+1,i+1,j+1);
						memset(g,0,sizeof(g));
						g[u]++;g[i]++;g[j]++;
						LL lalal=1;
						for (LL k=0;k<=6;k++)
						{
							if (g[k]==0) continue;
							/*if (u+i+j==18)
								printf("%lld %lld %lld\n",C1[cnt[k]+g[k]-1][g[k]],cnt[k]+g[k]-1,g[k]);*/
							lalal=lalal*C1[cnt[k]+g[k]-1][g[k]];
						}
						//printf("%lld %lld %lld %lld\n",u,i,j,lalal);
						ans=ans+lalal;
					}
		printf("%lld\n",ans);
	}
	return 0;
}