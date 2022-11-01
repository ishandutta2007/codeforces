#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (50*1001)
#define K (1001*1000)

ll n,m,xors[K],l[N],r[N],a[N],dp[N],ans[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<K;i++)xors[i]=xors[i-1]^i;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++)scanf("%d%d",&l[i],&r[i]),l[i]--,r[i]--;
	for(int i=0;i<n;i++)
	{
		dp[i]=a[i];
		for(int j=i+1;j<n;j++)dp[j]=max(dp[j-1],xors[max(a[i],a[j])]^xors[min(a[i],a[j])-1]);
		for(int j=0;j<m;j++)if(l[j]<=i && i<=r[j])ans[j]=max(ans[j],dp[r[j]]);
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);
    return 0;
}