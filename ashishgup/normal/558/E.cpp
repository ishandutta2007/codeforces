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

const int N=1e5+5;

int st[26][4*N];
int lazy[26][4*N];
ll n,q;
string s;

void propagate(ll id, ll node, ll L,ll R)
{
	if(L!=R)
	{
		lazy[id][node + node]=lazy[id][node];
		lazy[id][node + node + 1]=lazy[id][node];
	}
	st[id][node]=(R-L+1)*lazy[id][node];
	lazy[id][node]=-1;
}

ll query(ll id, ll node, ll L, ll R, ll i, ll j)
{
	if(lazy[id][node]!=-1)
	{
		propagate(id,node,L,R);
	}
	if(j<L || i>R)
		return 0;
	if(i<=L && R<=j)
	{
		return st[id][node];
	}
	ll M=(L+R) >> 1;
	return query(id,node+node,L,M,i,j) + query(id,node+node+1,M+1,R,i,j);
}

void update(ll id, ll node, ll L, ll R, ll i, ll j, ll newval)
{
	if(lazy[id][node]!=-1)
	{
		propagate(id,node,L,R);
	}
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		st[id][node]=(R-L+1)*newval;
		if(L!=R)
		{
			lazy[id][node+node]=newval;
			lazy[id][node+node+1]=newval;
		}
		return;
	}
	ll M=(L+R) >> 1;
	update(id,node+node,L,M,i,j,newval);
	update(id,node+node+1,M+1,R,i,j,newval);
	st[id][node]=st[id][node+node] + st[id][node+node+1];
}
int main()
{
	IOS;
	cin>>n>>q;
	cin>>s;
	memset(st,0,sizeof(st));
	memset(lazy,-1,sizeof(lazy));
	for(ll i=0;i<n;i++)
	{
		ll cur=s[i]-'a';
		update(cur,1,0,n-1,i,i,1);
	}
	while(q--)
	{
		ll u,v,k;
		cin>>u>>v>>k;
		u--;
		v--;
		if(k)
		{
			ll ct=0;
			for(ll i=0;i<=25;i++)
			{
				ll store=query(i,1,0,n-1,u,v);
				update(i,1,0,n-1,u,v,0);
				update(i,1,0,n-1,u+ct,u+ct+store-1,1);
				ct+=store;
			}
		}
		else
		{
			ll ct=0;
			for(ll i=25;i>=0;i--)
			{
				ll store=query(i,1,0,n-1,u,v);
				update(i,1,0,n-1,u,v,0);
				update(i,1,0,n-1,u+ct,u+ct+store-1,1);
				ct+=store;
			}
		}
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<26;j++)
		{
			if(query(j,1,0,n-1,i,i))
			{
				cout<<(char)(j+'a');
				break;
			}
		}
	}
	return 0;
}