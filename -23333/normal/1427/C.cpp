#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define IL inline
#define rint register int
#define ll long long 
#define mid ((h+t)/2) 
const ll INF=1e18;
const ll N=2e5+10;
int n,r,id[N],cmp_d,ans;
int x,y,dy[N];
void umax(int &x,int y)
{ 
  if (x<y) x=y;
}
void umin(int &x,int y)
{
  if (x>y) x=y; 
}
struct re
{
  int d[3],f;
};
bool cmp(re x,re y)
{
  return(x.d[cmp_d]<y.d[cmp_d]);
}
re p[N],p1[N];
struct kd
{
   int ls[N],rs[N],Mx[N],My[N],Mz[N],Nx[N],Ny[N],Nz[N],v[N],vv[N],fa[N];
  void updata(int x)
  {
    if (ls[x])
    {
      umax(Mx[x],Mx[ls[x]]);
      umax(My[x],My[ls[x]]);
      umax(Mz[x],Mz[ls[x]]);
      umin(Nx[x],Nx[ls[x]]);
      umin(Ny[x],Ny[ls[x]]);
      umin(Nz[x],Nz[ls[x]]);
      umax(v[x],v[ls[x]]);
    }
    if (rs[x])
    {
      umax(Mx[x],Mx[rs[x]]);
      umax(My[x],My[rs[x]]);
      umax(Mz[x],Mz[rs[x]]);
      umin(Nx[x],Nx[rs[x]]);
      umin(Ny[x],Ny[rs[x]]);
      umin(Nz[x],Nz[rs[x]]);
      umax(v[x],v[rs[x]]);
    }
  }
  int build(int h,int t,int o,int f1)
  {
    cmp_d=o; nth_element(p+h,p+mid,p+t+1,cmp);
    int x=mid;
    fa[x]=f1;
    Mx[x]=Nx[x]=p[x].d[0];
    My[x]=Ny[x]=p[x].d[1];
    Mz[x]=Nz[x]=p[x].d[2];
    v[x]=-1e9; vv[x]=-1e9;
    if (h!=x)
	{ 
	  ls[x]=build(h,mid-1,(o+1)%3,x);
    }
    if (t!=x) 
    {
	  rs[x]=build(mid+1,t,(o+1)%3,x);
    }
    updata(x);
    return x;
  }
  void insert(re x,int kk)
  {
  	int now=dy[x.f];
  	umax(v[now],kk); umax(vv[now],kk);
  	while (fa[now])
  	{
  		now=fa[now];
  		umax(v[now],kk);
  	}
  }
  int query(int k,int x1,int y1,int z1)
  {
    if (!k||Nx[k]>x1||Ny[k]>y1||Nz[k]>z1) return -1e9;
    if (x1>=Mx[k]&&y1>=My[k]&&z1>=Mz[k])
    {
      return v[k];
    }
    int ans=-1e9;
    if (x1>=p[k].d[0]&&y1>=p[k].d[1]&&z1>=p[k].d[2]) ans=vv[k];
    ans=max(ans,query(ls[k],x1,y1,z1)); 
	ans=max(ans,query(rs[k],x1,y1,z1));
	return ans;
  }
}K;
struct ree{
	int a,b,c,d; 
} a[N]; 
bool cmpt(ree x,ree y)
{
	 return (x.d<y.d)||(x.d==y.d&&x.a<y.a);
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>r>>n;
  rep(i,1,n)
  {
  	cin>>a[i].a>>a[i].b>>a[i].c; a[i].d=a[i].a-a[i].b-a[i].c;
  }
  a[++n]=(ree){0,1,1,-2};
  sort(a+1,a+n+1,cmpt);
  rep(i,1,n)
  {
  	p[i].f=i; p[i].d[0]=a[i].a+a[i].b-a[i].c; 
	p[i].d[1]=a[i].a+a[i].b+a[i].c;
	p[i].d[2]=a[i].a-a[i].b+a[i].c;
  }
  memcpy(p1,p,sizeof(p));
 int rt=K.build(1,n,0,0),ans2=0;
  rep(i,1,n) dy[p[i].f]=i;
  rep(i,1,n)
  {
    if (a[i].a==0) K.insert(p1[i],0);
    else
    {
    	int ans=K.query(rt,p1[i].d[0],p1[i].d[1],p1[i].d[2])+1;
    	ans2=max(ans2,ans);
    	K.insert(p1[i],ans);
    }
  }
  cout<<ans2<<endl;
  return 0; 
}