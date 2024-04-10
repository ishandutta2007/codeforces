#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
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
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const ll N=255;

vector<char> ans;
ll n,k;

bool check(ll m)
{
	ll cur=(m*(m+1))/2;
	if(cur<=k)
		return true;
	else
		return false;
}

ll binsearch(ll lo, ll hi)
{
	while(lo<hi)
	{
		ll mid=(lo+hi+1)/2;
		if(check(mid))
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	return lo;
}
int main()
{ 
	cin>>n>>k;
	if(k>=1e11)
	{
		cout<<"Impossible";
		return 0;
	}
	ll a=binsearch(0, 3e5 + 5);
	ll ct=0;
	ll stk=k;
	for(int i=0;i<=a;i++)
	{
		ans.pb('(');
		ct++;
		k-=i;
		if(ct>n)
		{
			cout<<"Impossible";
			return 0;
		}
	}
	if(ct>n)
	{
		cout<<"Impossible";
		return 0;
	}
	for(int i=a;i>=1;i--)
	{
		ans.pb(')');
		while(k>=i)
		{
			ans.pb('(');
			ans.pb(')');
			ct++;
			k-=i;
		}
		if(ct>n)
		{
			cout<<"Impossible";
			return 0;
		}
	}
	ans.pb(')');
	if(ct>n)
	{
		cout<<"Impossible";
		return 0;
	}
	while(ct<n)
	{
		ans.pb('(');
		ans.pb(')');
		ct++;
	}
	for(auto it:ans)
	{
		cout<<it;
	}
	return 0;
}