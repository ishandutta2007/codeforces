#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;

int n;
int a[N];

int not_sorted()
{
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
			return 1;
	}
	return 0;
}

void checkno()
{
	for(int i=2;i<=n;i++)
	{
		if(abs(a[i]-a[i-1])>=2)
		{
			cout<<"NO";
			exit(0);
		}
	}
}

void work()
{
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	vector<int> cur;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==v.back())
		{
			if(flag)
				cur.push_back(a[i]);
			flag=1;
		}
		else
		{
			cur.push_back(a[i]);
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		a[i]=cur[i-1];
	}
}

int32_t main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(not_sorted())
	{
		checkno();
		work();
		n--;
	}
	cout<<"YES";
	return 0;
}