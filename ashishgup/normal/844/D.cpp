#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
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

ll n;
typedef struct node
{
	ll ind,x,next;
}nd;

bool comp(nd n1,nd n2)
{
	return n1.x<n2.x;
}

ll RAND()
{
	ll store=(rand() << 15 + rand())%n;
	return store;
}
int main()
{
	ll start,x;
	cin>>n>>start>>x;
	vector<nd> v;
	set<ll> s;
	s.insert(x);
	ll cur=0;
	nd n1;
	n1.ind=start;
	cout<<"? "<<start<<endl;
	cin>>n1.x>>n1.next;
	s.insert(start);
	s.insert(n1.next);
	v.pb(n1);
	ll ct=0;
	vpll ind;
	for(ll i=1;i<=n;i++)
	{
		pll p;
		p.ff=RAND();
		p.ss=i;
		ind.pb(p);
	}
	sort(ind.begin(),ind.end());
	for(ll i=0;i<1000;i++)
	{
		while(cur<n&&s.find(ind[cur].ss)!=s.end())
		{
			cur++;
		}
		ct++;
		if(cur>=n)
			break;
		s.insert(ind[cur].ss);
		n1.ind=ind[cur].ss;
		cout<<"? "<<ind[cur].ss<<endl;
		cin>>n1.x;
		cin>>n1.next;
		v.pb(n1);
		s.insert(n1.next);
	}
	sort(v.begin(),v.end(),comp);
	ll stind=-1;
	for(auto it:v)
	{
		if(it.x<x)
		{
			stind=it.ind;
		}
	}
	if(stind==-1)
	{
		cout<<"! "<<v[0].x<<endl;
		return 0;
	}
	while(ct<1998&&stind!=-1)
	{
		ct++;
		cout<<"? "<<stind<<endl;
		ll nextind,val;
		cin>>val>>nextind;
		if(val>=x)
		{
			cout<<"! "<<val<<endl;
			return 0;
		}
		stind=nextind;
	}
	cout<<"! -1";
	return 0;
}