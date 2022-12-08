#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=155;
int n,k,s,q[N],f[2][N][N*N];
inline void work()
{
	sort(q+1,q+n+1);
	int ans=0;
	for(int i=1;i<=k;i++)ans+=q[i];
	printf("%d\n",ans);
}
int main()
{
	scanf("%d%d%d",&n,&k,&s);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	if(s>=n*(n-1)/2)return work(),0;
	memset(f,60,sizeof(f));
	f[0][0][0]=0;
	int now=0,lst=0;
	for(int i=1;i<=n;i++)
	{
		now^=1;
		memset(f[now],60,sizeof(f[now]));
		for(int j=0;j<=k;j++)
			for(int p=0;p<=s;p++)
			{
				f[now][j][p]=f[lst][j][p];
				if(p>=(i-j)&&j)f[now][j][p]=min(f[now][j][p],f[lst][j-1][p-(i-j)]+q[i]);
			}
		lst=now;
	}
	int ans=1e9;
	for(int i=0;i<=s;i++)ans=min(ans,f[now][k][i]);
	printf("%d\n",ans);
	return 0;
}