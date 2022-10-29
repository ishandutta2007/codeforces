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
#define MOD 100000000

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

ll n,k;
string s;
vll v;
typedef struct node
{
	ll ind;
	ll val;
	ll absdiff;
	ll sign;
}nd;

bool comp(nd n1,nd n2)
{
	if(n1.absdiff<n2.absdiff)
	{
		return true;
	}
	else if(n1.absdiff==n2.absdiff)
	{
		if(n1.sign>n2.sign)
		{
			return true;
		}
		else if(n1.sign==n2.sign)
		{
			if(n1.sign>0)
				return n1.ind<n2.ind;
			else
				return n1.ind>n2.ind;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool comp2(nd n1,nd n2)
{
	return n1.ind<n2.ind;
}
pair<ll,string> func(ll a)
{
	vector<nd> v2(n);
	for(ll i=0;i<n;i++)
	{
		v2[i].ind=i;
		v2[i].val=v[i];
		v2[i].absdiff=abs(v[i]-a);
		v2[i].sign=v[i]-a;
	}
	sort(v2.begin(),v2.end(),comp);
	ll reqd=0;
	for(ll i=0;i<k;i++)
	{
		v2[i].val=a;
		reqd+=v2[i].absdiff;
	}
	sort(v2.begin(),v2.end(),comp2);
	string ans="";
	for(ll i=0;i<n;i++)
	{
		ans+=(char)(v2[i].val+'0');
	}
	return mp(reqd,ans);
}
int main()
{
	IOS;
	cin>>n>>k;
	cin>>s;
	for(ll i=0;i<n;i++)
	{
		v.pb(s[i]-'0');
	}
	vector<pair<ll,string> > ans(10);
	for(ll i=0;i<=9;i++)
	{
		ans[i]=func(i);
	}
	sort(ans.begin(),ans.end());
	cout<<ans[0].ff<<endl<<ans[0].ss;
	return 0;
}