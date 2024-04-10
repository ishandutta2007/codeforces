#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,ta,tb,k;
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&ta,&tb,&k);
	long long a[n+1],b[m+1];
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%I64d",&b[i]);
	a[0]=-1000000000;
	if(k>=n) return 3-printf("-1\n");
	long long res=0;
	int idx=1;
	for(int i=0;i<=k;i++)
    {
        while(idx<=m&&b[idx]<a[i+1]+ta) idx++;
        if(idx+k-i>m) return 3-printf("-1\n");
        res=max(res,b[idx+k-i]+tb);
    }
    printf("%I64d\n",res);
	return 0;
}