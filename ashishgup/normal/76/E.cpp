#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0, sumx=0, sumy=0;
int x[N], y[N], prefx[N], prefy[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		ans+=(n-1)*x[i]*x[i] + (n-1)*y[i]*y[i];
		prefx[i]=prefx[i-1] + x[i];
		prefy[i]=prefy[i-1] + y[i];
	}
	for(int i=n;i>=1;i--)
	{
		ans-=2*x[i]*prefx[i-1];
		ans-=2*y[i]*prefy[i-1];
	}
	cout<<ans;
	return 0;
}