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

int n;
int a[N];

typedef struct node
{
	ll val[20];
	ll lazy[20];

	merge(node &a, node &b)
	{
		for(ll i=0;i<20;i++)
		{
			val[i]=a.val[i] + b.val[i];
		}
	}

	propagate(node &a, node&b, int L, int R)
	{
		for(ll i=0;i<20;i++)
		{
			if(lazy[i])
			{
				val[i]=(R-L+1) - val[i];
			}
		}
		if(L!=R)
		{
			for(ll i=0;i<20;i++)
			{
				a.lazy[i]^=lazy[i];
				b.lazy[i]^=lazy[i];
			}
		}
		for(ll i=0;i<20;i++)
		{
			lazy[i]=0;
		}

	}
}nd;

nd nullnode; 

nd st[4*N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		for(ll i=0;i<20;i++)
		{
			if(a[L] & (1LL<<i))
			{
				st[node].val[i]=1;
			}
		}
		return;
	}
	int M=(L+R) >> 1;
	build(node+node,L,M);
	build(node+node+1,M+1,R);
	st[node].merge(st[node+node],st[node+node+1]);
}

void update(int node, int L, int R, int i, int j, int val[])
{
	st[node].propagate(st[node+node],st[node+node+1],L,R);
	if(j<L || i>R)
	{
		return;
	}
	if(i<=L && R<=j)
	{
		for(ll i=0;i<20;i++)
		{
			if(val[i])
			{
				st[node].val[i]=(R-L+1) - st[node].val[i];
			}
		}
		if(L!=R)
		{
			for(ll i=0;i<20;i++)
			{
				st[node+node].lazy[i]^=val[i];
				st[node+node+1].lazy[i]^=val[i];
			}
		}
		return;
	}
	int M=(L+R) >> 1;
	update(node+node, L, M, i, j, val);
	update(node+node+1, M+1, R, i, j, val);
	st[node].merge(st[node+node],st[node+node+1]);
}

nd query(int node, int L, int R, int i, int j)
{
	st[node].propagate(st[node+node],st[node+node+1],L,R);
	if(j<L || i>R)
	{
		return nullnode;
	}
	if(i<=L && R<=j)
	{
		return st[node];
	}
	int M=(L+R) >> 1;
	nd n1=query(node+node, L, M, i, j);
	nd n2=query(node+node+1, M+1, R, i, j);
	nd reqd;
	reqd.merge(n1,n2);
	return reqd;
}
int main()
{
	IOS;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	build(1,1,n);	
	int m;
	cin>>m;
	while(m--)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			ll l,r;
			cin>>l>>r;
			node store=query(1,1,n,l,r);
			ll ans=0;
			for(ll i=0;i<20;i++)
			{
				ans+= store.val[i] * (1LL<<i);
			}
			cout<<ans<<endl;
		}
		else
		{
			ll l,r,x;
			cin>>l>>r>>x;
			int val[20];
			for(ll i=0;i<20;i++)
			{
				if((1LL<<i)&x)
				{
					val[i]=1;
				}
				else
				{
					val[i]=0;
				}
			}
			update(1,1,n,l,r,val);
		}
	}
	return 0;
}