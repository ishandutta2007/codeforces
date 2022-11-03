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
  const int MAX = 7070;
  using BS = bitset<MAX>;

  vector<BS> ds(MAX,0),vs(MAX,0);
  vector<int> ok(MAX,1);
  for(int i=2;i*i<MAX;i++)
    for(int j=i*i;j<MAX;j+=i*i)
      ok[j]=0;
  
  for(int i=1;i<MAX;i++){
    for(int j=i;j<MAX;j+=i){
      ds[j].set(i);
      if(ok[j/i]) vs[i].set(j);
    }
  }
  
  int n,q;
  cin>>n>>q;
  vector<BS> ms(n,0);
  
  string ans;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      int x,v;
      cin>>x>>v;
      x--;
      ms[x]=ds[v];
      continue;
    }
    if(t==2){
      int x,y,z;
      cin>>x>>y>>z;      
      x--;y--;z--;
      ms[x]=ms[y]^ms[z];
      continue;
    }    
    if(t==3){
      int x,y,z;
      cin>>x>>y>>z;      
      x--;y--;z--;
      ms[x]=ms[y]&ms[z];
      continue;
    }
    if(t==4){
      int x,v;
      cin>>x>>v;
      x--;
      ans.push_back(char('0'+((ms[x]&vs[v]).count()&1)));
      continue;
    }
  }
  cout<<ans<<endl;
  return 0;
}