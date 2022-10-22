#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6+10;
int a[N],n,m,k;
bool solve(int *a,int n,int m)
{
	ll sum=0,ans=0;
	rep(i,1,k)
	  if (a[i]>=2*n) {sum+=a[i]/n;ans=max(ans,1ll*a[i]/n);}
	if (m%2==1)
	{
		if (sum>=m&&ans>=3) return 1;
		else return 0;
	} else
	if (sum>=m) return 1;
	return 0;
}
int main()
{
//	freopen("1.in","r",stdin);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m>>k;
		rep(i,1,k) cin>>a[i];
		bool tt=solve(a,n,m)|solve(a,m,n);
		if (tt) cout<<"Yes"<<endl;
		else cout<<"No"<<endl; 
	}
	return 0;
}