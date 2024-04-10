#include <stdio.h>
#include <algorithm>

typedef long long lli;
int n;
lli ti[100001], cost[100001];

int main()
{
	scanf("%d",&n);
	lli sum=0, prev=0;
	ti[0]=-987654321;
	for(int i=1;i<=n;i++) {
		scanf("%lld", ti+i);

		lli m1=cost[i-1]+20;
		lli m2=50+cost[(std::lower_bound(ti, ti+i+1, ti[i]-90+1)-ti)-1];
		lli m3=120+cost[(std::lower_bound(ti,ti+i+1,ti[i]-1440+1)-ti)-1];
		cost[i]=(m1<m2)?m1:m2;
		if(cost[i]>m3) cost[i]=m3;
		printf("%lld\n",cost[i]-cost[i-1]);
	}

	return 0;
}