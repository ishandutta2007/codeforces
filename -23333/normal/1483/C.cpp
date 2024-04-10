#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
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
const int mo=1e9+7;
const int N=6e5;
struct re{
	ll a,b,c;
}a[N];
int ve[N];
#define mid ((h+t)/2)
struct stg{
	ll v[N*4],lazy[N*4];
	int down(int x)
	{
		v[x*2]+=lazy[x]; v[x*2+1]+=lazy[x];
		lazy[x*2]+=lazy[x]; lazy[x*2+1]+=lazy[x];
		lazy[x]=0;
	}
	void change(int x,int h,int t,int h1,int t1,ll k)
	{
		if (h1<=h&&t<=t1)
		{
			v[x]+=k; lazy[x]+=k; return;
		}
		down(x); 
		if (h1<=mid) change(x*2,h,mid,h1,t1,k);
		if (mid<t1)change(x*2+1,mid+1,t,h1,t1,k);
		v[x]=max(v[x*2],v[x*2+1]);
	}
	ll query(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return v[x];
		down(x);
		ll ans=-1e18;
		if (h1<=mid) ans=query(x*2,h,mid,h1,t1);
		if (mid<t1) ans=max(ans,query(x*2+1,mid+1,t,h1,t1));
		return ans; 
	}
}S;
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   rep(i,1,n) cin>>a[i].b;
   rep(i,1,n) cin>>a[i].a;
   int cnt=0;
   rep(i,1,n)
   {
   	  ll ans=0;
   	  if (i!=1) ans=S.query(1,1,n+1,2,i);
   	  S.change(1,1,n+1,i+1,i+1,ans+a[i].a);
   	  while (cnt>0&&a[ve[cnt]].b>a[i].b)
   	  {
   	  	S.change(1,1,n+1,ve[cnt-1]+2,ve[cnt]+1,a[i].a-a[ve[cnt]].a);
   	  	cnt--;
   	  }
   	  ve[++cnt]=i;
   }
   cout<<S.query(1,1,n+1,2,n+1);
   return 0;
}