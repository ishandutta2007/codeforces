#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
ll n,m;
const int N=1e6;
ll jc[N];
ll sum[N];
int sum2[N];
int main()
{
	int T;
	cin>>T;
	jc[0]=1;
	rep(i,1,15) jc[i]=jc[i-1]*i;
	rep(i,1,(1<<15)-1)
	{
		rep(j,1,15)
		  if ((i>>(j-1))&1) sum[i]+=jc[j],sum2[i]++;
	}
	while (T--)
	{
		cin>>n;
		int ans=1e9;
		rep(i,0,(1<<15)-1)
		  if (n>=sum[i])
		  {
		  	 ans=min(ans,__builtin_popcountll(n-sum[i])+sum2[i]);
		  }
		cout<<ans<<endl;
	}
	return 0;
}