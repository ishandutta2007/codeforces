#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=150;
LL f[N][N];
LL calc (LL t,LL x,LL y)
{
	if (t<0) return 0;
	x++;y++;

	memset(f,0,sizeof(f));
		f[1][1]=t;
	for (LL u=1;u<=x;u++)
	for (LL i=1;i<=y;i++)
	{
		f[u][i+1]+=(f[u][i]+1)/2;
		f[u+1][i]+=f[u][i]/2;
	}
	return f[x][y];
}
int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		LL t,x,y;
		scanf("%lld%lld%lld",&t,&x,&y);
		t=t-x-y;
		if (t<0) {printf("NO\n");continue;}
		//printf("%lld %lld",calc(t+1,x,y),calc(t,x,y));
		if (calc(t+1,x,y)!=calc(t,x,y))
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}