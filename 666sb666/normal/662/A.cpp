#include<cstdio>
const int N=5e5+5;
int n,ans;
long long a[N],b[N],c[N],x;
inline bool insert(long long val)
{
	for(int i=60;i>=0;i--)if(val&(1LL<<i))
	{
		if(!c[i]){c[i]=val;break;}
		val^=c[i];
	}
	return val>0;
}
inline bool check(long long val)
{
	for(int i=60;i>=0;i--)if(val&(1LL<<i)){val^=c[i];if(!val)return true;}
	if(!val)return true;return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]),x^=a[i],a[i]^=b[i],ans+=insert(a[i]);
	if(check(x))printf("%lld/%lld\n",(1LL<<ans)-1,1LL<<ans);else puts("1/1");
	return 0;
}