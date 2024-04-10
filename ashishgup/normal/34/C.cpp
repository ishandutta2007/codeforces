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
typedef pair<long long, long long> pll;
typedef vector<long long> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 2000000011
#define MOD2 2000000033

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const long long N=2e5+5;

int main()
{
	IOS;
	string s;
	cin>>s;
	stringstream ss(s);
	ll num;
	ss>>num;
	set<ll> store;
	store.insert(num);
	char ch;
	while(ss>>ch)
	{
		ss>>num;
		store.insert(num);
	}
	vector<int> v;
	for(auto it:store)
	{
		v.pb(it);
	}
	ll sz=v.size();
	int start=-1;
	int end=-1;
	vpll ans;
	for(int i=0;i<sz;i++)
	{
		start=v[i];
		end=v[i];
		bool check=false;
		while(i<sz-1&&v[i+1]-v[i]==1)
		{
			i++;
			check=true;
			end=v[i];
		}
		ans.pb(mp(start,end));
	}
	ll sz2=ans.size();
	for(int i=0;i<sz2;i++)
	{
		ll a=ans[i].ff;
		ll b=ans[i].ss;
		if(a!=b)
		{
			cout<<a<<"-"<<b;
		}
		else
		{
			cout<<a;
		}
		if(i<sz2-1)
		{
			cout<<",";
		}
	}
	return 0;
}