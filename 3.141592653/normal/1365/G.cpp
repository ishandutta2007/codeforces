#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int popcnt[333333];
int g[333333],ss,n;
typedef long long ll;
ll ask(int x)
{
	register int i;
	int cnt=0;
	for(i=1;i<=n;i++)
		if(g[i]&(1<<x))cnt++;
	if(!cnt)return 0;
	printf("? %d ",cnt);
	for(i=1;i<=n;i++)
		if(g[i]&(1<<x))printf("%d ",i);
	puts(""),fflush(stdout);
	ll ret;
	scanf("%lld",&ret);
	return ret;
}
ll ans[333333];
ll call(ll x)
{
	register int i;
	ll ret=0;
	for(i=0;i<13;i++)
		if(!(g[x]&(1<<i)))ret|=ans[i];
	return ret;
}
int main()
{
	int Lm=1<<14;
	scanf("%d",&n);
	register int i;
	for(i=1;i<=Lm;i++)popcnt[i]=popcnt[i>>1]+(i&1);
	for(i=1;i<=Lm;i++)if(popcnt[i]==7)g[++ss]=i;
	for(i=0;i<13;i++)
		ans[i]=ask(i);
	printf("! ");
	for(i=1;i<=n;i++)
		printf("%lld ",call(i));
	puts(""),fflush(stdout);
}
/*
Just go for it.
*/