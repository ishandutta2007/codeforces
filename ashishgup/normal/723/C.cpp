#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second;
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

const int N=1e5;
const int M=1e9;

int n,m;
int a[N], f[N], f2[N];

bool check(int k)
{
	int reqd=0, extra=0;
	int ct=0;
	for(int i=1;i<=m;i++)
	{
		reqd+=max(0, k-f[i]);
		extra+=max(0, f[i]-k);
		ct+=f[i];
	}
	extra+=(n-ct);
	if(extra>=reqd)
		return true;
	else
		return false;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check(mid))
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

int main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=m)
		{
			f[a[i]]++;
		}
	}
	int freq=binsearch(0, n);
	int ct=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>m)
		{
			for(int j=1;j<=m;j++)
			{
				if(f[j]<freq)
				{
					a[i]=j;
					f[j]++;
					ct++;
					break;
				}
			}
		}
		else if(a[i]<=m && f[a[i]]>freq)
		{
			for(int j=1;j<=m;j++)
			{
				if(f[j]<freq)
				{
					f[j]++;
					f[a[i]]--;
					a[i]=j;
					ct++;
					break;
				}
			}
		}
	}
	cout<<freq<<" "<<ct<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}