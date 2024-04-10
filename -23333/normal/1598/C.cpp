#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
char s[2][N];
int a[N];
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
		M.clear();
		cin>>n;
		ll ans=0;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n) ans+=a[i];
		ll gg=gcd(ans,n);
		ans/=gg; ll n2=n/gg;
		if (n2>2)
		{
			cout<<0<<endl;
			continue;
		}
		if (n2==1) ans*=2;
		ll now=0;
		rep(i,1,n)
		{
		  now+=M[ans-a[i]];
		  M[a[i]]++;
	    }
	    cout<<now<<endl;
	}
	return 0;
}