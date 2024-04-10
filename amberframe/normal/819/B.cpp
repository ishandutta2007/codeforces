#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;
typedef long long LL;
const int maxn = 7000005;
const int N = 2000001;
const int M = 5000000;

int p[maxn],n,sum[maxn];LL sumi[maxn];
LL ans=1ll<<50;int ansi;

void add(int x,int w)
{
	for (int i=x;i<=M;i+=i&-i)
		sum[i]++,sumi[i]+=w; 
}
void del(int x,int w)
{
	for (int i=x;i<=M;i+=i&-i)
		sum[i]--,sumi[i]-=w; 
}
int query(int x)
{
	int res=0;
	for (int i=x;i;i-=i&-i)
		res+=sum[i];
	return res;
}
LL queryi(int x)
{
	LL res=0;
	for (int i=x;i;i-=i&-i)
		res+=sumi[i];
	return res;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("shifts.in","r",stdin);
		//freopen("shifts.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]),add(p[i]-i+N,p[i]-i);
	for (int i=0;i<n;)
	{
		LL sum=0;
		LL a=query(-i+N),b=queryi(-i+N);
		sum-=a*i+b;
		sum+=queryi(M)-b+(n-a)*i;
		if (sum<ans) ans=sum,ansi=(n-i)%n;
		
		i++;
		del(p[i]-i+N,p[i]-i);
		add(p[i]-i+N-n,p[i]-i-n);
	}
	printf("%lld %d",ans,ansi);
	return 0;
}