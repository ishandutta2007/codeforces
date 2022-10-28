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

const int N=1e6+5;

int a[200];
int b[200];

int main()
{ 
	IOS;
	ll n,m;
	cin>>n>>m;
	if(m==0)
	{
		if(n==1)
		{
			cout<<"1";
		}
		else
		{
			cout<<"-1";
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	set<int> ans;
	for(int i=1;i<=100;i++)
	{
		bool check=true;
		for(int j=1;j<=m;j++)
		{
			int flat=a[j];
			int floor=a[j]/i;
			if(a[j]%i != 0)
			{
				floor++;
			}
			if(floor!=b[j])
			{
				check=false;
				break;
			}
		}
		if(check)
		{
			int store=n/i;
			if(n%i != 0)
			{
				store++;
			}
			ans.insert(store);
		}
	}
	if(ans.size()!=1)
	{
		cout<<"-1";
		return 0;
	}
	else
	{
		cout<<*(ans.begin());
	}
	return 0;
}