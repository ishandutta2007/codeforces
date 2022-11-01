#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1001*1000)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

int n,m,num[N];
ll ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		ll v,u;
		scanf("%d%d",&v,&u);
		num[v]++;num[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		ll ex=n-1-num[i];
		ans+=num[i]*(num[i]-1)+ex*(ex-1);
		ans-=ex*num[i];
	}
	printf("%I64d",ans/6);
    return 0;
}