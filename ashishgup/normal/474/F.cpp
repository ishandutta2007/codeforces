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


struct data
{
	int count;
	int gcd1;
	int min1;
	int ans;

	merge(data &a, data &b)
	{
		if(a.min1==b.min1)
		{
			count=a.count+b.count;
		}
		else
		{
			count=(a.min1<b.min1)?(a.count):(b.count);
		}
		min1=min(a.min1,b.min1);
		gcd1=gcd(a.gcd1,b.gcd1);
		if(gcd1==min1)
		{
			ans=count;
		}
		else
		{
			ans=0;
		}
	}
};

data nullnode;

int n;
data st[4*N];
int a[N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node].gcd1=a[L];
		st[node].count=1;
		st[node].min1=a[L];
		st[node].ans=1;
		return;
	}
	int M=(L+R)>>1;
	build(node+node,L,M);
	build(node+node+1,M+1,R);
	st[node].merge(st[node+node],st[node+node+1]);
}

data query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
	{
		return nullnode;
	}
	if(i<=L && R<=j)
	{
		return st[node];
	}
	int M=(L+R)>>1;
	data n1=query(node+node, L, M, i ,j);
	data n2=query(node+node+1, M+1, R, i ,j);
	data res;
	res.merge(n1,n2);
	return res;
}
int main()
{
	IOS;
	cin>>n;
	nullnode.min1=INT_MAX;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	build(1,0,n-1);
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		data st=query(1,0,n-1,l,r);
		//trace4(st.gcd1,st.min1,st.count,st.ans)
		int ans=(r-l+1) - (st).ans;
		cout<<ans<<endl;
	}
	return 0;
}