#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>

using namespace std;
const int maxn = 30005;
const int maxm = 1005;
const int N = 3e4;
const int M = 1e3;

int f[maxn][maxm];
int cnt[maxn],n,d,ans;
int findlim(int d)
{
	int sum=0;
	for (int i=d;i>=1;i--)
	{
		sum+=i;
		if (sum>N) return i;
	}
	return 0;
}
void upd(int &x,int y)
{
	x<y?x=y:0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("hunter.in","r",stdin);
		freopen("hunter.out","w",stdout);
	#endif
	scanf("%d %d",&n,&d);
	for (int o,i=1;i<=n;i++)
		scanf("%d",&o),++cnt[o];
	memset(f,-1,sizeof f);
	int bas=findlim(d);
	f[d][d-bas]=0;
	for (int i=1;i<=N;i++)
	for (int j=0;j<=M;j++)
	if (f[i][j]!=-1) {
		int v=f[i][j]+cnt[i];
		ans=max(ans,v);
		if (j>0&&j+bas-1>0&&j+bas+i-1<=N)
			upd(f[j+bas+i-1][j-1],v);
		if (j+bas+i<=N)
			upd(f[j+bas+i][j],v);
		if (j+bas+i+1<=N)
			upd(f[j+bas+i+1][j+1],v);
	}
	printf("%d",ans);
	return 0;
}