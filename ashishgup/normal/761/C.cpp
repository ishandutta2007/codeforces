#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<vector<vector<ll> > > > vvvvll;
typedef vector<vector<vector<ll> > > vvvll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }


vector<string> s;
ll n,m;
vvvvll cache(51, vvvll(2, vvll(2, vll (2,-1))));
ll dp(ll i, ll d, ll a,ll sp)
{
	if(i==n)
	{
		//cout<<d<<" "<<a<<" "<<sp<<endl;
		if((d&&a)&&sp)
		{
			return 0;
		}
		else
		{
			return 1e9;
		}
	}
	//cout<<i<<" "<<d<<" "<<a<<" "<<sp<<endl;
	if(cache[i][d][a][sp]!=-1)
	{
		return cache[i][d][a][sp];
	}
	ll min1=LLONG_MAX;
	for(ll j=0;j<m;j++)
	{
		ll temp1=0;
		if(isalpha(s[i][j]))
		{
			temp1=min(j,m-j)+dp(i+1,d,1,sp);
		}
		else if(isdigit(s[i][j]))
		{
			temp1=min(j,m-j)+dp(i+1,1,a,sp);	
		}
		else
		{
			temp1=min(j,m-j)+dp(i+1,d,a,1);
		}
		min1=min(min1,temp1);
	}
	cache[i][d][a][sp]=min1;
	return cache[i][d][a][sp];
}
int main()
{
	cin>>n>>m;
	s=vector<string> (n);
	for(ll i=0;i<n;i++)
	{
		cin>>s[i];
	}
	ll ans=dp(0,0,0,0);
	cout<<ans;
	return 0;
}