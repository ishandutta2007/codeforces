#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
ll tavan(ll a,ll b){ll res=1;while(b){res*=b%2?a:1;res%=MOD;a*=a;a%=MOD;b/=2;}return res;}
ll n,a[N],fen[N],num[N],fac[N],ans;
ll query(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}
ll update(ll x){for(;x<N;x+=x&-x)fen[x]++;}
int main()
{
	scanf("%I64d",&n);
	fac[0]=1;
	for(ll i=1;i<N;i++)fac[i]=(fac[i-1]*i)%MOD;
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		num[i]=(a[i]-1-query(a[i]))*fac[n-i];num[i]%=MOD;
		update(a[i]);
	}
	for(ll i=0;i<N;i++)fen[i]=0;
	ll tvn=tavan(2,MOD-2);
	for(ll i=n,sum=0;i>0;i--)
	{
		ll ex,ex2,p=query(a[i]);
		ex=p*fac[n-i];ex%=MOD;ex*=tvn;ex%=MOD;ex2=(n-i)*(n-i-1)/2;ex2%=MOD;ex*=ex2;ex%=MOD;ex+=MOD;ex%=MOD;
		ans+=ex;ans%=MOD;
		ex=(p)*(p-1)/2;ex%=MOD;ex*=fac[n-i];ex%=MOD;
		ans+=ex;ans%=MOD;
		ex=p*(sum+1);ex%=MOD;
		ans+=ex;ans%=MOD;
		sum+=num[i];sum%=MOD;
		update(a[i]);
	}
	printf("%I64d",ans);
	return 0;
}