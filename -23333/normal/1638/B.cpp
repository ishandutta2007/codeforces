#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
#define ll long long
const int P=998244353;
map<int,int> M;
const int N=1e6;
int a[N];
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
		int gg[2]; gg[0]=0; gg[1]=0;
		bool tt=0;
		rep(i,1,n)
		{ 
		  if (gg[a[i]%2]>a[i]) tt=1;
		  gg[a[i]%2]=max(gg[a[i]%2],a[i]);
	    }
	    if (tt) cout<<"No"<<endl;
	    else cout<<"Yes"<<endl;
	}
	return 0;
}