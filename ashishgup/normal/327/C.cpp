#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=1e9+7;

string s;
int n, k;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b>0)
	{
		if(b%2)
		{
			ans*=a;
			ans%=m;
		}
		a*=a;
		a%=m;
		b/=2;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

int gp(int a)
{
	int num=pow(2LL, a, MOD);
	int store=pow(2LL, (n*k)%(MOD-1), MOD);
	store-=1;
	store+=MOD;
	store%=MOD;
	num*=store;
	num%=MOD;
	int den=pow(2LL, n, MOD);
	den-=1;
	int deninv=modinv(den);
	num*=deninv;
	num%=MOD;
	return num;
}

int32_t main()
{
    IOS;
    cin>>s>>k;
    n=s.size();
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
    	if(s[i]=='0'||s[i]=='5')
    	{
    		ans+=gp(i);
    		ans%=MOD;
    	}
    }
    cout<<ans;
    return 0;
}