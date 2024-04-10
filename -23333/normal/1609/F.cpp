#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long 
#define mid ((h+t)/2)
const int N=1.01e6;
const int M=2630000;
char ss[1<<26],*A=ss,*B=ss;
inline char gc()
{
  return (A==B&&(B=(A=ss)+fread(ss,1,1<<26,stdin),A==B)?EOF:*A++);
}
template<class T>void read(T &x)
{
  int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=c^48;
  while (c=gc(),47<c&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f;
}
ll a[N];
int b[N],n;
struct re{
   ll a;
   int b,c;
};
struct re2{
	int a,b,c,d;
};
vector<re2> ve[62];
re st1[N],st2[N];
struct sgt{
  int v1[M],v2[M];
  short lazy[M];
  inline void clear()
  {
  	memset(v1,0,sizeof(v1));
  	memset(v2,0,sizeof(v2));
  	memset(lazy,0,sizeof(lazy));
  }
  inline void hh(int x,int h,int t,int k)
  {
  	lazy[x]+=k;
    if (k==2)
    {
    	v2[x]=t-h+1; v1[x]=0;
    } else
    if (k==1)
    {
    	int gg=t-h+1-v1[x]-v2[x];
    	v2[x]=v1[x]; v1[x]=gg;
    } else
    if (k==-1)
    {
    	v1[x]=v2[x];
    	v2[x]=0;
    } else
    if (k==-2)
    {
        v1[x]=v2[x]=0;
    }
  }
  inline void down(int x,int h,int t)
  {
  	if (lazy[x])
  	{
  		hh(x*2,h,mid,lazy[x]);
  		hh(x*2+1,mid+1,t,lazy[x]);
  		lazy[x]=0;
  	}
  }
  void g(int x,int h,int t,int h1,int t1,int k)
  { 
  	  if(h1<=h&&t<=t1)
  	  {
  	  	   hh(x,h,t,k); return;
  	  }
  	  down(x,h,t);
      if (h1<=mid) g(x*2,h,mid,h1,t1,k);	 
  	  if (mid<t1) g(x*2+1,mid+1,t,h1,t1,k);
  	  v1[x]=v1[x*2]+v1[x*2+1];
  	  v2[x]=v2[x*2]+v2[x*2+1]; 
  }
}S;
int main()
{
	ios::sync_with_stdio(false);
	read(n);
	cin>>n; 	
	rep(i,1,n) read(a[i]);
	if (n==1)
	{
		cout<<1<<endl;
		return 0;
    }
	rep(i,1,n)
	{ 
	  b[i]=__builtin_popcountll(a[i]);
    }
	int top1=0,top2=0;
	ll ans=0;
	dep(i,n,1)
	{
		int lst=i;
		while (top1&&a[i]<=st1[top1].a)
		{ 
		    ve[__builtin_popcountll(st1[top1].a)].push_back({st1[top1].b,st1[top1].c,-1,i});
			lst=st1[top1].c;
		    top1--;
		}
		ve[b[i]].push_back({i,lst,1,i});
		st1[++top1]={a[i],i,lst};
		lst=i;
		while(top2&&a[i]>=st2[top2].a)
		{
		    ve[__builtin_popcountll(st2[top2].a)].push_back({st2[top2].b,st2[top2].c,-1,i});
		    lst=st2[top2].c;
		    top2--;
		}
	    ve[b[i]].push_back({i,lst,1,i});
		st2[++top2]={a[i],i,lst}; 
	}
	rep(i,0,60)
	{
		S.clear();
		int now=n;
		for (auto v:ve[i])
		{
			if (v.d!=now)
			{
				ans+=1ll*S.v2[1]*(now-v.d);
			}
			S.g(1,1,n,v.a,v.b,v.c);
			now=v.d;
		}
		ans+=1ll*S.v2[1]*now;
	}
	cout<<ans<<endl;
	return 0; 
}