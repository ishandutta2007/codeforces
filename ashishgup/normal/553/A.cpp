#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=2e5+5;
const int MOD=1e9+7;

int n;
int a[N], fact[N], invfact[N];

int modinv(int k)
{
    return pow(k, MOD-2, MOD);
}

void precompute()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    invfact[N-1]=modinv(fact[N-1]);
    for(int i=N-2;i>=0;i--)
    {
        invfact[i]=invfact[i+1]*(i+1);
        invfact[i]%=MOD;
    }
}

int calc(int x, int y)
{
	int num=fact[x+y-1];
	num*=invfact[x];
	num%=MOD;
	num*=invfact[y-1];
	num%=MOD;
	return num;
}

int32_t main()
{
	IOS;
	precompute();
	cin>>n;
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=calc(a[1], a[2]);
	int sum=a[1]+a[2];
	for(int i=3;i<=n;i++)
	{
		ans*=calc(sum, a[i]);
		sum+=a[i];
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}