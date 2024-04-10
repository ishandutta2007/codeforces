#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=1e9+7;
ll inv[100005],val[100005],K;

ll cal(ll p,ll k)
{
	val[0]=1;
	p%=MOD;
	ll t=p;
	for(ll i=1;i<=k;++i,t=t*p%MOD)
		val[i]=(val[i-1]+t)%MOD;
	for(ll i=1;i<=k;++i)
		val[i]=(val[i]*inv[i+1])%MOD;
	for(ll i=2;i<=K;++i)
	{
		for(ll j=1;j<=k;++j)
			val[j]=(val[j-1]+val[j])%MOD;
		for(ll j=1;j<=k;++j)
			val[j]=(val[j]*inv[j+1])%MOD;
	}
	//cout << "cal " << p << " " << k << " = " << val[k] << "\n";
	return val[k];
}

int main()
{jizz
	ll n,ans=1,cnt;
	cin >> n >> K,inv[1]=1;
	if(n==1)
		return cout << "1\n",0;
	for(ll i=2;i<=100000;++i)
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(ll i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			cnt=0;
			while(n%i==0)
				n/=i,++cnt;
			ans=ans*cal(i,cnt)%MOD;
		}
	}
	if(n>1) ans=ans*cal(n,1)%MOD;
	cout << ans << "\n";
}