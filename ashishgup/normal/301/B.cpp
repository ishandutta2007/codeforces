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

typedef long long ll;
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

vll x;
vll y;
ll distance1(ll i,ll j)
{
	ll ans=abs(x[i]-x[j])+abs(y[i]-y[j]);
	return ans;
}
int main()
{
	IOS;
	ll n,d;
	cin>>n>>d;
	vvll g(n);
	vll time(n,0);
	x=vll (n);
	y=vll (n);
	for(ll i=1;i<n-1;i++)
	{
		cin>>time[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>x[i];
		cin>>y[i];
	}
	vvll dist(n,vll(n,LLONG_MAX));
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i!=j)
				dist[i][j]=d*distance1(i,j)-time[j];
			else
				dist[i][j]=0;
		}
	}
	/*for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(ll k=0;k<n;k++)
	{
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	/*for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dist[0][n-1];
	return 0;
}