#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)
ll n,m;
long long ans;
ll tvn[N],num[2][N];

int main()
{
	scanf("%I64d%I64d",&n,&m);
	tvn[0]=1;
	for(int i=1;i<=n;i++)tvn[i]=tvn[i-1]*2311;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		scanf("%I64d%I64d",&v,&u);
		num[0][v]+=tvn[u];
		num[0][u]+=tvn[v];
		num[1][v]+=tvn[u];
		num[1][u]+=tvn[v];
	}
	for(int i=1;i<=n;i++)num[1][i]+=tvn[i];
	sort(num[0]+1,num[0]+n+1);
	sort(num[1]+1,num[1]+n+1);
	for(int i=2,cnt=1,cnt2=1;i<=n;i++)
	{
		if(num[0][i]==num[0][i-1])ans+=cnt,cnt++;
		else cnt=1;
		if(num[1][i]==num[1][i-1])ans+=cnt2,cnt2++;
		else cnt2=1;
	}
	printf("%I64d",ans);
	return 0;
}