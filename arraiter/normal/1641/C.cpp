#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin,(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=2e5+10;

int n,q;

struct Querys{
  int op,l,r,x;
}Q[maxn];

#define mid ((l+r)>>1)
#define lson ls[k],l,mid
#define rson rs[k],mid+1,r

int tot,rt[maxn],ls[maxn*20],rs[maxn*20],sum[maxn*20];
void ins(int&k,int rt,int l,int r,int x){
  sum[k=++tot]=sum[rt]+1,ls[k]=ls[rt],rs[k]=rs[rt];
  if(l==r)return;
  x<=mid?ins(ls[k],ls[rt],l,mid,x):ins(rs[k],rs[rt],mid+1,r,x);
}
int query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return sum[k];
  int res=0;
  if(ql<=mid)res=query(lson,ql,qr);
  if(qr>mid)res+=query(rson,ql,qr);
  return res;
}
int ask(int k,int l,int r,int ql,int qr){
  if(sum[k]==r-l+1)return-1;
  if(l==r)return l;
  if(ql<=mid){
    int x=ask(lson,ql,qr);
    if(x!=-1)return x;
  }
  if(qr>mid){
    int x=ask(rson,ql,qr);
    if(x!=-1)return x;
  }
  return-1;
}

#undef mid

int par[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

int ans[maxn];

void solve(){
  cin>>n>>q;
  rep(i,1,q){
    int op=read();
    if(op==0){
      int l=read(),r=read(),x=read();
      Q[i]={op,l,r,x};
//      if(x)sum[i]=r-l+1,add(1,1,n,l,r,i);
    }else{
      Q[i]={op,0,0,read()};
    }
  }
  memset(ans,-1,sizeof ans);
  rep(i,1,n+1)par[i]=i;
  rep(_,1,q){
    rt[_]=rt[_-1];
    const auto e=Q[_];
    if(e.op==0){
      int l=e.l,r=e.r;
      if(e.x==0){
        for(int i=find(l);i<=r;i=par[i]=find(i+1)){
          ins(rt[_],rt[_],1,n,i);
//          printf("#%d %d\n",i,query(rt[_],1,n,i,i));
        }
//        rep(i,1,n)printf("%d%c",find(i),"\n "[i<n]);
      }else{

      }
    }else{
      if(find(e.x)!=e.x)ans[_]=0;
//      if(ans[e.x]==-1)puts("N/A");
//      else if(ans[e.x]==1)puts("Yes");
//      else puts("No");
    }
  }
  static int tim[maxn];
  rep(_,1,q){
    auto e=Q[_];
    if(e.op==0&&e.x==1){
      int l=0,r=q,ans=-1;
      while(l<=r){
        int mid=(l+r)/2;
//        printf("(%d) (%d %d) %d\n",mid,e.l,e.r,query(rt[mid],1,n,e.l,e.r));
        if(query(rt[mid],1,n,e.l,e.r)<e.r-e.l){
          l=mid+1;
        }else{
          ans=mid;
          r=mid-1;
        }
      }
      if(ans!=-1){
        int id=ask(rt[ans],1,n,e.l,e.r);
        if(!tim[id])tim[id]=max(_,ans);
        else chkmin(tim[id],max(_,ans));
//        cout<<_<<' '<<ans<<endl;
      }
    }
  }
  rep(_,1,q){
    auto e=Q[_];
    if(e.op==1){
      if(ans[_]==-1&&tim[e.x]&&tim[e.x]<_)ans[_]=1;
      if(ans[_]==-1)puts("N/A");
      else if(ans[_]==1)puts("YES");
      else puts("NO");
    }
  }

}

signed main(){
//  int T;cin>>T;
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}

/*
5 4
0 3 4 1
0 3 3 1
1 3
0 4 4 0

*/