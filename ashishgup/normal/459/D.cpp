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

const int N = 1e6 + 5;

int bit1[N][2];
int n, a[N];
map<int,int> m;
int cnt=1;
int freq[N];
int right1[N];

void update(int id, int i, int val)
{
	while(i<=n)
	{
		bit1[i][id]+=val;
		i+=(i&(-i));
	}
}

int prefsum(int id, int i)
{
	int store=0;
	while(i>0)
	{
		store+=bit1[i][id];
		i-=(i&(-i));
	}
	return store;
}
int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]];
	}
	for(auto &it:m)
	{
		it.ss=cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=m[a[i]];
	}
	for(int i=n;i>=1;i--)
	{
		freq[a[i]]++;
		right1[i]=freq[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		update(1, right1[i], 1);
	}
	ll answer=0;
	for(int i=1;i<=n;i++)
	{
		update(1, right1[i], -1);
		update(0, a[i],1);
		int left=prefsum(0,a[i]) - prefsum(0,a[i]-1);
		int right2=prefsum(1, left-1);
		answer+=right2;
	}
	cout<<answer;
	return 0;
}