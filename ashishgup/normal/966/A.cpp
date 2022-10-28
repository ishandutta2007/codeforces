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
 
const int N=1e6+5;

int n, m, stairs, elev, vel;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>stairs>>elev>>vel;
	for(int i=1;i<=stairs;i++)
		cin>>a[i];
	for(int i=1;i<=elev;i++)
		cin>>b[i];
	int q;
	cin>>q;
	while(q--)
	{
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		if(y1>y2)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		int diff=abs(x2-x1);
		auto it=lower_bound(a+1, a+stairs+1, y1);
		int index=it-a;
		int ans=1e18;
		for(int j=max(1LL,index-1);j<=min(stairs,index+1);j++)
		{
			ans=min(ans, abs(y1-a[j]) + diff + abs(y2-a[j]));
		}
		auto it2=lower_bound(b+1, b+elev+1, y1);
		index=it2-b;
		int difftime=(diff+vel-1)/vel;
		for(int j=max(1LL,index-1);j<=min(elev,index+1);j++)
		{
			ans=min(ans, abs(y1-b[j]) + difftime + abs(y2-b[j]));
		}
		if(diff==0)
		{
			ans=abs(y2-y1);
		}
		cout<<ans<<endl;
	}
	return 0;
}