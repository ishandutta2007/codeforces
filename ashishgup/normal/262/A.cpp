#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k, ans=0;
int a[N];

int check(int x)
{
	int ct=0;
	while(x>0)
	{
		int cur=x%10;
		ct+=((cur==4)||(cur==7));
		x/=10;
	}
	return ct<=k;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=check(a[i]);
	}
	cout<<ans;
	return 0;
}