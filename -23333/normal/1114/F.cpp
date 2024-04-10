#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define IL inline
#define ll long long
#define mid ((h+t)>>1)
const int mo=1e9+7;
IL int fsp(int x,int y)
{
  ll now=1;
  while (y)
  {
    if (y&1) now=now*x%mo;
    x=1ll*x*x%mo; y>>=1;
  }
  return now;
}
const int N=5e5;
bool t[500];
int ve[500],pos[500],rt[500],n,m,a[N],inv[500];
vector<int> ve1[500];
int now;
IL void fj(int x)
{
  int cnt=0;
  int y=x;
  for (int i=2;i<=300;i++)
  if (x%i==0)
  {
    cnt++;
    ve1[y].push_back(i);
    while (x%i==0) x/=i;
  }
  now=max(now,cnt);
}
struct sgt1{
  int v[N*4],lazy[N*4];
  sgt1() { rep(i,0,N*4-1) lazy[i]=1;}
  #define updata(x) v[x]=1ll*v[x*2]*v[x*2+1]%mo;
  IL void down(int x,int h,int t)
  {
    if (lazy[x]==1) return;
    lazy[x*2]=1ll*lazy[x*2]*lazy[x]%mo;
    lazy[x*2+1]=1ll*lazy[x*2+1]*lazy[x]%mo;
    v[x*2]=1ll*v[x*2]*fsp(lazy[x],mid-h+1)%mo;
    v[x*2+1]=1ll*v[x*2+1]*fsp(lazy[x],t-mid)%mo;
    lazy[x]=1;
  }
  void build(int x,int h,int t)
  {
    if (h==t)  {v[x]=a[h]; return; }
    build(x*2,h,mid); build(x*2+1,mid+1,t);
    updata(x);
  }
  void change(int x,int h,int t,int h1,int t1,int k)
  {
    if (h1<=h&&t<=t1)
    {
      lazy[x]=1ll*lazy[x]*k%mo; v[x]=1ll*v[x]*fsp(k,t-h+1)%mo; return; 
    }
    down(x,h,t);
    if (h1<=mid) change(x*2,h,mid,h1,t1,k);
    if (mid<t1) change(x*2+1,mid+1,t,h1,t1,k);
    updata(x); 
  }
  int query(int x,int h,int t,int h1,int t1)
  {
    if (h1<=h&&t<=t1) return v[x];
    down(x,h,t);
    ll ans=1;
    if (h1<=mid) ans=query(x*2,h,mid,h1,t1);
    if (mid<t1) ans=ans*query(x*2+1,mid+1,t,h1,t1)%mo;
    return ans; 
  }
}S;
struct sgt2{
  ll v[N*4],lazy[N*4];
  IL void down(int x)
  {
    if (!lazy[x]) return;
    v[x*2]|=lazy[x]; lazy[x*2]|=lazy[x];
    v[x*2+1]|=lazy[x]; lazy[x*2+1]|=lazy[x];
    lazy[x]=0;
  }
  void change(int x,int h,int t,int h1,int t1,ll k)
  {
    if (h1<=h&&t<=t1)
    {
       v[x]|=k; lazy[x]|=k; return; 
    }
    down(x); 
    if (h1<=mid) change(x*2,h,mid,h1,t1,k);
    if (mid<t1) change(x*2+1,mid+1,t,h1,t1,k);
    v[x]=v[x*2]|v[x*2+1];
  }
  ll query(int x,int h,int t,int h1,int t1)
  {
    if (h1<=h&&t<=t1) return v[x];
    down(x);
    ll now=0;
    if (h1<=mid) now=query(x*2,h,mid,h1,t1);
    if (mid<t1) now|=query(x*2+1,mid+1,t,h1,t1);
    return now;  
  }
}S2;
int main()
{
  int nm=300;
  int cnt=0;
  for (int i=2;i<=nm;i++)
    if (!t[i])
    {
      for (int j=2;j*i<=nm;j++)
        t[i*j]=1;
      ve[++cnt]=i;
      pos[i]=cnt;
    }
  rep(i,1,nm)
  {
    fj(i);
  }
  rep(i,1,nm) inv[i]=fsp(i,mo-2);
  ios::sync_with_stdio(false);
  cin>>n>>m;
  rep(i,1,n) cin>>a[i];
  rep(i,1,n)
  {
    int len=ve1[a[i]].size();
    ll now=0;
    rep(j,0,len-1)
    {
      int k=pos[ve1[a[i]][j]];
      now|=1ll<<(k-1);
    }
    S2.change(1,1,n,i,i,now);
  }
  S.build(1,1,n);
  char cc[20];
  int cnt3=0;
  rep(i,1,m)
  {
    cin>>cc;
    int x,y,z;
    if (cc[0]=='T')
    {
      cin>>x>>y;
      ll ans=S.query(1,1,n,x,y);
      ll k=S2.query(1,1,n,x,y);
      rep(i,1,cnt)
      {
        if ((k>>(i-1))&1) ans=ans*inv[ve[i]]%mo*(ve[i]-1)%mo;
      }
      cout<<ans<<endl;
    } else
    {
      cin>>x>>y>>z;
      int len=ve1[z].size();
      ll now=0;
      rep(j,0,len-1)
      {
        int k=pos[ve1[z][j]];
        now|=1ll<<(k-1);
      }
      S2.change(1,1,n,x,y,now);
      S.change(1,1,n,x,y,z);
    }
  }
  cerr<<cnt3<<endl;
  return 0;
}