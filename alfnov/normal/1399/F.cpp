#include<bits/stdc++.h>
using namespace std;
int L[3005],R[3005],t[6005];
short mp[6005][6005],f[6005][6005];
vector<int>g[6005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&L[i],&R[i]);
			t[++m]=L[i],t[++m]=R[i];
		}
		sort(t+1,t+m+1);
		m=unique(t+1,t+m+1)-t-1;
		for(int i=1;i<=m;i++)
		{
			g[i].clear(); 
			for(int j=i;j<=m;j++)mp[i][j]=f[i][j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int l=lower_bound(t+1,t+m+1,L[i])-t;
			int r=lower_bound(t+1,t+m+1,R[i])-t;
			g[r].push_back(l);
			mp[l][r]++;
		}
		for(int i=1;i<=m;i++)f[i][i]=mp[i][i];
		for(int l=2;l<=m;l++)for(int i=1;i<=m-l+1;i++)
		{
			int j=i+l-1;
			f[i][j]=f[i][j-1];
			for(int k=0;k<g[j].size();k++)
			{
				int cu=g[j][k];
				if(cu<=i)continue;
				f[i][j]=max(0+f[i][j],f[i][cu-1]+f[cu][j]);
			}
			f[i][j]+=mp[i][j];
		}
		cout<<f[1][m]<<endl;
	}
	return 0;
}