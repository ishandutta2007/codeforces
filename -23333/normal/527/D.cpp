#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (itn i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
#define mid (h+((t-h)>>1))
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
const int N=3e5;
const int N1=8e6;
const int M=2e9;
struct re{
	int x,w;
}a[N];
int rt,n;
bool cmp(re x,re y)
{
	return x.x<y.x;
}
struct sgt{
  int cnt,ls[N1],rs[N1],v[N1];
  void change(int &x,int h,int t,int pos,int k)
  {
  	if (!x) x=++cnt;
  	maxa(v[x],k);
  	if (h==t) return;
  	if (pos<=mid) change(ls[x],h,mid,pos,k);
  	else change(rs[x],mid+1,t,pos,k);
  }
  int query(int x,int h,int t,int h1,int t1)
  {
  	if (h1<=h&&t<=t1) return v[x];
  	int ans=0;
  	if (h1<=mid) maxa(ans,query(ls[x],h,mid,h1,t1));
  	if (mid<t1) maxa(ans,query(rs[x],mid+1,t,h1,t1));
  	return ans;
  }
}S;
int main()
{
	read(n);
	rep(i,1,n)
	{
		read(a[i].x); read(a[i].w);
	}
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)
	{
		int k=a[i].x-a[i].w;
		int ans=0;
		if (k>0) ans=S.query(rt,1,M,1,k);
		S.change(rt,1,M,a[i].w+a[i].x,ans+1);
	}
	cout<<S.v[1]<<endl;
	return 0;
}