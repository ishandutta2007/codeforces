#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
ll T,n,m;
const int N=1e6+10;
char s[N];
int a[N],b[N],c[N];
ll ans=0;
vector<int> ve[N];
map<vector<int>,int> M;
const int mo=998244353;
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
		int n,k;
		cin>>n>>k;
		rep(i,1,n) cin>>a[i];
		ll ans=1;
		rep(i,1,n-k)
		  if (a[i]==-1) ans=ans*(k+1+i-1)%mo;
		  else if (a[i]==0) ans=ans*(k+1)%mo;
		rep(i,1,k) ans=ans*i%mo;
		rep(i,n-k+1,n)
		  if (a[i]!=0&&a[i]!=-1) ans=0;
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
6
3 5 4 6 2 1
3 6 4 5 2 1
*/