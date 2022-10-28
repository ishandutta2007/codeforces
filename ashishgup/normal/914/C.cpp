#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e3+5;
const int MOD=1e9+7;

int n, k;
string s;
int cache[N][N][2];

int isk(int n)
{
	int cnt=0;
	while(n>1)
	{
		int ones=0;
		while(n>0)
		{
			ones+=n%2;
			n/=2;
		}
		n=ones;
		cnt++;
		if(cnt>k)
			return 0;
	}
	return (cnt==k-1);
}

int dp(int i, int cnt, int check)
{
	if(i>=n)
	{
		if(cnt==0)
			return 0;
		if(isk(cnt))
			return 1;
		return 0;
	}
	int &ans=cache[i][cnt][check];
	if(ans!=-1)
		return ans;
	if(check)
	{
		ans=dp(i+1, cnt, 1) + dp(i+1, cnt+1, 1);
	}
	else
	{
		if(s[i]=='1')
		{
			ans=dp(i+1, cnt, 1) + dp(i+1, cnt+1, 0);
		}
		else
		{
			ans=dp(i+1, cnt, check);
		}
	}
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>s>>k;
	if(k==0)
	{
		cout<<1;
		return 0;
	}
	n=s.size();
	int ans=dp(0, 0, 0);
	if(k==1)
	{
		ans=(ans-1+MOD)%MOD;
	}
	cout<<ans;
	return 0;
}