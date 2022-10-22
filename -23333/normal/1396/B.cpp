#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
int a[N],f[N];
int main()
{
	ios::sync_with_stdio(false);
	int n,T;
	cin>>T;
	while (T--)
	{
	  cin>>n;
	  int sum=0,tt=0;
	  rep(i,1,n) cin>>a[i],sum+=a[i],tt=max(tt,a[i]);
	  if (sum%2==1)
	  {
	  	cout<<"T"<<endl;
	  } else
	  {
	  	if (tt*2>sum) cout<<"T"<<endl;
	  	else cout<<"HL"<<endl;
	  }
    } 
	return 0; 
}