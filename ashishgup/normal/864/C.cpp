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

const int N=1e5+5;

long long a,b,f,k;
int main()
{
	IOS;
	cin>>a>>b>>f>>k;
	if(f>b)
	{
		cout<<"-1";
		return 0;
	}
	if(k==1)
	{
	    if((a-f)>b)
	    {
	        cout<<"-1";
	        return 0;
	    }
	}
	if(k==2)
	{
		long long dist2=(a-f)*2;
		if(dist2>b)
		{
			cout<<"-1";
			return 0;
		}
	}
	if(k>=3)
	{
		long long dist2=(a-f)*2;
		if(dist2>b)
		{
			cout<<"-1";
			return 0;
		}
		long long dist3=(f*2);
		if(dist3>b)
		{
			cout<<"-1";
			return 0;
		}
	}
	long long fuel=b-f;
	long long ans=0;
	long long dist2=(a-f)*2;
	long long dist3=(f*2);
	for(int i=1;i<k;i++)
	{
		if(i%2==1)
		{
			if(fuel>=dist2)
			{
				fuel-=dist2;
			}
			else
			{
				ans++;
				fuel=b;
				fuel-=dist2;
			}
		}
		else
		{
			if(fuel>=dist3)
			{
				fuel-=dist3;
			}
			else
			{
				ans++;
				fuel=b;
				fuel-=dist3;
			}
		}
	}
	if(k%2 == 1)
	{
		long long leftover=dist2/2;
		if(fuel<leftover)
		{
			ans++;
		}
	}
	else
	{
		long long leftover=dist3/2;
		if(fuel<leftover)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}