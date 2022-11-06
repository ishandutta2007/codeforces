//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=20;
int n,m,x,y,ans;
int dp[1<<N][N],used[N][N];
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		x=read()-1,y=read()-1;used[x][y]=used[y][x]=1;///
	}
	for(int i=0;i<n;i++)dp[1<<i][i]=1;
	for(int i=1;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			if(dp[i][j])
				for(int k=0;k<n;k++)
					if(used[j][k])
					{
						if((i&-i)>(1<<k))continue;
						if((i&-i)==(1<<k))ans+=dp[i][j];
						else if(!(i&(1<<k)))dp[i|(1<<k)][k]+=dp[i][j];
					}
	cout<<(ans-m)/2<<endl;
	return 0;
}