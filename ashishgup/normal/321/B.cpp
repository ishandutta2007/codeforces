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

typedef struct node
{
	string s;
	ll val;
}nd;

vector<nd> v;
vector<ll> a,b,c;
ll n,m;

int main()
{
	IOS;
	cin>>n>>m;
	v=vector<nd> (n);
	a=vector<ll> (m);
	multiset<ll> st;
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].s>>v[i].val;
		if(v[i].s=="ATK")
		{
			b.pb(v[i].val);
		}
		else
		{
			c.pb(v[i].val);
		}
	}
	for(ll i=0;i<m;i++)
	{
		cin>>a[i];
		st.insert(a[i]);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	ll sz1=b.size();
	ll sz2=n-sz1;
	ll ans=0;
	for(ll count=sz1-1;count>=0;count--)
	{	
		ll tempans=0;
		bool chck=true;
		for(ll i=m-1,j=count;i>=0&&j>=0;i--,j--)
		{
			if(a[i]>=b[j])
			{
				tempans+=a[i]-b[j];
			}
			else
			{
				chck=false;
				break;
			}
		}
		if(!chck)
			continue;
		ans=max(ans,tempans);
	}
	ll ans2=0;
	bool check=true;
	for(ll i=0;i<sz2;i++)
	{
		auto it=st.upper_bound(c[i]);
		if(it==st.end())
		{
			check=false;
			break;
		}
		st.erase(st.find(*it));
	}
	if(!check)
	{
		cout<<ans;
		return 0;
	}
	vll rem;
	for(auto it:st)
	{
		rem.pb(it);
	}
	ll siz=rem.size();
	ll i,j;
	for(i=siz-1,j=sz1-1;i>=0&&j>=0;i--,j--)
	{
		if(rem[i]>=b[j])
		{
			ans2+=rem[i]-b[j];
		}
		else
		{
			ans2=INT_MIN;
			break;
		}
	}
	while(i!=-1)
	{
		ans2+=rem[i];
		i--;
	}
	cout<<max(ans,ans2);
    return 0;
}