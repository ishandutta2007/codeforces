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
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=5e3+5;

ll n;
int a[N];
ll cache[N][5];
bool vis[N][5];
pair<ll,ll> parent[N][5];

ll dp(ll i,ll cur)
{
	if(i>=n)
	{
		return 0;
	}
	if(vis[i][cur])
	{
		return cache[i][cur];
	}
	vis[i][cur]=1;
	ll ans=0;
	if(cur==0||cur==2)
	{
		ll pos1=a[i]+dp(i+1,cur);
		ll pos2=-1*a[i]+dp(i+1,cur+1);
		if(pos1>=pos2)
		{
			parent[i][cur]=mp(i+1,cur);
		}
		else
		{
			parent[i][cur]=mp(i+1,cur+1);
		}
		ans=max(pos1,pos2);
	}
	else if(cur==1)
	{
		ll pos1=-1*a[i] + dp(i+1,cur);
		ll pos2=a[i]+dp(i+1,cur+1);
		if(pos1>=pos2)
		{
			parent[i][cur]=mp(i+1,cur);
		}
		else
		{
			parent[i][cur]=mp(i+1,cur+1);
		}
		ans=max(pos1,pos2);
	}
	else
	{
		ans=-1*a[i]+dp(i+1,cur);
		parent[i][cur]=mp(i+1,cur);
	}
	cache[i][cur]=ans;
	return ans;
}
int main()
{
	IOS;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//ll ans=dp(0,0);
	//cout<<ans;
	ll max1=LLONG_MIN;
	ll j;
	for(ll i=0;i<4;i++)
	{
		if(dp(0,i)>max1)
		{
			max1=dp(0,i);
			j=i;
		}
	}
	ll printed=0;
	for(ll k=0;k<j;k++)
	{
		printed++;
		cout<<"0 ";
	}
	ll i=0;
	vll ans;
	while(i<n&&j<3)
	{
		pll par=parent[i][j];
		if(j!=par.ss)
		{
			printed++;
			cout<<i<<" ";
		}
		i=i+1;
		j=par.ss;
	}
	while(printed<3)
	{
		cout<<n<<" ";
		printed++;
	}
	return 0;
}