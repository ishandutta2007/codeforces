#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

#define int long long

template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int MOD=1e9+7;

int n, m, k;
int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	if((n+m)%2 && k==-1)
	{
		cout<<"0";
		return 0;
	}
	int a=(n-1)%(MOD-1);
	int b=(m-1)%(MOD-1);
	int c=(a*b)%(MOD-1);
	int ans=pow(2LL, c, MOD);
	cout<<ans;
}