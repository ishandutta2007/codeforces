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

ll n,k;
ll a[N];
ll st[4*N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=gcd(a[L],k);
		return;
	}
	int M=(L+R)>>1;
	build(node<<1, L, M);
	build((node<<1) + 1, M+1, R);
	st[node]=gcd(k, st[node<<1] * st[(node<<1) + 1]);
}

int query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return 1;
	if(i<=L && R<=j)
	{
		return st[node];
	}
	int M=(L+R)>>1;
	ll left=query(node<<1, L, M, i, j);
	ll right=query((node<<1) +1, M+1, R, i, j);
	return gcd(left*right, k);
}
int main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	build(1, 1, n);
	int r=1;
	ll ans=0;
	for(int l=1;l<=n;l++)
	{
		while(r<l)
			r++;
		while(r<=n&&query(1, 1, n, l, r)!=k)
		{
			r++;
		}
		ans+=(n-r+1);
	}
	cout<<ans;
	return 0;
}