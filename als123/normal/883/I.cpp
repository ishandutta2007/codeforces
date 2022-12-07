#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1600010;
LL t[N]; LL f[N];  LL n,kk;

LL lc[N],rc[N],C[N],rt,tot;
void Link(LL &u,LL L,LL R,LL k,LL c)
{
  if(!u) u=++tot;
  if(L==R){C[u] = c; return ;}
  LL mid=(L+R)>>1;
  if(k<=mid) Link(lc[u],L,mid,k,c);
  else Link(rc[u],mid+1,R,k,c);
  C[u] = min(C[lc[u]] , C[rc[u]]);
}

LL Query(LL u,LL L,LL R,LL l,LL r)
{
  if(l>r) return 2e9;
  if(L==l && R==r) return C[u];
  LL mid=(L+R)>>1;
  if(r<=mid) return Query(lc[u],L,mid,l,r);
  else if(l>mid) return Query(rc[u],mid+1,R,l,r);
  else return min(Query(lc[u],L,mid,l,mid),Query(rc[u],mid+1,R,mid+1,r));
}

bool check(LL val,LL x)
{
  LL L=0; LL R=x-kk; LL mid,ret=1e9;
  while(L<=R)
  {
    mid=(L+R)>>1;
    if(t[x] - t[mid+1] <= val) R=mid-1,ret=mid;
    else if(t[x] - t[mid+1] > val) L=mid+1; 
  }
  if(Query(rt,0,n,ret,x-kk) <= val) return 1;
  else return 0;
}

int main()
{
  scanf("%lld%lld",&n,&kk);
  for(LL i=1;i<=n;i++) scanf("%lld",&t[i]);
  sort(t+1,t+n+1);
  rt=tot=0; for(LL i=0;i<=n;i++) Link(rt,0,n,i,1e9); Link(rt,0,n,0,0);
  for(LL i=kk;i<=n;i++)
  {
    LL L=0; LL R=1e9; LL ret=0;
    check(10,i);
    while(L<=R)
    {
      LL mid=(L+R)>>1;
      if(check(mid,i)) R=mid-1,ret=mid;
      else L=mid+1;
    }
    // printf("%lld\n",ret);
    f[i] = ret; Link(rt,0,n,i,ret);
  }
  // for(LL i=1;i<n;i++) prLLf("%lld ",f[i]);
  return printf("%lld\n",f[n]),0;
}