#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)3030)

ll n,m,b,k,x[N],y[N],lft[N][N],rght[N][N];
ll v[2][30],sz[2];
long long ans;
bool mark[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>b>>k;
	for(int i=0;i<b;i++)
	{
		cin>>x[i]>>y[i];x[i]--;y[i]--;
		mark[x[i]][y[i]]=1;
	}
	for(int i=0;i<n;i++)
	{
		lft[i][0]=-1;
		for(int j=1;j<=m;j++)lft[i][j]=mark[i][j-1]?j-1:lft[i][j-1];
		rght[i][m-1]=-1;
		for(int j=m-2;j>=0;j--)rght[i][j]=mark[i][j+1]?j+1:rght[i][j+1];
	}
	for(int t=0;t<b;t++)
	{
		sz[0]=sz[1]=0;
		for(int i=0;i<30;i++)v[0][i]=-1,v[1][i]=m;
		//cout<<x[t]<<" "<<y[t]<<"|||||||| \n";
		for(int i=x[t];i<n;i++)
		{
		//	cout<<i<<"... \n";
			for(int j=0,ex=lft[i][y[t]+1];j<k+1 && ex!=-1;j++,ex=lft[i][ex])
				v[0][sz[0]++]=ex;
			sort(v[0],v[0]+sz[0],greater <int>());
			sz[0]=min(sz[0],k+1);
			for(int p=1;p<=k;p++)
			{
				ll q=k-p;
				if(sz[0]<p || sz[1]<q)continue;
		//		cout<<p<<"\n";
		//		cout<<v[0][p-1]<<" "<<v[0][p]<<" "<<v[1][0]<<" "<<y[t]<<"\n";
				ans+=1LL*(v[0][p-1]-v[0][p])*((q==0)?(v[1][0]-y[t]):v[1][q]-v[1][q-1])*(x[t]+1);
		//		cout<<"ans :"<<ans<<"\n";
			}
			if(i==n-1)continue;
			for(int j=0,ex=rght[i+1][y[t]];j<k+1 && ex!=-1;j++,ex=rght[i+1][ex])
				v[1][sz[1]++]=ex;
			sort(v[1],v[1]+sz[1]);
		//	cout<<"v[1] :\n";
		//	for(int j=0;j<sz[1];j++)cout<<v[1][j]<<" ";
		//	cout<<"\n";
			sz[1]=min(sz[1],k+1);
		}
	}
	cout<<ans;
	return 0;
}