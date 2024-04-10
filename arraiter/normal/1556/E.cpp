#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=1e5+10;

int n,q,A[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

struct node{
  ll lef,rig,ans,sum,pre;
}T[maxn<<2];
node merge(const node&A,const node&B){
  return{max(A.lef,A.sum+B.lef),max(B.rig,B.sum+A.rig),max(A.rig+B.lef,max(A.ans,B.ans)),A.sum+B.sum,min(A.pre,A.sum+B.pre)};
}
void build(int k,int l,int r){
  if(l==r){
    ll x=max(0,A[l]);
    T[k]={x,x,x,A[l],min(A[l],0)};
  }else build(lson),build(rson),T[k]=merge(T[k<<1],T[k<<1|1]);
}
node query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return T[k];
  if(qr<=mid)return query(lson,ql,qr);
  if(ql>mid)return query(rson,ql,qr);
  return merge(query(lson,ql,qr),query(rson,ql,qr));
}

#undef mid
#undef lson
#undef rson

int main(){
  cin>>n>>q;
  rep(i,1,n)scanf("%d",A+i);
  rep(i,1,n){
    int x;scanf("%d",&x),A[i]=x-A[i];
  }
  build(1,1,n);
  while(q--){
    int l,r;scanf("%d%d",&l,&r);
    node t=query(1,1,n,l,r);
    ll ans=t.lef,mnp=t.pre;
//    ll res=0,ans=0,su=0,mnp=0;
//    rep(i,l,r){
//      res=max(res,0ll)+A[i];
//      ans=max(ans,res);
//      mnp=min(mnp,su+=A[i]);
//    }
    if(mnp<0||t.sum!=0){
      puts("-1");
    }else{
      printf("%lld\n",ans);
    }
  }
  return 0;
}