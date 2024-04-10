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

ll n,x;
typedef struct node
{
	ll l,r,c;
}nd;

vector<nd> v;

bool comp(nd n1, nd n2)
{
	if(n1.r<n2.r)
		return true;
	if(n1.r==n2.r)
		return n1.l<n2.l;
	else
		return false;
}

bool comp2(nd n1, nd n2)
{
	if(n1.l<n2.l)
		return true;
	if(n1.l==n2.l)
		return n1.r<n2.r;
	else
		return false;
}
int main()
{
	IOS;
	cin>>n>>x;
	v=vector<nd> (n+1);
	vector<nd> v2(n+1);
	ll ans=INT_MAX;
	map<ll,multiset<ll> > m;
	for(ll i=1;i<=n;i++)
	{
		cin>>v[i].l>>v[i].r>>v[i].c;
		m[v[i].r-v[i].l+1].insert(v[i].c);
		v2[i].l=v[i].l;
		v2[i].r=v[i].r;
		v2[i].c=v[i].c;
	}
	//trace1("Hi");
	sort(v.begin()+1,v.end(),comp);
	sort(v2.begin()+1,v2.end(),comp2);
	ll ind=1;
	for(ll i=1;i<=n;i++)
	{
		ll curr=v[i].r;
		while(ind<=n&&v2[ind].l<=curr)
		{
			m[v2[ind].r-v2[ind].l+1].erase(m[v2[ind].r-v2[ind].l+1].find(v2[ind].c));
			ind++;
		}
		ll reqd=x-(v[i].r-v[i].l+1);
		if(m.find(reqd)==m.end())
		{
			continue;
		}
		else if(m[reqd].size()==0)
		{
			continue;
		}
		else
		{
			auto it=m[reqd].begin();
			ans=min(ans,v[i].c+*it);
		}
	}
	if(ans!=INT_MAX)
	{
		cout<<ans;
	}
	else
	{
		cout<<"-1";
	}
	return 0;
}