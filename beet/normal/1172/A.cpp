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
  int n;
  cin>>n;
  deque<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>bs[i];

  int flg=count(as.begin(),as.end(),1);
  if(!flg){
    deque<int> cs(as),ds(bs);
    int idx=0;
    for(int i=0;i<n;i++)
      if(bs[i]==1) idx=i;
    int cont=1;
    for(int i=0;idx+i<n;i++)          
      cont&=bs[idx+i]==i+1;

    if(cont){
      set<int> ss(as.begin(),as.end());
      int res=0;
      while(ss.count(bs.back()+1)){
        res++;
        int nxt=bs.back()+1;
        ss.erase(nxt);
        bs.emplace_back(nxt);
        ss.emplace(bs.front());
        bs.pop_front();        
      }      
      if(bs.back()==n){
        for(int i=0;i<n;i++) assert(bs[i]==i+1);        
        cout<<res<<endl;
        return 0;
      }
    }
    as=cs;
    bs=ds;
  }
  vector<int> num(n+1,0);
  for(int i=0;i<n;i++) num[as[i]]=0;
  for(int i=0;i<n;i++) num[bs[i]]=i+1;
  int res=0;
  for(int i=1;i<=n;i++) chmax(res,num[i]-(i-1));
  cout<<res+n<<endl;  
  return 0;
}