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

const int N=1005;

int n, r;
int a[N];
double ans[N];

double compute(int k)
{
	double cury=r;
	for(int i=1;i<=k-1;i++)
	{
		if(abs(a[k]-a[i])>2*r)
			continue;
		double rhs=4*r*r - ((a[k]-a[i])*(a[k]-a[i]));
		rhs=sqrtl(rhs);
		double tempy=ans[i]+rhs;
		cury=max(cury, tempy);
	}
	return cury;
}

int32_t main()
{
    IOS;
    cin>>n>>r;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    ans[1]=r;
    for(int i=2;i<=n;i++)
    {
    	ans[i]=compute(i);
    }
    cout<<fixed<<setprecision(12);
    for(int i=1;i<=n;i++)
    {
    	cout<<ans[i]<<" ";
    }
    return 0;
}