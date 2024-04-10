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

struct node
{
	ll a;
	ll b;
	ll c;
};

bool operator<(const node& node1, const node& node2) 
{
  return node1.a > node2.a;
}
int main()
{
	IOS;
	ll n,k,x;
	cin>>n>>k>>x;
	vpll v(n);
	priority_queue <node,vector<node> > p;
	ll countpos=0;
	ll countneg=0;
	ll countzero=0;
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].ff;
		v[i].ss=i;
		if(v[i].ff>=1)
		{
			countpos++;
		}
		else if(v[i].ff<=-1)
		{
			countneg++;
		}
	}
	sort(v.begin(),v.end());
	for(ll i=0;i<n;i++)
	{
		if(k==0)
		{
			break;
		}
		if(v[i].ff==0)
		{
			if(countneg%2)
			{
				v[i].ff+=x;
				k--;
			}
			else
			{
				v[i].ff-=x;
				k--;
				countneg++;
			}
		}
	}
	for(ll i=0;i<n;i++)
	{
		node t;
		t.a=abs(v[i].ff);
		t.b=v[i].ss;
		t.c=v[i].ff>0?1:-1;
		p.push(t);
	}
	while(k>0)
	{
		if(countneg%2)
		{
			node t=p.top();
			p.pop();
			t.a+=x;
			p.push(t);
		}
		else
		{
			node t=p.top();
			p.pop();
			t.a-=x;
			if(t.a<0)
			{
				t.c*=-1;
				t.a=abs(t.a);
				countneg++;
			}
			p.push(t);
		}
		k--;
	}
	vll ans(n);
	while(!p.empty())
	{
		node t=p.top();
		p.pop();
		ans[t.b]=t.a*t.c;
	}
	for(auto it:ans)
	{
		cout<<it<<" ";
	}
	
	return 0;
}