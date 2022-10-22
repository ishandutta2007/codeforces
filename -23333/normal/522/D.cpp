#include <bits/stdc++.h>
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
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
	template<class T>IL void maxa(T &x,T y) {if (x<y) x=y;}
	template<class T>IL void mina(T &x,T y) {if (x>y) x=y;}
	template<class T>IL T MAX(T x,T y) { return x>y?x:y;}
	template<class T>IL T MIN(T x,T y) { return x<y?x:y;}
};
using namespace std;
using namespace IO;
const int N=6e5;
map<int,int> M;
int cnt,a[N],cmp_d,rt;
struct re{
	int x,y,z;
}p[N];
bool cmp(re x,re y)
{
	if (!cmp_d) return x.x<y.x;
	else return x.y<y.y;
}
const int INF=1e9;
struct kd_tree{
	int v[N],pv[N],ls[N],rs[N],Mx[N],Nx[N],My[N],Ny[N];
	kd_tree()
	{
		v[0]=pv[0]=INF;
		Nx[0]=INF; Mx[0]=0;
		Ny[0]=INF; My[0]=0;
	}
	IL void updata(int x)
	{
		pv[x]=MIN(MIN(pv[ls[x]],pv[rs[x]]),v[x]);
		Mx[x]=MAX(p[x].x,MAX(Mx[ls[x]],Mx[rs[x]]));
		Nx[x]=MIN(p[x].x,MIN(Nx[ls[x]],Nx[rs[x]]));
		My[x]=MAX(p[x].y,MAX(My[ls[x]],My[rs[x]]));
		Ny[x]=MIN(p[x].y,MIN(Ny[ls[x]],Ny[rs[x]]));
	}
	int build(int h,int t,int o)
	{
		int x,mid; x=mid=(h+t)/2;
		cmp_d=o; nth_element(p+h,p+mid,p+t+1,cmp);
		v[x]=p[x].z;
		if (h<mid) ls[x]=build(h,mid-1,o^1);
		if (mid<t) rs[x]=build(mid+1,t,o^1);
		updata(x);
		return x;
    }
    int query(int x,int x1,int x2,int y1,int y2)
    {
    	if (x1>Mx[x]||x2<Nx[x]||y1>My[x]||y2<Ny[x]) return(INF);
    	if (x1<=Nx[x]&&Mx[x]<=x2&&y1<=Ny[x]&&My[x]<=y2) return(pv[x]);
    	int ans=INF;
    	if (p[x].x>=x1&&p[x].x<=x2&&p[x].y>=y1&&p[x].y<=y2) ans=v[x];
    	mina(ans,query(ls[x],x1,x2,y1,y2));
    	mina(ans,query(rs[x],x1,x2,y1,y2));
    	return ans;
    }
}K;
int main()
{
	int n,m;
	read(n); read(m);
	rep(i,1,n)
	{ 
	  read(a[i]);
	  int k=M[a[i]];
	  if (k) p[++cnt]=(re){k,i,i-k};
	  M[a[i]]=i;
    }
    rt=K.build(1,cnt,0);
    rep(i,1,m)
    {
    	int x,y;
    	read(x); read(y);
    	int ans=K.query(rt,x,y,x,y);
    	if (ans<INF) wer(ans); else wer(-1);
    	wer2();
    }
    fwrite(sr,1,C+1,stdout);
	return 0;
}