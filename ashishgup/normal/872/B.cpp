#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e6+5;
const int MOD=1e9+7;

int n,k;
int a[N], pref[N], suf[N];
set<int> s;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	if(k==1)
	{
		cout<<*(s.begin());
		return 0;
	}
	if(k>=3)
	{
		cout<<*(--s.end());
		return 0;
	}
	pref[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		pref[i]=min(a[i], pref[i-1]);
	}
	suf[n]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		suf[i]=min(suf[i+1], a[i]);
	}
	int ans=-2e9;
	for(int i=1;i<=n-1;i++)
	{
		ans=max(ans, max(pref[i], suf[i+1]));
	}
	cout<<ans;
	return 0;
}