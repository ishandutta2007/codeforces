#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
const int mo=998244353;
char s[N];
int x[N],y[N],X[N],Y[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n,m,k,q;
		cin>>n>>m>>k>>q;
		rep(i,1,q) cin>>x[i]>>y[i];
		int cnt1=0,cnt2=0;
		int ans=0;
		bool tt=0;
		dep(i,q,1)
		{
			if (!((X[x[i]]&&Y[y[i]])||tt)) ans++;
			if (!X[x[i]])
			{
			    cnt1++;
			    X[x[i]]=1;
		    }
		    if (!Y[y[i]])
		    {
		    	cnt2++;
		    	Y[y[i]]=1;
		    }
		    if (cnt1==n||cnt2==m) tt=1;
		}
		int gg=1;
		rep(i,1,ans) gg=1ll*gg*k%mo;
		rep(i,1,n) X[i]=0;
		rep(i,1,m) Y[i]=0;
		cout<<gg<<endl;
	}
	return 0; 
}