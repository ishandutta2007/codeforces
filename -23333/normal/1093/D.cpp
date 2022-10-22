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
bool tt;
const int N=8.1e5;
int head[N],color[N],l,color0,color1,g[N];
struct re{
	int a,b;
}e[N*2];
const int mo=998244353;
IL void arr(int x,int y)
{
	e[++l].a=head[x];
	e[l].b=y;
	head[x]=l;
}
void dfs(int x)
{
	if (color[x]==0) color0++; else color1++;
	for (rint u=head[x];u;u=e[u].a)
	{
		int v=e[u].b;
		if (color[v]==-1)
		{ 
		  color[v]=color[x]^1; dfs(v); 
	    }
	    if ((color[v]^color[x])!=1) tt=0;
	}
}
int main()
{
	g[0]=1;
	rep(i,1,4e5) g[i]=g[i-1]*2%mo;
	int T;
	read(T);
	memset(color,-1,sizeof(color));
	while (T--)
	{
		int n,m;
		read(n); read(m);
		l=0;
		rep(i,1,m)
		{
			int x,y;
			read(x);read(y); arr(x,y); arr(y,x);
		}
		tt=1;
		ll ans=1;
		rep(i,1,n) 
		  if (color[i]==-1) 
		  {
		  	color0=0; color1=0;
		    color[i]=0,dfs(i);
		    ans=ans*(g[color0]+g[color1])%mo;
		  }
		if (!tt) wer(0),wer2();
		else
		{
			wer(ans),wer2();
		}
		memset(head,0,sizeof(head[0])*(n+10));
		memset(color,-1,sizeof(color[0])*(n+10));
	}
	fwrite(sr,1,C1+1,stdout);
	return 0;
}