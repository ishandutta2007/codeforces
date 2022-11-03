#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> ds(n);
  for(Int i=0;i<n;i++) cin>>ds[i];

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int i=0;i<n;i++)
    vp.emplace_back(ds[i],i);

  sort(vp.rbegin(),vp.rend());

  vector< vector<Int> > G(n*2+1);
  vector<P> latte;

  auto add_edge=
    [&](Int a,Int b){
      G[a].emplace_back(b);
      G[b].emplace_back(a);
    };

  auto add_edge_later=
    [&](Int a,Int b){
      latte.emplace_back(a,b);
    };

  vector<Int> used(n*2,-1);
  int pos=0,tail=-1;
  for(auto p:vp){
    Int d=p.first,i=p.second;
    Int x=i*2+1,y=i*2+2;
    //cout<<x<<" "<<y<<endl;

    if(pos==0){
      used[pos]=x;
      used[d]=y;
      pos++;
      tail=d;
      continue;
    }

    if(~used[pos]){
      add_edge(x,used[0]);
      if(d==1) add_edge(x,y);
      else add_edge(used[d-2],y);
      continue;
    }

    used[pos]=x;
    if(pos+d==tail+1){
      used[pos+d]=y;
      tail++;
    }else{
      add_edge_later(pos+d-1,y);
    }
    pos++;
  }

  for(auto p:latte)
    add_edge(used[p.first],p.second);

  for(Int i=0;i+1<n*2;i++){
    if(used[i+1]<0) break;
    Int u=used[i],v=used[i+1];
    add_edge(u,v);
  }

  for(Int v=1;v<=n*2;v++){
    for(Int u:G[v]){
      if(u>v) continue;
      cout<<u<<" "<<v<<"\n";
    }
  }
  cout<<flush;
  return 0;
}