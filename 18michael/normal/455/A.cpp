#include<cstdio>
#include<cstring>
#define Mx 100000
#define LL long long
int n;
LL cnt[100002]={},f[100002];
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),++cnt[x];
	f[1]=cnt[1];
	for(LL i=2;i<=Mx;++i)f[i]=max(f[i-1],f[i-2]+i*cnt[i]);
	printf("%lld",f[Mx]);
	return 0;
}