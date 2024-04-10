#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
char s[2][N];
ll a[N],b[N],c1[N],c2[N];
int n;
int gcd(int x,int y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
map<ll,int> M;
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		ll ans=0;
		rep(i,1,n)
		{ 
		  cin>>a[i]>>b[i];
		  c1[a[i]]++;
	    }
	    rep(i,1,n)
	    {
	      c2[b[i]]+=c1[a[i]]-1;
	    }
	    //ans=1ll*n*n*n;
	    rep(i,1,n)
	      ans-=c2[b[i]]-(c1[a[i]]-1);
	    //ans/=2;
	    ans+=1ll*n*(n-1)*(n-2)/6;
	    rep(i,1,n) c2[i]=c1[i]=0;
	    cout<<ans<<endl;
	}
	return 0;
}