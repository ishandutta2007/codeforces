#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD=1e9+7;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
int geomsum(int n, int r)
{
	int T=1;
	int e=r%MOD;
	int total=0;
	while(n>0)
	{
		if(n&1)
			total=(total*e+T)%MOD;
		n/=2;
		T=(T*(e+1))%MOD;
		e=(e*e)%MOD;
	}
	return total;
}

int a, b, n, x;

int32_t main()
{
	IOS;
	cin>>a>>b>>n>>x;	
	int ans=0;
	int powa=pow(a, n, MOD);
	ans+=powa*x;
	ans%=MOD;
	int sum=geomsum(n, a);
	sum*=b;
	sum%=MOD;
	ans+=sum;
	ans%=MOD;
	cout<<ans;
	return 0;
}