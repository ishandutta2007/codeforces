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

ll n,m,c;
vll v;
vll pref;

void update1(ll i,ll k)
{
	while(i<=n)
	{
		pref[i]+=k;
		pref[i]=pref[i]%c;
		i+=(i&(-i));
	}
}

ll prefsum(ll i)
{
	ll sum=0;
	while(i>0)
	{
		sum+=pref[i];
		i-=(i&(-i));
	}
	return sum;
}

int main()
{
	IOS;
	cin>>n>>m>>c;
	v=vll (n);
	vll b1 (m,0);
	pref=vll(n+1,0);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(ll i=0;i<m;i++)
	{
	    cin>>b1[i];
	}
	for(ll i=1;i<=m;i++)
	{
		update1(i,b1[i-1]);
		update1(i+n-m+1,-1*b1[i-1]);
	}
	for(ll i=0;i<n;i++)
	{
		//cout<<i<<" "<<v[i]<< " "<<pref[i+1]<<" "<<endl;
		ll ans=(v[i]+prefsum(i+1))%c;
		if(ans<0)
		{
			ans+=c;
		}
		cout<<ans<<" ";
	}
}