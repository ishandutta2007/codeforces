#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
#define ll long long
const int N=1e6;
struct re{
	ll a,b;
}a[N];
ll b[N];
bool cmp(re x,re y)
{
	return x.a<y.a;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		ll n,c;
		cin>>n>>c;
	    ll c2=(c+1)/2;
	    ll c3=c2; 
		ll ans=0;
		rep(i,1,n) cin>>a[i].a,a[i].b=i;
		bool tf=0;
		rep(i,1,n)
		  if (a[i].a>=c2&&a[i].a<=c)
		  {
		  	cout<<1<<endl;
		  	cout<<i<<endl;
		  	tf=1; break;
		  }
		if (tf) continue;
		sort(a+1,a+n+1,cmp);
		int cnt=0;
		dep(i,n,1)
		  if (a[i].a<=c3&&c2>0)
		  { 
		    b[++cnt]=a[i].b; c2-=a[i].a;
		  }
		if (c2<=0)
		{
			cout<<cnt<<endl;
			rep(i,1,cnt) cout<<b[i]<<" ";
			cout<<endl;
		} else cout<<-1<<endl;
	}
	return 0; 
}