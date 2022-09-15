#include<cstdio>

#include<algorithm>
using namespace std;
const int MAXN = 262144;

long long idx[MAXN*2];

long long getor()
{
	return idx[1];
}
void update(int a,long long v)
{
	a+=MAXN;
	idx[a]=v;
	while(a>1)
	{
		a/=2;
		idx[a] = idx[2*a] | idx[2*a+1];
	}
	return;
}
int main()
{
	int N, K, X;
	scanf("%d %d %d",&N,&K,&X);
	long long int mult=1;
	for(int i=0;i<K;i++) mult *= X;
	for(int i=0;i<N;i++) scanf("%lld",idx+MAXN+i);
	for(int i=MAXN-1;i>=1;i--)
		idx[i] = idx[2*i] | idx[2*i+1];
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		long long t=idx[i+MAXN];
		update(i, t*mult);
		ans=max(ans, getor());
		update(i,t);
	}
	printf("%lld\n",ans);
}