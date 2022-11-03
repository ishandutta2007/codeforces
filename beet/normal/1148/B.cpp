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
  Int n,m,ta,tb,k;
  cin>>n>>m>>ta>>tb>>k;
  vector<Int> as(n),bs(m);
  for(Int i=0;i<n;i++) cin>>as[i];
  for(Int i=0;i<m;i++) cin>>bs[i];

  auto check=
    [&](Int x)->Int{
      Int pos=0;
      vector<Int> sm(m+1,0);
      for(Int i=0;i<n;i++){
        while(pos<m&&as[i]+ta>bs[pos]) pos++;
        if(pos>=x) break;
        sm[pos+1]++;
      }
      for(Int i=0;i<m;i++) sm[i+1]+=sm[i];

      Int num=n+m;
      for(Int i=0;i<=x;i++)
        chmin(num,(x-i)+sm[i]);      
      return num<=k;
    };
  
  Int L=0,R=m+1;
  while(L+1<R){
    Int M=(L+R)>>1;
    if(check(M)) L=M;
    else R=M;
  }
  cout<<(L==m?-1:bs[L]+tb)<<endl;  
  return 0;
}