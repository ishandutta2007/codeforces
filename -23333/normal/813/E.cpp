#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (itn i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
#define mid ((h+t)>>1)
namespace IO
{
  char ss[1<<24],*A=ss,*B=ss;
  IL char gc()
  {
  	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
  }
  template<class T>void read(T &x)
  {
 	  rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	  while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f;
  }
  char sr[1<<24],z[20]; int Z,C=-1;
  template<class T>void wer(T x)
  {
  	if (x<0) sr[++C]='-',x=-x;
  	while (z[++Z]=x%10+48,x/=10);
  	while (sr[++C]=z[Z],--Z);
  }
  IL void wer1()
  {
  	sr[++C]=' ';
  }
  IL void wer2()
  {
  	sr[++C]='\n';
  }
  template<class T>IL void maxa(T &x,T y) { if (x<y) x=y; }
  template<class T>IL void mina(T &x,T y) { if (x>y) x=y; }
  template<class T>IL T MAX(T x,T y) {return x>y?x:y;}
  template<class T>IL T MIN(T x,T y) {return x<y?x:y;}
};
using namespace IO;
const int N=2e5;
const int N1=6e6;
int a[N],n,m,rt[N];
vector<int> ve[N];
struct sgt{
	int cnt,ls[N1],rs[N1],v[N1];
	void change(int lst,int &x,int h,int t,int pos)
	{
		x=++cnt;
		v[x]=v[lst]+1; ls[x]=ls[lst]; rs[x]=rs[lst];
		if (h==t)
		{
			return ;
		}
	  	if (pos<=mid) change(ls[lst],ls[x],h,mid,pos);
	  	else change(rs[lst],rs[x],mid+1,t,pos);
	}
	int query(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return(v[x]);
		int ans=0;
		if (h1<=mid) ans+=query(ls[x],h,mid,h1,t1);
		if (mid<t1) ans+=query(rs[x],mid+1,t,h1,t1);
		return ans; 
	}
    int query2(int x,int y)
    {
    	return query(rt[y],0,n,0,x-1)-query(rt[x-1],0,n,0,x-1);
    }
}S;
int main()
{
	read(n); read(m);
	rep(i,1,n) 
	{
	  read(a[i]);
	  int k=0;
	  if (ve[a[i]].size()>=m) 
	    k=ve[a[i]][ve[a[i]].size()-m];
	  ve[a[i]].push_back(i);
	  S.change(rt[i-1],rt[i],0,n,k);
    }
    int q;
	read(q);
	int ans=0;
	rep(i,1,q)
	{
		int x,y;
		read(x); read(y);
		x=(x+ans)%n+1,y=(y+ans)%n+1;
		if (x>y) swap(x,y);
		ans=S.query2(x,y);
		wer(ans); wer2();
	}
	fwrite(sr,1,C+1,stdout);
	return 0;
}