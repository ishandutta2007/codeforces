#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
#define mep(x,y) memcpy(x,y,sizeof(y))
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
	IL void wer1() { sr[++C]=' ';}
	IL void wer2() { sr[++C]='\n';}
	template<class T>IL void maxa(T &x,T y) { if (x<y) x=y;} 
	template<class T>IL void mina(T &x,T y) { if (x>y) x=y;}
	template<class T>IL T MAX(T x,T y) {return x>y?x:y;}
	template<class T>IL T MIN(T x,T y) {return x<y?x:y;}
};
using namespace IO;
const int N=1.5e5;
int v[N],q,n,pos[N],cnt,p[N];
struct re{
	int a,b,c,d;
}a[N*4],b[N*10];
ll ans[N*4];
void change(int x1,int x2,int y1,int y2,int k)
{
	b[++cnt]=(re){x1,y1,y2,k};
	b[++cnt]=(re){x2+1,y1,y2,-k};
}
const int N1=N*4;
struct sgt{
	ll now[N1];
	int tim[N1],num[N1],v[N1],lazy[N1];
	void build(int x,int h,int t)
	{
		num[x]=(t-h+1);
		if (h==t) return;
		build(x*2,h,mid); build(x*2+1,mid+1,t); 
	}
	IL void down(int x)
	{
		if (lazy[x])
		{
		  lazy[x*2]+=lazy[x]; lazy[x*2+1]+=lazy[x];
		  v[x*2]+=lazy[x]; v[x*2+1]+=lazy[x];
		  lazy[x]=0;
	    }
	    if (tim[x])
	    {
		if (v[x*2]==v[x])
		{
			now[x*2]+=1ll*tim[x]*num[x*2];
			tim[x*2]+=tim[x]; 
		}
		if (v[x*2+1]==v[x]) 
		{
			now[x*2+1]+=1ll*tim[x]*num[x*2+1];
			tim[x*2+1]+=tim[x];
		}
		tim[x]=0;
	    }
	}
	IL void updata(int x)
	{
		now[x]=now[x*2]+now[x*2+1];
		v[x]=MIN(v[x*2],v[x*2+1]);
		num[x]=0;
		if (v[x]==v[x*2]) num[x]+=num[x*2];
		if (v[x]==v[x*2+1]) num[x]+=num[x*2+1];
	}
	void change(int x,int h,int t,int h1,int t1,int k)
	{
		if (h1<=h&&t<=t1)
		{
			v[x]+=k; lazy[x]+=k; return;
		}
		down(x);
		if (h1<=mid) change(x*2,h,mid,h1,t1,k);
		if (mid<t1) change(x*2+1,mid+1,t,h1,t1,k);
		updata(x);
	}
	ll query(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return(now[x]);
		down(x);
		ll ans=0;
		if (h1<=mid) ans+=query(x*2,h,mid,h1,t1);
		if (mid<t1) ans+=query(x*2+1,mid+1,t,h1,t1);
		return ans; 
	}
}S;
bool cmp(re x,re y)
{
	return x.a<y.a; 
}
int main()
{
	read(n);
	rep(i,1,n) read(v[i]),pos[v[i]]=i;
	rep(i,1,n-1)
	{
	  change(1,i,i+1,n,1);
	  change(i+1,n,1,i,1);
	  int x1=pos[i],x2=pos[i+1];
	  if (x1>x2) swap(x1,x2);
	  change(1,x1,x2,n,-1);
	  change(x2,n,1,x1,-1);
    }
	read(q);
	int q1=q*4;
	rep(i,1,q)
	{
		int x,y;
		read(x); read(y);
		a[i*4-3]=(re){y,y,i*4-3};
		a[i*4-2]=(re){x-1,y,i*4-2};
		a[i*4-1]=(re){y,x-1,i*4-1};
		a[i*4]=(re){x-1,x-1,i*4};
		p[i]=y-x+1;
	}
	int now=1,lst=1;
	S.build(1,1,n);
	sort(a+1,a+q1+1,cmp);
	sort(b+1,b+cnt+1,cmp);
	rep(i,1,q1)
	{
		while(now<=cnt&&b[now].a<=a[i].a)
		{
			S.tim[1]+=b[now].a-lst; S.now[1]+=1ll*(b[now].a-lst)*S.num[1];
			lst=b[now].a;
			S.change(1,1,n,b[now].b,b[now].c,b[now].d);
			now++;
		}
		S.tim[1]+=a[i].a+1-lst; S.now[1]+=1ll*(a[i].a+1-lst)*S.num[1];
		lst=a[i].a+1;
		if (a[i].b) ans[a[i].c]=S.query(1,1,n,1,a[i].b);
	}
	rep(i,1,q)
	  wer((ans[i*4-3]-ans[i*4-2]-ans[i*4-1]+ans[i*4]-p[i])/2+p[i]),wer2();
	fwrite(sr,1,C+1,stdout); 
	return 0;
}