#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
ll a[N],b[N];
int n,m,q;
char ss[1<<24],*A=ss,*B=ss;
inline char gc()
{
  return (A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++);
}
template<class T>void read(T &x)
{
  int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=c^48;
  while (c=gc(),47<c&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f;
}
char sr[1<<24],z[20]; int C=-1,Z;
template <class T> void wer(T x)
{
  if (x<0) sr[++C]='-',x=-x;
  while (z[++Z]=x%10+48,x/=10);
  while (sr[++C]=z[Z],--Z); sr[++C]='\n';
}
struct re{
	ll a,b;
	inline re operator +(const re x)const{
		return {a+x.a,b+x.b};
	}
};
#define mid ((h+t)/2)
struct sgt{
	ll sum1[N*4],sum2[N*4],lazy[N*4],mx[N*4];
	inline ll js(int x,int y)
	{
		return 1ll*(y+x)*(y-x+1)/2;
	}
	inline void updata(int x)
	{
		sum1[x]=sum1[x*2]+sum1[x*2+1];
		sum2[x]=sum2[x*2]+sum2[x*2+1];
		mx[x]=max(mx[x*2],mx[x*2+1]);
	}
	inline void gg(int x,int h,int t,ll k)
	{
		sum1[x]+=k*js(h,t); sum2[x]+=k*(t-h+1);
		lazy[x]+=k; mx[x]+=k;
	}
	inline void down(int x,int h,int t)
	{
		if (lazy[x])
		{
			gg(x*2,h,mid,lazy[x]);
			gg(x*2+1,mid+1,t,lazy[x]);
			lazy[x]=0;
		}
	}
	void g(int x,int h,int t,int h1,int t1,ll k)
	{
		if (h1<=h&&t<=t1)
		{
			gg(x,h,t,k); 
			return;
		}
		down(x,h,t);
		if (h1<=mid) g(x*2,h,mid,h1,t1,k);
		if (mid<t1) g(x*2+1,mid+1,t,h1,t1,k);
		updata(x);
	}
	re q1(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1)
		{
		   return {sum1[x],sum2[x]};	
		}
		down(x,h,t);
		re ans={0,0};
		if (h1<=mid) ans=q1(x*2,h,mid,h1,t1);
		if (mid<t1) ans=ans+q1(x*2+1,mid+1,t,h1,t1);
		return ans;
	}
	int q2(int x,int h,int t,ll k)
	{
		if (h==t)
		{ 
		  if (mx[x]>k) return h;
		  else return h+1;
	    }
	    down(x,h,t);
		if (mx[x*2]>k) return q2(x*2,h,mid,k);
		else return q2(x*2+1,mid+1,t,k);
	}
}S;
int main()
{
	ios::sync_with_stdio(false);
//	cin>>n>>m>>q;
    read(n); read(m); read(q);
	rep(i,1,n) read(a[i]);
	rep(i,1,m) read(b[i]);
	rep(i,2,m) S.g(1,1,m,i,i,b[i]-b[i-1]);
	rep(i,1,q){
		 ll kk,x,y;
		 read(kk); read(x); read(y);
	  	// cin>>kk>>x>>y;
	  	 if (kk==1)
	  	 {
	  	 	int pp=0;
	  	 	rep(i,n-x+1,n)
	  	 	{
	  	 		pp+=y;
	  	 	    a[i]+=pp;
	  	 	}
	  	 } else
	  	 {
	  	 	if (x==m) b[1]+=y;
	  	 	S.g(1,1,m,max(2,(int)(m-x+1)),m,y);
	  	 }
	  	 ll ans=(n+m-1)*(a[1]+b[1]);
	  	 ll now=2;
	  	 rep(i,2,n)
	  	 {
	  	 	if (now<=m)
	  	 	{
	  	 		int kk=S.q2(1,1,m,a[i]-a[i-1]);
	  	 		kk--;
	  	 		if (kk>=now)
	  	 		{
	  	 			re Q=S.q1(1,1,m,now,kk);
	  	 			ans-=Q.a;
	  	 			ans+=Q.b*(n-i+1+m+1);
	  	 			now=kk+1;
	  	 		}
	  	 	}
	  	 	ans+=(n-i+1+m-now+1)*(a[i]-a[i-1]); 
	  	 }
	  	 if (now<=m)
	  	 {
	  	 	re Q=S.q1(1,1,m,now,m);
	  	 	ans-=Q.a;
	  	 	ans+=Q.b*(m+1);
	  	 }
	  	 wer(ans);
	  //	 cout<<ans<<"\n";
    }
    fwrite(sr,1,C+1,stdout); 
	return 0; 
}