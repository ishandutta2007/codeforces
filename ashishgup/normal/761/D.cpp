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
	ll n,l,r;
	cin>>n>>l>>r;
	vll a(n),b(n);
	vll c(n);
	vll index(n+1);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>c[i];
		index[c[i]]=i;
	}
	vpll v(n);
	for(ll i=0;i<n;i++)
	{
		v[i].first=c[i];
		v[i].second=a[i];
	}
	sort(v.begin(),v.end());
	vll d(n);
	d[0]=l-v[0].second;
	b[index[1]]=l;
	bool check=true;
	for(ll i=1;i<n;i++)
	{
		ll minval=d[i-1]+1+v[i].second;
		if(minval>r)
		{
			check=false;
			break;
		}
		else if(minval<l)
		{
			b[index[i+1]]=l;
		}
		else
		{
			b[index[i+1]]=minval;
		}
		d[i]=b[index[i+1]]-v[i].second;
	}
	if(!check)
	{
		cout<<"-1";
		return 0;
	}
	for(ll i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}	
	return 0;
}