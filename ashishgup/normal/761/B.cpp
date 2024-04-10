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

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

int main()
{
	ll n,l;
	cin>>n>>l;
	vll a(2*n);
	vll b(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>b[i];
	}
	ll sta0=a[0];
	ll stb0=b[0];
	for(ll i=0;i<n-1;i++)
	{
		a[i]=a[i+1]-a[i];
		b[i]=b[i+1]-b[i];
	}
	a[n-1]=(l-a[n-1])+sta0;
	b[n-1]=(l-b[n-1])+stb0;
	for(ll i=n;i<2*n;i++)
	{
		a[i]=a[i-n];
	}
	bool check=false;
	for(ll i=0;i<n;i++)
	{
		vll c=vll(a.begin()+i,a.begin()+i+n);
		if(c==b)
		{
			check=true;
		}
	}
	if(check)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}