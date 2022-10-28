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
#define ff first
#define ss second

typedef long long ll;
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
	ll n;
	cin>>n;
	vector<string> v(n);
	for(ll i=0;i<n;i++)	
	{
		cin>>v[i];
	}
	for(ll i=n-2;i>=0;i--)
	{
		ll a=v[i].size();
		ll b=v[i+1].size();
		ll j=0;
		string sta=v[i];
		string stb=v[i+1];
		bool checksmall=false;
		for(j=0;j<min(a,b);j++)
		{
			if(sta[j]>stb[j])
			{
				break;
			}
			if(sta[j]<stb[j])
			{
				checksmall=true;
				break;
			}
		}
		if(checksmall)
			continue;
		v[i].erase(j,6*1e5);
	}
	for(ll i=0;i<n;i++)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}