#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n, k, ans=1;
int a[N], b[N], mx[N], pw[N];

int32_t main()
{
	IOS;
	pw[0]=1;
	for(int i=1;i<=10;i++)
	{
		pw[i]=pw[i-1]*10;
		mx[i]=pw[i]-1;
	}
	cin>>n>>k;
	for(int i=1;i<=n/k;i++)
		cin>>a[i];
	for(int i=1;i<=n/k;i++)
		cin>>b[i];
	for(int i=1;i<=n/k;i++)
	{
		int total=1 + mx[k]/a[i];
		int remainder=(b[i]*pw[k-1])%a[i];
		if(remainder==0)
			remainder+=a[i];
		int remove=(mx[k-1]+remainder)/a[i];
		total-=remove;
		total+=MOD;
		total%=MOD;
		ans*=total;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}