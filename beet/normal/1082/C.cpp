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
  Int n,m;
  cin>>n>>m;
  vector<Int> s(n),r(n);
  for(Int i=0;i<n;i++) cin>>s[i]>>r[i];

  vector<vector<Int> > L(m);
  for(Int i=0;i<n;i++) L[--s[i]].emplace_back(r[i]);
  
  vector<vector<Int> > S(m);
  for(Int i=0;i<m;i++){
    sort(L[i].rbegin(),L[i].rend());
    
    S[i].assign(L[i].size()+1,0);
    for(Int j=0;j<(Int)L[i].size();j++)
      S[i][j+1]=S[i][j]+L[i][j];
  }
  
  queue<Int> q;
  for(Int i=0;i<m;i++)
    if(!L[i].empty()) q.emplace(i);

  Int ans=0;
  for(Int i=1;i<=n;i++){
    Int res=0;
    queue<Int> nq;
    while(!q.empty()){
      Int x=q.front();q.pop();
      res+=max(0LL,S[x][i]);
      if(i+1<=(Int)L[x].size()) nq.emplace(x);      
    }
    swap(q,nq);
    chmax(ans,res);
  }
  
  cout<<ans<<endl;
  return 0;
}