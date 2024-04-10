#include<bits/stdc++.h>
using namespace std;
int n,m,p[105][105],ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		p[u][v]+=w;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int z=min(p[i][j],p[j][i]);
			p[i][j]-=z,p[j][i]-=z;
			for(int k=1;k<=n;k++){
				z=min(p[i][j],p[j][k]);
				p[i][j]-=z,p[j][k]-=z;
				p[i][k]+=z;
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans+=p[i][j];
	cout<<ans;
    return 0;
}