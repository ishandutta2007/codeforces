#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=1000000007;
typedef long double lb;
int n,m,i,j,t,k,tot,a[505][505],b[505][505],c[505][505],d[505][505],q,ans[505][505],u,v,x,y;
char e[505][505];
int s[255][505][505];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=n;++i)
		scanf("%s",e[i]+1);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(e[i][j]=='R');
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+(e[i][j]=='G');
			c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+(e[i][j]=='Y');
			d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+(e[i][j]=='B');
		}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			for(k=1;k<=i&&k<=j;++k)
			{
				if(a[i][j]+a[i-k][j-k]-a[i-k][j]-a[i][j-k]!=k*k)
					break;
				if(b[i][j+k]+b[i-k][j]-b[i-k][j+k]-b[i][j]!=k*k)
					break;
				if(c[i+k][j]+c[i][j-k]-c[i][j]-c[i+k][j-k]!=k*k)
					break;
				if(d[i+k][j+k]+d[i][j]-d[i][j+k]-d[i+k][j]!=k*k)
					break;
			}
			ans[i][j]=k-1;
		}
	for(i=1;i<=250;++i)
		for(j=1;j<=n;++j)
			for(k=1;k<=m;++k)
				s[i][j][k]=(ans[j][k]>=i)-s[i][j-1][k-1]+s[i][j][k-1]+s[i][j-1][k];
	while(q--)
	{
		scanf("%d %d %d %d",&u,&v,&x,&y);
		int l=1,r=min((x-u+1)/2,(y-v+1)/2)+1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(s[mid][x-mid][y-mid]-s[mid][u+mid-2][y-mid]-s[mid][x-mid][v+mid-2]+s[mid][u+mid-2][v+mid-2]>0)
				l=mid+1;
			else
				r=mid;
		}
		printf("%d\n",4*(l-1)*(l-1));
	}
}