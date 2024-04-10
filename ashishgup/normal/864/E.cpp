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
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e2+5;

int n;
int cache[N][5000];
int vis[N][5000];
pair<int,int> path[N][5000];

struct data
{
	int t,d,p,ind;
};

data a[N];

bool comp(data &d1, data &d2)
{
	if(d1.d<d2.d)
		return true;
	else if(d1.d==d2.d)
		return d1.t<d2.t;
	else
		return false;
}

int dp(int i, int tim)
{
	if(i>n)
	{
		return 0;
	}
	if(vis[i][tim])
	{
		return cache[i][tim];
	}
	vis[i][tim]=1;
	if(tim+a[i].t<a[i].d)
	{
		cache[i][tim]=dp(i+1, tim);
		path[i][tim]=mp(i+1, tim);
		int pos2=a[i].p + dp(i+1, tim+a[i].t);
		if(pos2>cache[i][tim])
		{
			cache[i][tim]=pos2;
			path[i][tim]=mp(i+1, tim+a[i].t);
		}
	}
	else
	{
		cache[i][tim]=dp(i+1, tim);
		path[i][tim]=mp(i+1, tim);
	}
	return cache[i][tim];
}

int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t>>a[i].d>>a[i].p;
		a[i].ind=i;
	}
	sort(a+1, a+n+1, comp);
	cout<<dp(1,0)<<endl;
	int ind=1;
	int tim=0;
	vector<int> ans2;
	while(ind!=n+1)
	{
		pair<int, int> curpair=path[ind][tim];
		int nexttime=curpair.ss;
		if(nexttime!=tim)
		{
			ans2.pb(a[ind].ind);
		}
		tim=nexttime;
		ind=ind+1;
	}
	cout<<ans2.size()<<endl;
	for(auto it:ans2)
	{
		cout<<it<<" ";
	}
	return 0;
}