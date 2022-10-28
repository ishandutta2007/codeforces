#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N], b[N], c[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n/2;i++)
	{
		cin>>a[i];
		b[i]=2*(i-1) + 1;
		c[i]=2*i;
	}
	sort(a+1, a+n/2+1);
	int ans1=0, ans2=0;
	for(int i=1;i<=n/2;i++)
	{
		ans1+=abs(a[i]-b[i]);
		ans2+=abs(a[i]-c[i]);
	}
	cout<<min(ans1, ans2);
	return 0;
}