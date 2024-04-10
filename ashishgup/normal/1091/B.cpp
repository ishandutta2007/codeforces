#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, sumx=0, sumy=0;
int x[N], y[N], a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		sumx+=x[i];
		sumy+=y[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sumx+=a[i];
		sumy+=b[i];
	}
	sumx/=n;
	sumy/=n;
	cout<<sumx<<" "<<sumy;
	return 0;
}