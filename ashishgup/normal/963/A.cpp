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
const int MOD=1e9+9;

int n, a, b, k;

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

int32_t main()
{
	IOS;
	cin>>n>>a>>b>>k;
	int cura=pow(a, n, MOD);
	int curb=1;
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		int current=cura * curb;
		current%=MOD;
		char ch;
		cin>>ch;
		if(ch=='-')
			current*=-1;
		current+=MOD;
		current%=MOD;
		ans+=current;
		ans%=MOD;
		cura*=modinv(a);
		cura%=MOD;
		curb*=b;
		curb%=MOD;
	}
	int len=(n+1)/k;
	int rationum=pow(b, k, MOD);
	int ratioden=pow(a, k, MOD);
	int ratio=rationum * modinv(ratioden);
	ratio%=MOD;
	if(ratio==1)
	{
		ans=ans*len;
		ans%=MOD;
		cout<<ans;
		return 0;
	}
	int num=pow(ratio, len, MOD);
	num-=1;
	int den=ratio-1;
	num=abs(num);
	den=abs(den);
	int deninv=modinv(den);
	int mult=num * deninv;
	mult%=MOD;
	ans*=mult;
	ans%=MOD;
	cout<<ans;
	return 0;
}