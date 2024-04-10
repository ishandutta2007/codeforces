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
	ll u,r;
}nd;

int main()
{
	IOS;
	ll a,b;
	cin>>a>>b;
	if(a==0 && b==0)
	{
		cout<<"Yes";
		return 0;
	}
	string s;
	cin>>s;
	ll n=s.size();
	vector<nd> v(n);
	ll up=0,right=0;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='U')
		{
			up++;
		}
		else if(s[i]=='R')
		{
			right++;
		}
		else if(s[i]=='D')
		{
			up--;
		}
		else
		{
			right--;
		}
		v[i].u=up;
		v[i].r=right;
		if(up==b && right == a)
		{
			cout<<"Yes";
			return 0;
		}
	}
	if(up==0 && right ==0)
	{
		cout<<"No";
		return 0;
	}
	for(ll i=0;i<n;i++)
	{
		ll kup=b-v[i].u;
		if(up==0)
		{
			if(v[i].u==b)
			{
				if((a-v[i].r)%right == 0 )
				{
					ll st=(a-v[i].r)/right;
					if(st<0)
					{
						continue;
					}
					//trace5(i,v[i].u,v[i].r,up,right);
					cout<<"Yes";
					return 0;
				}
			}
			continue;
		}
		if((b-v[i].u)%up != 0)
		{
			continue;
		}
		ll k=kup/up;
		if(k<0)
		{
			continue;
		}
		ll stb=v[i].r+k*right;
		if(stb==a)
		{
		//	trace3(i,v[i].u,v[i].r);
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
    return 0;
}