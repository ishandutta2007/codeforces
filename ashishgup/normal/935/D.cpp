#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=2e5+5;
const int MOD=1e9+7;

int n, m, ans=0;
int a[N], b[N];

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void rec(int i, int prob)
{
	if(i>n)
		return;
	if(a[i]==0 && b[i]==0)
	{
		int num=(m-1);
		int den=(2*m);
		int storegcd=gcd(num, den);
		num/=storegcd;
		den/=storegcd;
		int cur=(num);
		cur*=modinv(den);
		cur%=MOD;
		cur*=prob;
		cur%=MOD;
		ans+=cur;
		ans%=MOD;
		int newprob=prob * modinv(m);
		newprob%=MOD;
		rec(i+1, newprob);
	}
	else if(a[i]==0)
	{
		int num=(m-b[i]);
		int den=(m);
		int storegcd=gcd(num, den);
		num/=storegcd;
		den/=storegcd;
		int cur=(num);
		cur*=modinv(den);
		cur%=MOD;
		cur*=prob;
		cur%=MOD;
		ans+=cur;
		ans%=MOD;
		int newprob=prob * modinv(m);
		newprob%=MOD;
		rec(i+1, newprob);
	}
	else if(b[i]==0)
	{
		int num=(a[i]-1);
		int den=(m);
		int storegcd=gcd(num, den);
		num/=storegcd;
		den/=storegcd;
		int cur=(num);
		cur*=modinv(den);
		cur%=MOD;
		cur*=prob;
		cur%=MOD;
		ans+=cur;
		ans%=MOD;
		int newprob=prob * modinv(m);
		newprob%=MOD;
		rec(i+1, newprob);
	}
	else
	{
		if(a[i]>b[i])
		{
			ans+=prob;
			ans%=MOD;
			return;
		}
		else if(a[i]<b[i])
		{
			return;
		}
		else
		{
			rec(i+1, prob);
		}
	}
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
    	if(a[i]==0 || b[i]==0)
    		break;
    	if(a[i]>b[i])
    	{
    		cout<<"1";
    		return 0;
    	}
    	else if(a[i]<b[i])
    	{
    		cout<<"0";
    		return 0;
    	}
    }
    rec(1, 1);
    cout<<ans;
    return 0;
}