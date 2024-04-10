#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int md=1000000007;
map<int,int> mp,g[305];
map<int,int>::iterator ddq;
int n,i,j,k,x,jc[605],rjc[605],inv[605],a[305],p[305],size[305],w[305],cnt,f[305][305],sum[305];
int find(int x)
{
	return !p[x]?x:p[x]=find(p[x]);
}
bool cmp(int a,int b)
{
	return a>b;
}
int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int main()
{
	//freopen("ball.in","r",stdin);
	//freopen("ball.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		g[i].clear();
		for(k=a[i],x=2;1ll*x*x<=k;++x)
			if(k%x==0)
			{
				while(k%x==0)
				{
					g[i][x]++;
					k/=x;
				}
			}
		if(k>1)
			g[i][k]++;
	}
	inv[1]=1;
	for(i=2;i<=2*n;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=1;
	for(i=1;i<=2*n;++i)
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	for(i=1;i<n;++i)
		for(j=i+1;j<=n;++j)
			if(find(i)!=find(j))
			{
				mp.clear();
				for(ddq=g[i].begin();ddq!=g[i].end();ddq++)
					mp[ddq->first]+=ddq->second;
				for(ddq=g[j].begin();ddq!=g[j].end();ddq++)
					mp[ddq->first]+=ddq->second;
				if(mp.empty())
					p[find(i)]=find(j);
				else
				{
					for(ddq=mp.begin();ddq!=mp.end();ddq++)
						if((ddq->second)&1)
							break;
					if(ddq==mp.end())
						p[find(i)]=find(j);
				}
			}
	for(i=1;i<=n;++i)
		size[find(i)]++;
	for(i=1;i<=n;++i)
		if(find(i)==i)
			w[++cnt]=size[i];
	sort(w+1,w+1+cnt,cmp);
	for(i=1;i<=cnt;++i)
		sum[i]=sum[i-1]+w[i];
	f[1][w[1]-1]=jc[w[1]];
	for(i=1;i<cnt;++i)
		for(j=0;j<=sum[i];++j)
		{
			for(k=1;k<=w[i+1];++k)
				for(x=0;x<=j&&x<=k;++x)
					f[i+1][j-x+w[i+1]-k]=(f[i+1][j-x+w[i+1]-k]+1ll*f[i][j]*jc[w[i+1]]%md*C(j,x)%md*C(sum[i]+1-j,k-x)%md*C(w[i+1]-1,k-1)%md)%md;
		}
	printf("%d",f[cnt][0]);
	return 0;
}