#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long f[400001][20],mx[400001][20],sum[400001][20],m,a,b,c,las,cnt=1,v[400001],dep[400001];
int main()
{
	scanf("%d",&m);
	v[0]=1e17;
	for(int i=0;i<=19;i++)
	mx[1][i]=sum[1][i]=1e16,mx[0][i]=sum[0][i]=1e16;
	while(m--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		b^=las,c^=las;
		if(a==1)
		{
			++cnt;
			int tmp=b;
			if(v[b]<c)
			tmp=f[b][0];
			for(int i=19;i>=0;i--)
			if(mx[tmp][i]<c)
			tmp=f[tmp][i];
			if(v[tmp]<c)
			tmp=f[tmp][0];
			f[cnt][0]=tmp;
			mx[cnt][0]=v[tmp];
			v[cnt]=c;
			dep[cnt]=dep[tmp]+1;
			for(int i=1;i<=19;i++)
			f[cnt][i]=f[f[cnt][i-1]][i-1],
			mx[cnt][i]=max(mx[cnt][i-1],mx[f[cnt][i-1]][i-1]);
			sum[cnt][0]=v[tmp];
			for(int i=1;i<=19;i++)
			{
				sum[cnt][i]=sum[f[cnt][i-1]][i-1]+sum[cnt][i-1];
				if(sum[cnt][i]>1e16)
				sum[cnt][i]=1e16;
			}
		}
		else
		{
			long long ct=0,tp=b;
			if(c>=v[b])
			{
				c-=v[b],ct++;
				for(int i=19;i>=0;i--)
				if(sum[tp][i]<=c)
				c-=sum[tp][i],ct+=1<<i,tp=f[tp][i];
				printf("%lld\n",ct),las=ct;
			}
			else
			printf("0\n"),las=0;
		}
	}
}