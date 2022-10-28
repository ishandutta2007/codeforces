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
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

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
	ll n,x;
	cin>>n>>x;
	vll a(n),b(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll score=LLONG_MAX;
	ll storei;
	ll storej;
	for(ll i=0;i<n;i++)
	{
		ll cur=a[i];
		ll reqd=x-a[i];
		auto it=lower_bound(b.begin(),b.end(),reqd);
		if(it==b.end())
		{
			continue;
		}
		ll sec=*it;
		if(cur+sec<score)
		{
			storei=i;
			storej=it-b.begin();
		}
		score=min(score,cur+sec);
	}
	multiset<ll> a1;
	multiset<ll> b1;
	for(ll i=0;i<n;i++)
	{
		if(i!=storei)
		{
			a1.insert(a[i]);
		}
		if(i!=storej)
		{
			b1.insert(b[i]);
		}
	}
	ll maxrank=1;
	for(auto it:a1)
	{
		ll reqd=max(0LL,score-it);
	//	trace2(reqd,maxrank);
		auto it2=b1.lower_bound(reqd);
		if(it2==b1.end())
		{
			continue;
		}
		maxrank++;
		b1.erase(b1.find(*it2));
	}
	cout<<"1 "<<maxrank;
	return 0;	
}