#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
typedef pair<int,int>pii;
const int maxn=4e5+10;
int n,m,q;ll ans,res[maxn];

pii dat[maxn],bet[maxn];
ll A[maxn],pre[maxn];

struct Querys{
  int k,tid;
}Q[maxn];

int par[maxn],sz[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

int main(){
  ios::sync_with_stdio(0);
  cin>>n>>m>>q;
  rep(i,1,n){
    cin>>dat[i].first,dat[i].second=1;
    ans+=dat[i].first;
  }
  rep(i,1,m){
    cin>>dat[n+i].first,dat[n+i].second=0;
  }
  sort(dat+1,dat+n+m+1);
  rep(i,1,q){
    cin>>Q[i].k,Q[i].tid=i;
  }
  sort(Q+1,Q+q+1,[](Querys P,Querys Q){
    return P.k<Q.k;
  });
  rep(i,1,n+m)A[i]=dat[i].first,pre[i]=pre[i-1]+A[i],par[i]=i,sz[i]=dat[i].second;
  rep(i,2,n+m)bet[i-1]={A[i]-A[i-1],i-1};
  sort(bet+1,bet+n+m);
  for(int i=1,j=1;i<=q;i++){
    for(;j<n+m&&bet[j].first<=Q[i].k;j++){
      int pos=bet[j].second;
      int nxt=find(pos+1);
      ans-=pre[pos]-pre[pos-sz[pos]];
      ans-=pre[nxt]-pre[nxt-sz[nxt]];
      par[pos]=nxt,sz[nxt]+=sz[pos];
      ans+=pre[nxt]-pre[nxt-sz[nxt]];
    }
    res[Q[i].tid]=ans;
  }
  rep(i,1,q)cout<<res[i]<<endl;
  return 0;
}