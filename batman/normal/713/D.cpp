#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1005)
#define INF ((ll)1e9)
#define K ((ll)10)

ll n,m,q,lft[N][N],tvn[N],mini[N][N][K],dp[N][N],maxi[N][N][K][K];
bool a[N][N];

ll maxim(ll x1,ll y1,ll x2,ll y2)
{
	ll k1=tvn[x2-x1+1],k2=tvn[y2-y1+1];
	return  max({maxi[x2][y2][k1][k2],
			maxi[x1+(1<<k1)-1][y1+(1<<k2)-1][k1][k2],
			maxi[x1+(1<<k1)-1][y2][k1][k2],
			maxi[x2][y1+(1<<k2)-1][k1][k2]});
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	scanf("%d%d",&n,&m);
	for(int i=1,num=0,t=1;i<N;i++)
	{
		if(i>=t*2)t*=2,num++;
		tvn[i]=num;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]),lft[i][j]=a[i][j]?lft[i][j-1]+1:0;
	for(int j=0;j<m;j++)
		for(int i=n-1;i>=0;i--)
		{
			mini[i][j][0]=lft[i][j];
			for(int k=1;k<K;k++)
				mini[i][j][k]=min(mini[i][j][k-1],(i+(1<<(k-1))>=n)?INF:mini[i+(1<<(k-1))][j][k-1]);
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			ll l=0,r=min(i,j)+2;
			while(l<r-1)
			{
				ll mid=l+r>>1,k=tvn[mid];
				if(min(mini[i-mid+1][j][k],mini[i-(1<<k)+1][j][k])>=mid)l=mid;
				else r=mid;
			}
			dp[i][j]=l;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			maxi[i][j][0][0]=dp[i][j];
			for(int k=1;k<K;k++)maxi[i][j][0][k]=max(maxi[i][j][0][k-1],(j-(1<<(k-1))<0)?0:maxi[i][j-(1<<(k-1))][0][k-1]);
			for(int k1=1;k1<K;k1++)
				for(int k2=0;k2<K;k2++)
				{
					if(i-(1<<k1)+1<0 || j-(1<<k2)+1<0)continue;
					maxi[i][j][k1][k2]=max(maxi[i][j][k1-1][k2],maxi[i-(1<<(k1-1))][j][k1-1][k2]);
				}
		}
	scanf("%d",&q);
	while(q--)
	{
		ll x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1--;y1--;x2--;y2--;
		ll l=0,r=min(x2-x1,y2-y1)+2;
		while(l<r-1)
		{
			ll mid=l+r>>1;
			if(maxim(x1+mid-1,y1+mid-1,x2,y2)>=mid)l=mid;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}