#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,Mx,Test_num;
int sum[32768],lg[32768],pre[17];
int nx[32768][17];
int f[17][32768][17];
typedef pair<int,int> P;
P from[17][32768][17];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void print(int x,int y,int z)
{
	if(!x)return ;
	print(x-1,from[x][y][z].first,from[x][y][z].second);
	for(int i=0;i<n;++i)
		if(((y^from[x][y][z].first)>>i)&1 && i+1!=z)
		{
			printf("%d %d\n",i+1-pre[i+1],z-pre[z]);
			for(int j=i+1;j<=n;++j)++pre[j];
		}
}
inline void solve()
{
	scanf("%d",&n),Mx=(1<<n)-1,lg[0]=-1;
	for(int i=1;i<=n;++i)scanf("%d",&sum[1<<(i-1)]),pre[i]=0;
	for(int i=1;i<=Mx;++i)
	{
		sum[i]=sum[lowbit(i)]+sum[i^lowbit(i)],lg[i]=lg[i>>1]+1;
		for(int j=lg[i]+1;j;--j)nx[i][j]=((i>>(j-1))&1? j:nx[i][j+1]);
	}
	for(int i=0;i<=n;++i)for(int j=0;j<=Mx;++j)for(int k=0;k<=n;++k)f[i][j][k]=inf;
	f[0][0][0]=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<Mx;++j)
			for(int k=0;k<=n;++k)
				if(f[i][j][k]<inf)
					for(int l=Mx^j;l;(--l)&=Mx^j)
						if(k<=lg[l] && f[i][j][k]<sum[l] && sum[l]<f[i+1][j|l][nx[l][k+1]])
							f[i+1][j|l][nx[l][k+1]]=sum[l],from[i+1][j|l][nx[l][k+1]]=P(j,k);
	for(int i=n;;--i)for(int j=1;j<=n;++j)if(f[i][Mx][j]<inf)return printf("%d\n",n-i),print(i,Mx,j);
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}