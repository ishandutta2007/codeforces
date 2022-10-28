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

const long long N=1e5+5;

ll n,d;
ll h[N], dp[N], path[N], rm[N];
pair<ll,ll> a[N];

struct data
{
	ll maxval, ind;

	void merge(data &a, data &b)
	{
		if(a.maxval>=b.maxval)
		{
			maxval=a.maxval;
			ind=a.ind;
		}
		else
		{
			maxval=b.maxval;
			ind=b.ind;
		}
	}
};

data nullnode;
data st[4*N];

void update(int node, int L, int R, int pos, int val)
{
	if(L==R)
	{
		st[node].maxval=val;
		st[node].ind=L;
		return;
	}
	int M=(L+R) >> 1;
	if(pos<=M)
		update(node<<1, L, M, pos, val);
	else
		update((node<<1) + 1, M+1, R, pos, val);
	st[node].merge(st[node<<1],st[(node<<1)+1]);
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
	int M=(L+R) >> 1;
	data d1=query(node<<1, L, M, i, j);
	data d2=query((node<<1)+1, M+1, R, i, j);
	data d3;
	d3.merge(d1,d2);
	return d3;
}

int lowerbound(int lo, int hi, ll height)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1) >> 1;
		if(height-a[mid].ff>=d)
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

int upperbound(int lo, int hi, ll height)
{
	while(lo<hi)
	{
		int mid=(lo+hi) >> 1;
		if(a[mid].ff-height>=d)
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	return lo;
}

int main()
{
	IOS;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		a[i].ff=h[i];
		a[i].ss=i;
	}	
	sort(a+1,a+n+1);
	nullnode.maxval=-1;
	nullnode.ind=-1;
	int ind=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].ff==h[1])
		{
			ind=i;
			break;
		}
	}
	dp[1]=1;
	path[1]=0;
	update(1, 1, n, ind, 1);
	for(ll i=1;i<=n;i++)
	{
		ll curh=h[i];
		int index=lower_bound(a+1, a+n+1, make_pair(h[i], i)) - a;
		rm[index]=i;
	}
	for(ll i=2;i<=n;i++)
	{	
		ll curh=h[i];
		int idx1=lowerbound(1, n, curh);
		int idx2=upperbound(1, n, curh);
		dp[i]=1;
		path[i]=0;
		if(curh-a[1].ff >= d)
		{
			data cur=query(1, 1, n, 1, idx1);
			if(cur.maxval>=dp[i])
			{
				dp[i]=cur.maxval+1;
				path[i]=rm[cur.ind];
			}
		}
		if(a[n].ff - curh >= d)
		{
			data cur=query(1, 1, n, idx2, n);
			if(cur.maxval>=dp[i])
			{
				dp[i]=cur.maxval+1;
				path[i]=rm[cur.ind];
			}
		}
		int index=lower_bound(a+1, a+n+1, make_pair(curh, i)) - a;
		update(1, 1, n, index, dp[i]);
	}
	int ans1=0;
	ind=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]>ans1)
		{
			ans1=dp[i];
			ind=i;
		}
	}
	cout<<ans1<<endl;
	vector<int> ans2;
	while(ind!=0)
	{
		ans2.pb(ind);
		ind=path[ind];
	}
	sort(ans2.begin(),ans2.end());
	for(auto it:ans2)
	{
		cout<<it<<" ";
	}
	return 0;
}