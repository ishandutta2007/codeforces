#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
const int N=1e6;
int n,m;
struct re{
	int a,b,c,d;
};
re a[N],b[N];
int fa[N],c[N],e[N],cnt;
ll d[N];
ll gg=0;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp(re x,re y)
{
	return x.c<y.c;
}
void solve(ll x)
{
   int k=upper_bound(e+1,e+cnt+1,x)-e-1;
 //  cout<<x<<" "<<k<<" "<<c[k]*x+d[k]<<"\n";
   gg^=c[k]*x+d[k];	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,m) cin>>a[i].a>>a[i].b>>a[i].c;
	sort(a+1,a+m+1,cmp);
    vector<int> ve;
	rep(i,1,m)
	  rep(j,i,m)
	  {
	  	  int gg=(a[i].c+a[j].c+1)/2;
	  	  ve.push_back(gg);
	  	  ve.push_back(gg-1);
	  	  ve.push_back(gg+1);
	  }
	ve.push_back(0);
	sort(ve.begin(),ve.end());
	ve.erase(unique(ve.begin(),ve.end()),ve.end());
	for (auto v:ve)
	{
		rep(i,1,n) fa[i]=i;
		rep(j,1,m) b[j].a=a[j].a,b[j].b=a[j].b,b[j].c=abs(a[j].c-v),b[j].d=a[j].c;
	    sort(b+1,b+m+1,cmp);
	    ll ans0=0,ans1=0;
		rep(i,1,m)
		{
		   int f1=find(b[i].a),f2=find(b[i].b);
		   if (f1!=f2)
		   {
		   	  fa[f1]=f2;
		   	  if (b[i].d>=v) ans0--,ans1+=b[i].d;
		   	  else ans0++,ans1-=b[i].d;
		   }
	    }
	    cnt++;
	    c[cnt]=ans0; d[cnt]=ans1; e[cnt]=v;
	}
	int p,k;
	ll a,b,c,x;
	cin>>p>>k>>a>>b>>c;
	rep(i,1,p)
	{
		cin>>x;
		solve(x);
	}
	rep(i,p+1,k)
	{
	  x=(x*a+b)%c;
	  solve(x);
    }
    cout<<gg<<endl;
	return 0;
}