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

ll n;
vvc v;
vvll vis;
void rec(ll i,ll j,char ch)
{
	if(i<0||i>=n||j<0||j>=n)
		return;
	if(vis[i][j])
		return;
	vis[i][j]=1;
	v[i][j]=ch;
	if(ch=='C')
	{
		rec(i+1,j,'.');
		rec(i,j+1,'.');
		rec(i-1,j,'.');
		rec(i,j-1,'.');
	}
	else
	{
		rec(i+1,j,'C');
		rec(i,j+1,'C');
		rec(i-1,j,'C');
		rec(i,j-1,'C');
	}
	
}
int main()
{
	IOS;
	cin>>n;
	v=vvc(n,vc(n));
	vis=vvll(n,vll(n,0));
	rec(0,0,'C');
	ll ct=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(v[i][j]=='C')
				ct++;
		}
	}
	cout<<ct<<endl;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cout<<v[i][j];
		}
		cout<<endl;
	}
	return 0;
}