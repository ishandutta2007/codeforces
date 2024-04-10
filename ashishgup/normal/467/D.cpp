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
 
ll m,n;
string a[N];
int equivalent[N];
map<string,ll> m1;
ll k=1;
vector<ll> g [N];
int val[2*N];
string storeval[2*N];
int vis[2*N];

struct node
{
	int count_r=0;
	int len=0;
	int val;
};

node store[2*N];
int tosort[2*N];

void lowercase(string &s)
{
	ll sz=s.size();
	for(ll i=0;i<sz;i++)
	{
		s[i]=tolower(s[i]);
	}
}
int assign(string &s)
{
	if(m1.find(s)==m1.end())
	{
		storeval[k]=s;
		m1[s]=k++;
	}
	return m1[s];
}

node function1(string &s)
{
	node nd;
	int sz=s.size();
	for(int i=0;i<sz;i++)
	{
		if(s[i]=='r')
		{
			nd.count_r++;
		}
	}
	nd.len=sz;
	nd.val=m1[s];
	return nd;
}

bool comp(int &a, int &b)
{
	if(store[a].count_r < store[b].count_r)
	{
		return true;
	}
	else if(store[a].count_r == store[b].count_r)
	{
		return store[a].len<store[b].len;
	}
	else
	{
		return false;
	}
}

void dfs(int i, int parentval)
{
	if(vis[i])
		return;
	vis[i]=1;
	val[i]=val[parentval];
	for(auto it:g[i])
	{
		dfs(it,i);
	}
}
int main()
{
	IOS;
	cin>>m;
	for(ll i=0;i<m;i++)
	{
		cin>>a[i];
		lowercase(a[i]);
		equivalent[i]=assign(a[i]);
	}
	for(ll i=0;i<2*N;i++)
	{
		val[i]=i;
	}
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		string x,y;
		cin>>x>>y;
		lowercase(x);
		lowercase(y);
		int xeq=assign(x);
		int yeq=assign(y);
		g[yeq].pb(xeq);
	}
	int ind=1;
	for(auto it:m1)
	{
		string cur=it.ff;
		node n1=function1(cur);
		store[it.ss]=n1;
		ind++;
	}
	for(ll i=1;i<ind;i++)
	{
		tosort[i]=i;
	}
	sort(tosort,tosort+ind,comp);
	for(ll i=0;i<ind;i++)
	{
		if(!vis[tosort[i]])
		{
			dfs(tosort[i],tosort[i]);
		}
	}
	ll ans1=0;
	ll ans2=0;
	for(ll i=0;i<m;i++)
	{
		int originalvalue=m1[a[i]];
		int newval=val[originalvalue];
		ans1+=store[newval].count_r;
		ans2+=store[newval].len;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}

//stuck