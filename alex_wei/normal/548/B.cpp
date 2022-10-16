#include<bits/stdc++.h>
using namespace std;
int n,m,q,c[502][502],p[502][502],k[502];
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>c[i][j],p[i][j]=c[i][j]+p[i][j-1]*c[i][j];
			k[i]=max(k[i],p[i][j]);
		}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		c[x][y]=!c[x][y];
		k[x]=0;
		for(int j=1;j<=m;j++){
			p[x][j]=c[x][j]+p[x][j-1]*c[x][j];
			k[x]=max(k[x],p[x][j]);
		}
		int ans=0;
		for(int j=1;j<=n;j++)
			ans=max(ans,k[j]);
		cout<<ans<<endl; 
	}
    return 0;
}