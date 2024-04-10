#include<bits/stdc++.h>
#define retrun return
#define cpnst const
typedef long long ll;
typedef double db;
typedef unsigned unt;
typedef unsigned long long ull;
using std::sort;
using std::min;
using std::max;
using std::swap;
using std::reverse;
struct pii{int x,y;};
bool operator<(const pii x,const pii y){return x.x^y.x?x.x<y.x:x.y<y.y;}
ll gcd(ll x,ll y){for(ll r=y;r;r=x%y,x=y,y=r);return x;}
int n,m,q;
char str[1111111];
ll a[1111111],b[1111111];

void exec()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=n;i++)scanf("%lld",a+i);
	for(i=1;i<=m;i++)scanf("%lld",b+i);
	ll G=0;
	for(i=2;i<=n;i++)G=gcd(G,abs(a[i]-a[i-1])); 
	for(i=1;i<=m;i++)
	{
		printf("%lld ",abs(gcd(G,a[1]+b[i])));
	}puts("");
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}