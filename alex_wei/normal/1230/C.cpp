#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,d[8],pd[8],p[8][8],x[50],y[50],ans,sum;
void check()
{
	int tmp=0;
	for(int i=1;i<=6;i++)
		for(int j=1;j<=i;j++)
			p[i][j]=p[j][i]=1;
	for(int i=1;i<=m;i++){
		if(p[d[x[i]]][d[y[i]]])
			tmp++,p[d[x[i]]][d[y[i]]]=p[d[y[i]]][d[x[i]]]=0;
	}
	ans=max(ans,tmp);
}
void dfs(int pos)
{
	if(pos>n){check();return;}
	for(int i=1;i<7;i++)
		d[pos]=i,dfs(pos+1),d[pos]=0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>x[i]>>y[i];
	dfs(1);
	cout<<ans;
    return 0;
}