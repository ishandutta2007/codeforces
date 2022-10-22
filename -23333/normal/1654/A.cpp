#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5010;
int n,m;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		rep(i,1,n) cin>>a[i];
		sort(a+1,a+n+1);
		cout<<a[n-1]+a[n]<<endl;
    }
	return 0;
}