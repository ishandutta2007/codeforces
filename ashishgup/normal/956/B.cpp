#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;

int n, u;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>u;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int check=0;
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-2]<=u)
		{
			check=1;
		}
	}
	if(!check)
	{
		cout<<"-1";
		return 0;
	}
	double ans=-1;
	for(int i=1;i<=n-2;i++)
	{
		double Ei=a[i];
		double Ej=a[i+1];
		auto index=upper_bound(a+i+2, a+n+1, Ei + u);
		index--;
		if(*index - a[i]<=u)
		{
			double Ek=*index;
			double num=Ek - Ej;
			double den=Ek - Ei;
			num/=den;
			ans=max(ans, num);
		}
	}
	if(ans<0)
	{
		cout<<"-1";
	}
	else
	{
		cout<<fixed<<setprecision(15)<<ans;
	}
	return 0;
}