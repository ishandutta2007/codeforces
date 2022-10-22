#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int ans=0;
		int n,m;
		cin>>n;
		rep(i,1,n) cin>>a[i];
		int cnt=0;
		rep(i,1,n) if (a[i-1]==0&&a[i]!=0) cnt++;
		cout<<min(cnt,2)<<endl;
	}
	return 0;
}