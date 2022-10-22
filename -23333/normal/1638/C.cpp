#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
#define ll long long
const int P=998244353;
map<int,int> M;
const int N=1e6;
int a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		rep(i,1,n) cin>>a[i];
		int now=0;
		int cnt=0;
		rep(i,1,n)
		  if (a[i]>now)
		  {
		  	 b[++cnt]=i;
		  	 now=a[i];
		  }
		int ans=0;
		dep(i,n,1)
		{
			if (b[cnt]>=i) { ans++; cnt--;}
			while (cnt&&a[b[cnt-1]]>a[i]) cnt--;
		}
		cout<<ans<<endl;
	}
	return 0;
}