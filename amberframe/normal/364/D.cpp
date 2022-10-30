#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>

using namespace std;
typedef long long LL;
const int maxn = 1000005;

int irand() {int w=(rand()<<15)^rand();return w<0?-w:w;}

LL a[maxn],d[maxn],cnt[maxn];int n,tot;LL ans=1;
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
int findp(LL num) {
	int lb=1,rb=tot+1;
	while (rb-lb>1) {
		int mid=lb+rb>>1;
		d[mid]<=num?lb=mid:rb=mid;
	}
	return lb;
}
void work(LL num)
{
	tot=0;
	for (LL i=1;i*i<=num;i++)
	if (num%i==0) {
		d[++tot]=i;
		if (i*i!=num) d[++tot]=num/i;
	}
	sort(d+1,d+tot+1);
	for (int i=1;i<=tot;i++) cnt[i]=0;
	for (int i=1;i<=n;i++) ++cnt[findp(gcd(a[i],num))];
	for (int i=tot;i>=1;i--)
	{
		LL sum=cnt[i];
		for (int j=i+1;j<=tot;j++)
		if (d[j]%d[i]==0) sum+=cnt[j];
		if (sum>=(n+1)/2) {ans=max(ans,d[i]);return ;}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("apple.in","r",stdin);
		freopen("apple.out","w",stdout);
	#endif
	scanf("%d",&n);srand(2333666);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while (clock()<1900) work(a[irand()%n+1]);
	printf("%lld",ans);
	return 0;
}