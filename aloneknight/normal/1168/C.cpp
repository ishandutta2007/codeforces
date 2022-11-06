#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
int n,Q,a[N],pre[N][22],lst[22];
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=0;j<20;j++)if(a[i]>>j&1)pre[i][j]=i;
		for(int j=0;j<20;j++)if(a[i]>>j&1)for(int k=0;k<20;k++)pre[i][k]=max(pre[i][k],pre[lst[j]][k]);
		for(int j=0;j<20;j++)if(a[i]>>j&1)lst[j]=i;
	}
	while(Q--)
	{
		int x,y;scanf("%d%d",&x,&y);bool ff=0;
		for(int i=0;i<20;i++)if((a[x]>>i&1)&&pre[y][i]>=x){puts("Shi");ff=1;break;}
		if(!ff)puts("Fou");
	}
	return 0;
}