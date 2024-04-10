#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
struct re{
	ll a,b;
}a[N],b[N];
int n,m,k;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		int gg=0;
		rep(i,1,n)
		{
			int x;
			cin>>x;
			ll now=1;
			while (x%m==0) x/=m,now*=m;
			if (a[gg].a==x) a[gg].b+=now;
			else a[++gg]={x,now};
	    }
	    cin>>k;
	    int gg2=0;
	    rep(i,1,k)
	    {
	    	int x;
	    	cin>>x;
	    	ll now=1;
			while (x%m==0) x/=m,now*=m;
			if (b[gg2].a==x) b[gg2].b+=now;
			else b[++gg2]={x,now};
	    }
	    bool tt=1;
	    if (gg!=gg2) tt=0;
	    rep(i,1,gg) if (b[i].a!=a[i].a||b[i].b!=a[i].b) tt=0;
	    if(tt) cout<<"Yes"<<endl;
		else cout<<"No"<<endl; 
	}
	return 0;
}