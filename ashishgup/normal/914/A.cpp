#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;

int a[N];
set<int> s;

void precomp()
{
	for(int i=0;i<=1e3;i++)
	{
		s.insert(i*i);
	}	
}

int notsq(int k)
{
	if(k<0)
		return 1;
	if(s.find(k)==s.end())
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	precomp();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	int ans=a[1];
	for(int i=2;i<=n;i++)
	{
		if(notsq(a[i]))
		{
			ans=a[i];
		}
	}
	cout<<ans;
	return 0;
}