#include<bits/stdc++.h>
using namespace std;
const int N=100005;
#define ll long long
#define pb push_back
int n,tt,id[N],d[205][205],D[205][205];ll a[N];
vector<int>V[105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)for(int j=0;j<60;j++)if(a[i]>>j&1)V[j].pb(i);
	for(int i=0;i<60;i++)if(V[i].size()>2){puts("3");return 0;}
	for(int i=0;i<60;i++)for(int j=0;j<V[i].size();j++)if(!id[V[i][j]])id[V[i][j]]=++tt;
	for(int i=1;i<=tt;i++)for(int j=1;j<=tt;j++)d[i][j]=200;
	for(int i=0;i<60;i++)if(V[i].size()==2){int x=id[V[i][0]],y=id[V[i][1]];d[x][y]=d[y][x]=1;}
	for(int i=1;i<=tt;i++)for(int j=1;j<=tt;j++)D[i][j]=d[i][j];
	for(int i=1;i<=tt;i++)D[i][i]=0;
	int ans=200;
	for(int k=1;k<=tt;k++)
	{
		for(int i=1;i<=tt;i++)for(int j=1;j<=tt;j++)if(k!=i&&k!=j&&i!=j)ans=min(ans,D[i][j]+d[i][k]+d[k][j]);
		for(int i=1;i<=tt;i++)for(int j=1;j<=tt;j++)D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
	}
	printf("%d\n",ans==200?-1:ans);
	return 0;
}