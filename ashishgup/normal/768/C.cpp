#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

int main()
{
	IOS;
	ll n,k,x;
	cin>>n>>k>>x;
	vll f(1<<10,0);
	vll f2(1<<10,0);
	vll v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		f[v[i]]++;
	}
	ll ctbelow=0;
	for(ll i=0;i<k;i++)
	{
		ll ctbelow=0;
		for(ll j=0;j<(1<<10);j++)
		{
			f2[j]=0;
		}
		for(ll j=0;j<(1<<10);j++)
		{
			if(ctbelow%2)
			{
				f2[j]+=f[j]/2 + f[j]%2;
				f2[j^x]+=f[j]/2;
			}
			else
			{
				f2[j]+=f[j]/2;
				f2[j^x]+=f[j]/2 + f[j]%2;
			}
			ctbelow+=f[j];
		}
		for(ll j=0;j<(1<<10);j++)
		{
			f[j]=f2[j];
		}
	}
	ll ans1,ans2;
	for(ll i=0;i<(1<<10);i++)
	{
		if(f[i]>0)
		{
			ans1=i;
			break;	
		}
	}
	for(ll i=1023;i>=0;i--)
	{
		if(f[i]>0)
		{
			ans2=i;
			break;	
		}
	}
	cout<<ans2<<" "<<ans1;
	return 0;	
}