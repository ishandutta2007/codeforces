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
  Int n,m,k;
  cin>>n>>m>>k;
  vector<Int> ps(m);
  for(Int i=0;i<m;i++) cin>>ps[i],ps[i]--;

  Int cnt=0,num=0,pre=-1;
  for(Int i=0;i<m;i++){
    Int len=ps[i]-pre-1;
    num+=len;
    num%=k;
    pre=ps[i]-1;
    Int j=i;
    while(j<m&&num+(ps[j]-pre)<=k) j++;
    //cout<<i<<" "<<j<<endl;

    num+=(ps[j-1]-pre)-(j-i);
    num%=k;

    pre=ps[j-1];

    i=j-1;
    cnt++;
    //cout<<":"<<num<<" "<<pre<<endl;
  }

  cout<<cnt<<endl;
  return 0;
}