#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n;
ll a[MAXN];
int x[65],y[65],p[125],G[125][125],dis[125][125];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    	for(int j=0;j<=60;j++)
    		if(a[i]&(1ll<<j))
			{
				if(!x[j])x[j]=i;
				else if(!y[j])y[j]=i;
				else return 0*printf("3\n");
			}
	int cnt=0;
	for(int j=0;j<=60;j++)
		p[++cnt]=x[j],p[++cnt]=y[j];
	sort(p+1,p+cnt+1);
	cnt=unique(p+1,p+cnt+1)-p-1;
	for(int j=0;j<=60;j++)
	{
		if(!x[j] || !y[j])continue;
		x[j]=lower_bound(p+1,p+cnt+1,x[j])-p;
		y[j]=lower_bound(p+1,p+cnt+1,y[j])-p;
		G[x[j]][y[j]]=G[y[j]][x[j]]=1;
	}
	int ans=1<<29;
	for(int r=0;r<=60;r++)
	{
		if(!x[r] || !y[r])continue;
		G[x[r]][y[r]]=G[y[r]][x[r]]=0;
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				if(G[i][j])dis[i][j]=1;
				else dis[i][j]=1<<29;
		for(int k=1;k<=cnt;k++)
			for(int i=1;i<=cnt;i++)
				for(int j=1;j<=cnt;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		ans=min(ans,dis[x[r]][y[r]]+1);
	}
	if(ans>=(1<<29))cout<<-1<<endl;
	else cout<<ans<<endl;
    return 0;
}