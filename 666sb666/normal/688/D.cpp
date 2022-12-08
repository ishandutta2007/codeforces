#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000001;
int n,k,c[maxn],m[maxn][10],mxx=0,f[maxn][10],g[maxn],mx[maxn],num[maxn];
bool have[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]>mxx)mxx=c[i]; 
	}
	if(k>mxx)mxx=k;
	memset(f,0,sizeof(f));
	for(int i=2;i<=mxx;i++)if(!g[i])
		for(int j=i;j<=mxx;j+=i)
		{
			g[j]++;
			int p=j;
			m[j][g[j]]=i;
			while(!(p%i))p/=i,f[j][g[j]]++;
		}
	memset(have,0,sizeof(have));
	for(int i=1;i<=g[k];i++)have[m[k][i]]=true,num[m[k][i]]=f[k][i];
	for(int i=1;i<=n;i++)if(!(c[i]%k))
	{
		printf("Yes\n");
		return 0;
	}
	memset(mx,0,sizeof(mx));
	for(int i=1;i<=n;i++)
	{ 
		int x=c[i];
		for(int j=1;j<=g[x];j++)if(have[m[x][j]])mx[m[x][j]]=max(mx[m[x][j]],f[x][j]);
	}
	for(int i=1;i<=g[k];i++)if(mx[m[k][i]]<num[m[k][i]])
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}