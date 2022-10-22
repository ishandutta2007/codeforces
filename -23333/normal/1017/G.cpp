#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for(int i=h;i<=t;i++)
#define dep(i,t,h) for(int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define mep(x,y) memcpy(x,y,sizeof(y))
#define mid ((h+t)>>1)
namespace IO{
    char ss[1<<24],*A=ss,*B=ss;
    IL char gc()
    {
        return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
    }
    template<class T> void read(T &x)
    {
        rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
        while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f; 
    }
    char sr[1<<24],z[20]; ll Z,C1=-1;
    template<class T>void wer(T x)
    {
        if (x<0) sr[++C1]='-',x=-x;
        while (z[++Z]=x%10+48,x/=10);
        while (sr[++C1]=z[Z],--Z);
    }
    IL void wer1()
    {
        sr[++C1]=' ';
    }
    IL void wer2()
    {
        sr[++C1]='\n';
    }
    template<class T>IL void maxa(T &x,T y) {if (x<y) x=y;}
    template<class T>IL void mina(T &x,T y) {if (x>y) x=y;} 
    template<class T>IL T MAX(T x,T y){return x>y?x:y;}
    template<class T>IL T MIN(T x,T y){return x<y?x:y;}
};
using namespace IO;
const int N=2.1e5;
struct re{
	int a,b;
}e[N*2];
int head[N],l,n,m;
IL void arr(int x,int y)
{
	e[++l].a=head[x];
	e[l].b=y;
	head[x]=l;
}
struct re2{
	int a[2];
	re2() { a[0]=a[1]=0; }
	re2(int x,int y) {a[0]=x; a[1]=y;};
	re2 operator *(const re2 &o) const
	{
		re2 c;
		c.a[0]=a[0]+o.a[0]; c.a[1]=MAX(a[1]+o.a[0],o.a[1]);
		return c;
    }
};
int fa[N],num[N],son[N],dfn[N],top[N],cnt;
void dfs(int x,int y)
{
	num[x]=1; fa[x]=y;
	for (rint u=head[x];u;u=e[u].a)
	{
		int v=e[u].b;
		if (v!=y)
		{ 
		  dfs(v,x);
		  num[x]+=num[v];
		  if (num[son[x]]<num[v]) son[x]=v;
	    }
	}
}
void dfs1(int x,int y,int z)
{
	top[x]=y; dfn[x]=++cnt;
	if (son[x]) dfs1(son[x],y,x);
	for (rint u=head[x];u;u=e[u].a)
	{
		int v=e[u].b;
		if (v!=z&&v!=son[x])
		{
			dfs1(v,v,x);
		}
	}
}
struct sgt{
	re2 sum[N*4];
	bool lazy[N*4];
	#define updata(x) sum[x]=sum[x*2]*sum[x*2+1]
	IL void down(int x,int h,int t)
	{
		if (lazy[x])
		{
			lazy[x*2]=lazy[x*2+1]=1; lazy[x]=0;
			sum[x*2]=re2(-(mid-h+1),-1);
			sum[x*2+1]=re2(-(t-mid),-1);
		}
	}
	void build(int x,int h,int t)
	{
		if (h==t) { sum[x]=re2(-1,-1); return;}
		build(x*2,h,mid); build(x*2+1,mid+1,t);
		updata(x);
	}
	void change(int x,int h,int t,int pos,int k)
    {
    	if (h==t) { sum[x]=re2(k,k);return; }
    	down(x,h,t);
    	if (pos<=mid) change(x*2,h,mid,pos,k);
    	else change(x*2+1,mid+1,t,pos,k);
    	updata(x);
    }
    re2 query(int x,int h,int t,int h1,int t1)
    {
    	if (h1<=h&&t<=t1) return sum[x];
    	down(x,h,t);
    	if (h1<=mid&&mid<t1) return query(x*2,h,mid,h1,t1)*query(x*2+1,mid+1,t,h1,t1);
    	else if (h1<=mid) return query(x*2,h,mid,h1,t1);
    	else return query(x*2+1,mid+1,t,h1,t1);
    }
    void push(int x,int h,int t,int h1,int t1)
    {
    	if (h1<=h&&t<=t1) { lazy[x]=1; sum[x]=re2(-(t-h+1),-1); return;}
    	down(x,h,t);
    	if (h1<=mid) push(x*2,h,mid,h1,t1); 
		if (mid<t1) push(x*2+1,mid+1,t,h1,t1);
    	updata(x);
    }
}S;
IL int query(int x)
{
    int ans=-1;
    re2 p1=re2(0,-1);
	while (x)
	{
		re2 p=S.query(1,1,n,dfn[top[x]],dfn[x]);
		p1=p*p1;
		ans=max(ans,p1.a[1]);
		x=fa[top[x]];
	}
	return ans;
}
int main()
{
	read(n); read(m);
	rep(i,2,n)
	{
		int x;
		read(x);
		arr(i,x); arr(x,i);
    }
    dfs(1,0); dfs1(1,1,0);
    S.build(1,1,n);
    rep(i,1,m)
    {
    	int kk,x;
    	read(kk); read(x);
    	if (kk==1)
    	{
    		S.change(1,1,n,dfn[x],S.query(1,1,n,dfn[x],dfn[x]).a[0]+1);
    	}
    	if (kk==2)
    	{
    		S.push(1,1,n,dfn[x],dfn[x]+num[x]-1);
            int ans=query(x);
            S.change(1,1,n,dfn[x],-ans-2);
    	}
    	if (kk==3)
    	{
    		if (query(x)>=0) cout<<"black"<<endl;
    		else cout<<"white"<<endl;
    	}
    }
	return 0;
}