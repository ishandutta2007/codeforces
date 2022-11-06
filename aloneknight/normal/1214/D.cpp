#include<bits/stdc++.h>
using namespace std;
int n,m,f[1000005],vis[1000005];char c[1000005];
int gt(int a,int b){return (a-1)*m+b;}
void cmn(int &a,int b){a=min(a,b);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",c+(i-1)*m+1);
	for(int i=1;i<=n*m;i++)f[i]=0;
	f[n*m]=1;
	for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)if(f[gt(i,j)])
	{
		if(i>1&&c[gt(i-1,j)]=='.')f[gt(i-1,j)]=1;
		if(j>1&&c[gt(i,j-1)]=='.')f[gt(i,j-1)]=1;
	}
	if(!f[1]){puts("0");return 0;}
	int x=1,y=1;
	while(x!=n||y!=m)
	{
		if(x<n&&f[gt(x+1,y)])x++;
		else if(y<m&&f[gt(x,y+1)])y++;
		vis[gt(x,y)]++;
	}
	x=1,y=1;vis[n*m]=0;
	while(x!=n||y!=m)
	{
		if(y<m&&f[gt(x,y+1)])y++;
		else if(x<n&&f[gt(x+1,y)])x++;
		if(vis[gt(x,y)]){puts("1");return 0;}
	}
	puts("2");
	return 0;
}