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
//	IOS;
	ll n;
	cin>>n;
	vpll v(n);
	ll a,b;
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].ff;
		cin>>v[i].ss;
	}
	a=v[0].ff;
	b=v[0].ss;
	priority_queue<pair<ll,ll>,vpll> pq;
	multiset<ll> s;
	for(ll i=1;i<n;i++)
	{
		if(v[i].ff<=a)
		{
			pq.push(v[i]);
		}
		else
		{
			s.insert(v[i].ss-v[i].ff+1);
		}
	}
	ll have=0;
	ll rank=s.size()+1;
	ll cur=0;
	while(a>0&&pq.size()>0)
	{
		pair<ll,ll> p=pq.top();
		while(p.ff==a)
		{
			s.insert(p.ss-p.ff+1);
			pq.pop();
			if(pq.size()==0)
				break;
			p=pq.top();
		}
		p=pq.top();
		have+=a-p.ff;
		a=p.ff;
	//	trace1(a);
		while(s.size()>0)
		{
			ll req2=*(s.begin());
		//	trace3(a,req2,have);
			if(req2>have)
			{
				break;
			}
			have-=req2;
			s.erase(s.begin());
		}
	//	trace1(a);
		ll sz=s.size();
		rank=min(rank,sz+1);
	}
	if(pq.size()==0)
	{
		have=a;
		while(s.size()>0)
		{		
			ll req2=*(s.begin());
		//	trace3(a,req2,have);
			if(req2>have)	
			{				
				break;
			}
			have-=req2;
			s.erase(s.begin());
		}
		ll sz=s.size();
		rank=min(rank,sz+1);
	}
	trace1(a);
	//	trace1(a);
	
	cout<<rank;
	return 0;
}