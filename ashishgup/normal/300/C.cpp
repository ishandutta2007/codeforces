#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=1e6+5;
const int MOD=1e9+7;

int a, b, n;
int fact[N], invfact[N];

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

int nCr(int x, int y)
{
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}

int check(int k)
{
	while(k>0)
	{
		if(k%10!=a && k%10!=b)
			return 0;
		k/=10;
	}
	return 1;
}

int32_t main()
{
	IOS;
	cin>>a>>b>>n;
	precompute();
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int suma=a*i;
		int sumb=b*(n-i);
		if(check(suma+sumb))
		{
			ans+=nCr(n, i);
			ans%=MOD;
		}
	}
	cout<<ans;
	return 0;
}