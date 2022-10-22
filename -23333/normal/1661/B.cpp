//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5+10;
const int mo=1e9+7;
int a[N],b[N],f[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	int n;
	n=32768;
	for (int i=n-1;i>0;i--)
	{
		f[i]=f[i+1]+1;
		int j=i;
		int cnt=0;
		while (j%2==0) j/=2,cnt++;
		f[i]=min(f[i],15-cnt);
    }
	cin>>n;
	rep(i,1,n)
	{
		int x;
	  cin>>x;
	  cout<<f[x]<<" ";
    }
	return 0;
}