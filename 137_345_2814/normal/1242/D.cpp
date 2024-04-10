#include<cstdio>
using namespace std;
#define ll long long
ll n,k,T;
ll doit(ll n,ll k)
{
	if(n==1)return k*(k+1)/2;
	ll tp=(n-1)/k+1,v1=doit(tp,k),tp2=(n-1)%k+1;
	ll f1=(tp-1)*(k*k+1),f2=v1-f1;
	if(tp2*k<f2)return (f1*2+tp2*2*k-k+1)*k/2;
	else if((tp2-1)*k>=f2)return (f1*2-k+3+tp2*2*k)*k/2;
	else return (f1*2-k+1+tp2*2*k)*k/2+tp2*k-f2+1;
}
ll solve(ll n,ll k)
{
	ll tp=(n-1)/(k*k+1)+1,st=doit(tp,k);
	if(n==st)return tp*(k+1);
	else return (n-tp+(n<st)-1)/k+n-tp+(n<st);
}
int main()
{
	scanf("%d",&T);
	while(T--)scanf("%lld%lld",&n,&k),printf("%lld\n",solve(n,k));
}