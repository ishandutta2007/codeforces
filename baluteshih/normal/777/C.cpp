#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int i,j,n,m,k,l,r,ans[100001],max,flag;
	scanf("%d%d",&n,&m);
	int map[n+1][m+1];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) scanf("%d",&map[i][j]);
	if(n<1000)
	{
		for(ans[0]=0,l=1;l<=n;l++)
		{	
			for(j=1,max=0;j<=m;j++,max=(i>max) ? i : max) 
				for(i=l+1;i<=n && map[i][j]>=map[i-1][j];i++) ;
			ans[l]=max-1;
			//printf("ans[%d] = %d\n",l,ans[l]);
		}
	}
	else
	{
		for(j=1;j<=m;j++) 
			for(i=n;i>=2;i--)
				map[i][j] = map[i][j]>=map[i-1][j];
		for(j=1;j<=m;j++) map[1][j]=1;
		for(j=1;j<=m;j++)
			for(i=2;i<=n;i++) map[i][j]+=map[i-1][j];//printf("map[%d][%d] = %d\n",i,j,map[i][j]);
	}
	scanf("%d",&k);
	while(k--) 
	{
		scanf("%d%d",&l,&r);
		if(n<1000)
			printf("%s\n",(ans[l]>=r) ? "Yes" : "No");
		else
		{
			flag=0;
			for(j=1;j<=m;j++)
				flag |= map[r][j]-map[l][j]>=r-l;
			flag|=l==r;
			printf("%s\n",(flag) ? "Yes" : "No");
		}	
	}
}