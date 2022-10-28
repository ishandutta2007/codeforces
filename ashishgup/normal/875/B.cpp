#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e6+5;

int n;
int a[N], bit[N];

void update(int i, int k)
{
	while(i<=n)
	{
		bit[i]+=k;
		i+=(i&(-i));
	}
}

int prefsum(int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=bit[i];
		i-=(i&(-i));
	}
	return sum;
}

int rangesum(int l, int r)
{
	return prefsum(r)-prefsum(l-1);
}

int32_t main()
{
    IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=(n-a[i]+1);
	}
	stack<int> s;
	for(int i=n;i>=1;i--)
	{
		s.push(i);
	}
	int ans=1;
	cout<<ans<<" ";
	int right=0;
	for(int i=1;i<=n;i++)
	{
		int cur=a[i];
		right=max(cur, right);
		update(cur, 1);
		while(!s.empty()&&rangesum(s.top(),s.top())==1)
		{
			update(s.top(), -1);
			s.pop();
		}
		cout<<prefsum(right)+1<<" ";
	}
    return 0;
}