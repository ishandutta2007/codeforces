#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=1e9+7;

int n, finans=0;
int a[N], f[N], mult[N], ans[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}	
	for(int i=1;i<N;i++)
	{
		for(int j=1;i*j<N;j++)
			mult[i]+=f[i*j];
	}
	for(int i=N-1;i>=2;i--)
	{
		int n=mult[i];
		ans[i]=n*pow(2LL, n-1, MOD);
		ans[i]%=MOD;
		for(int j=2;i*j<N;j++)
		{
			ans[i]-=ans[i*j];
			ans[i]+=MOD;
			ans[i]%=MOD;
		}
		finans+=i*ans[i];
		finans%=MOD;
	}
	cout<<finans;
	return 0;
}