#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int l1, r1, t1, l2, r2, t2;

int value(int a, int b, int c, int d)
{
	int L=max(a, c);
	int R=min(b, d);
	int ans=(R-L+1);
	ans=max(ans, 0LL);
	return ans;
}

int32_t main()
{
	IOS;
	cin>>l1>>r1>>t1>>l2>>r2>>t2;
	int k=(r1-l1);
	int m=(k+1);
	int L=l2-l1;
	int R=r2-l1;
	int g=__gcd(t1, t2);
	int xx=L/g;
	xx++;
	int ans=0;
	for(int x=xx-2;x<=xx+2;x++)
		ans=max(ans, value(0, k, L-g*x, R-g*x));
	cout<<ans;
	return 0;
}