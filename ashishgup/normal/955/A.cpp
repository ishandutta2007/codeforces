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

const int N=2e5+5;

int hh, mm;
int h, d, c, n;
double ans=INT_MAX;
string s;

int check()
{
	if(hh>=20)
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	cin>>hh>>mm;	
	cin>>h>>d>>c>>n;
	int reqd;
	if(check())
	{
		int hunger=h;
		reqd=hunger/n;
		if(hunger%n!=0)
			reqd++;
		ans=0.8*c*reqd;
	}
	else
	{
		int hunger=h;
		reqd=hunger/n;
		if(hunger%n!=0)
			reqd++;
		ans=c*reqd;
		int tim=(20-hh)*(60);
		tim-=mm;
		h+=tim*d;
		reqd=h/n;
		hunger=h;
		if(hunger%n!=0)
			reqd++;
		ans=min(ans, 0.8*c*reqd);
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}