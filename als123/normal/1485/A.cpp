#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
int solve (int x,int y)
{
	if (y==1) return 100;
	int cnt=0;
	while (x>0)
	{x=x/y;cnt++;
	}
	return cnt;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);int ans=100;
		for (int u=0;u<=30;u++)	ans=min(ans,solve(a,b+u)+u);
		printf("%d\n",ans);
	}
	return 0;
}