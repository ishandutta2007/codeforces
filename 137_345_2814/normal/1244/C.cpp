#include<cstdio>
using namespace std;
long long n,m,p,q;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int exgcd(int a,int b,int &x,int &y)
{
	if(!b){x=1;y=0;return a;}
	int g=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return g;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	if(m%gcd(p,q)){printf("-1\n");return 0;}
	int x,y;int s=exgcd(p,q,x,y);
	long long t1=1ll*x*(m/s%(q/s))%(q/s),t2=1ll*y*(m/s%(p/s))%(p/s);
	if(t2<0)t2+=p/s;
	long long s1=(m-1ll*t2*q)/p;
	if(s1+t2>n||t2>n||s1<0){printf("-1\n");return 0;}
	printf("%lld %lld %lld\n",s1,t2,n-s1-t2);
}