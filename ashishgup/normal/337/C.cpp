#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int MOD=1e9+9;

int n, m, k;

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	int blocks=min(n/k, n-m);
	int leftover=m - (k-1)*blocks;
	if(leftover<=0)
	{
		int ans=m;
		cout<<m;
		return 0;
	}
	int doubled=leftover/k;
	int covered=(k-1)*blocks + leftover%k;
	int ans=0;
	if(doubled>=1)
	{
		int gp=2*(pow(2LL, doubled, MOD) - 1);
		gp%=MOD;
		ans=gp * k;
		ans%=MOD;
	}
	ans+=covered;
	ans%=MOD;
	cout<<ans;
}