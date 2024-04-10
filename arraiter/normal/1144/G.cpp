#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef pair<int,int> pii;
const int maxn=2e5+10;
int n,A[maxn],ans[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

pii val1[maxn<<2],val2[maxn<<2];int mx[maxn<<2],mn[maxn<<2];
void build(int k,int l,int r){
  if(l==r){
    static int lst,x;scanf("%d",&x),val1[k]={x,l},val2[k]={x,-l},mx[k]=mn[k]=x-lst,A[l]=lst=x;return;
  }
  build(lson),build(rson),val1[k]=max(val1[k<<1],val1[k<<1|1]),val2[k]=max(val2[k<<1],val2[k<<1|1]),mx[k]=max(mx[k<<1],mx[k<<1|1]),mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
pii query1(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return val1[k];pii res(-1,0);
  if(ql<=mid)res=query1(lson,ql,qr);
  if(qr>mid)res=max(res,query1(rson,ql,qr));
  return res;
}
pii query2(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return val2[k];pii res(-1,0);
  if(ql<=mid)res=query2(lson,ql,qr);
  if(qr>mid)res=max(res,query2(rson,ql,qr));
  return res;
}
int query_mx(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return mx[k];int res=-1e9;
  if(ql<=mid)res=query_mx(lson,ql,qr);
  if(qr>mid)res=max(res,query_mx(rson,ql,qr));
  return res;
}
int query_mn(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return mn[k];int res=1e9;
  if(ql<=mid)res=query_mn(lson,ql,qr);
  if(qr>mid)res=min(res,query_mn(rson,ql,qr));
  return res;
}

#undef mid
#undef lson
#undef rson

bool divide(int l,int r,int L0,int L1,int R0,int R1){
//  printf("(%d %d) (%d %d %d %d)\n",l,r,L0,L1,R0,R1);
  if(l>r)return L0<R0&&L1>R1;
  pii pr0=query1(1,1,n,l,r),pr1=query2(1,1,n,l,r);
  if(pr0.first>L0&&pr0.first<R0){
    int pos=pr0.second;
    if((pos+1>=r||query_mx(1,1,n,pos+2,r)<0)&&(pos==r||A[r]>R1)&&(pos==r||L1>A[pos+1])&&divide(l,pos-1,L0,L1,pr0.first,pos==r?R1:A[pos+1])){
      ans[pos]=0;rep(i,pos+1,r)ans[i]=1;return 1;
    }
  }
  if(pr1.first<L1&&pr1.first>R1){
    int pos=-pr1.second;
    if((pos<=l+1||query_mn(1,1,n,l+1,pos-1)>0)&&(pos==l||A[l]>L0)&&(pos==l||A[pos-1]<R0)&&divide(pos+1,r,pos==l?L0:A[pos-1],pr1.first,R0,R1)){
      ans[pos]=1;rep(i,l,pos-1)ans[i]=0;return 1;
    }
  }
  return 0;
}

int main(){
  cin>>n,build(1,1,n);
  if(divide(1,n,-1e9,1e9,1e9,-1e9)){
    puts("YES");rep(i,1,n)printf("%d ",ans[i]);
  }else{
    puts("NO");
  }
  return 0;
}