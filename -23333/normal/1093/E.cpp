#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
#define mep(x) memcpy(x,y,sizeof(y))
#define mid ((h+t)>>1)
namespace IO{
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
	IL void wer1() {sr[++C]=' ';}
	IL void wer2() {sr[++C]='\n';}
	template<class T>IL void maxa(T &x,T y) { if (x<y) x=y;}
	template<class T>IL void mina(T &x,T y) { if (x>y) x=y;}
	template<class T>IL T MAX(T x,T y) {return x>y?x:y;}
	template<class T>IL T MIN(T x,T y) {return x<y?x:y;}
};
const int N=3e5;
const int M=N*8;
int a[N],b[N],c[N],d[N],e[N],ans[N],n,m;
struct re{
	int a,b,c,d;
}p[M],p1[M],p2[M];
#define lowbit(x) (x&(-x))
struct BIT{
	int sum[N];
	int query(int x)
	{
		int ans=0;
		for (int y=x;y>0;y-=lowbit(y)) ans+=sum[y]; 
		return ans;
	}
	void change(int x,int k)
	{
		for (;x<=n;x+=lowbit(x)) sum[x]+=k;
	}
}B;
bool cmp(re x,re y){
	return x.a<y.a;
}
void cdq_fz(int h,int t)
{
	if (h==t) return;
	int cnt1=0,cnt2=0;
	rep(i,h,mid)
	  if (p[i].c<=1) p1[++cnt1]=p[i];
	rep(i,mid+1,t)
	  if (p[i].c>=2)
	  {   
	    p2[++cnt2]=p[i];
	  }
	sort(p1+1,p1+cnt1+1,cmp);
	sort(p2+1,p2+cnt2+1,cmp);
	int t1=1;
	rep(i,1,cnt2)
	{
		while (t1<=cnt1&&p1[t1].a<=p2[i].a) B.change(p1[t1].b,p1[t1].c),t1++;
		ans[p2[i].d]+=(p2[i].c-3)*B.query(p2[i].b);
	}
	dep(i,t1-1,1) B.change(p1[i].b,-p1[i].c);
	cdq_fz(h,mid); 
	cdq_fz(mid+1,t);
}
bool t[N];
int main()
{
	IO::read(n); IO::read(m);
	rep(i,1,n) IO::read(a[i]),e[a[i]]=i;
	rep(i,1,n) IO::read(b[i]),c[b[i]]=i;
	rep(i,1,n) d[i]=c[a[i]];
	int num=0;
	rep(i,1,n) p[++num]=(re){i,d[i],1,i};
	rep(i,1,m)
	{
	  int kk,x1,y1,x2,y2,x,y;
	  IO::read(kk);
	  if (kk==1)
	  {
	  	t[i]=1;
	  	IO::read(x1); IO::read(x2); IO::read(y1); IO::read(y2);
	  	p[++num]=(re){x2,y2,4,i};
	  	p[++num]=(re){x2,y1-1,2,i};
	  	p[++num]=(re){x1-1,y2,2,i};
	  	p[++num]=(re){x1-1,y1-1,4,i};
	  } else
	  {
	  	IO::read(x); IO::read(y);
	  	p[++num]=(re){e[b[x]],x,-1,i};
	  	p[++num]=(re){e[b[x]],y,1,i};
	  	p[++num]=(re){e[b[y]],y,-1,i};
	  	p[++num]=(re){e[b[y]],x,1,i};
	  	swap(b[x],b[y]);
	  }
	}
	cdq_fz(1,num);
	rep(i,1,m) if (t[i]) IO::wer(ans[i]),IO::wer2();
	fwrite(IO::sr,1,IO::C+1,stdout);
	return 0;
}