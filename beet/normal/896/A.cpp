#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  string base="What are you doing at the end of the world? Are you busy? Will you save us?";
  string a="What are you doing while sending \"";
  string b="\"? Are you busy? Will you send \"";
  string c="\"?";
  Int q;
  cin>>q;
  const Int MAX = 114514;
  vector<Int> len(MAX+1,0);
  len[0]=base.size();
  const Int lim = 1.1e18;
  for(Int i=0;i<MAX;i++){
    if(len[i]>=lim) len[i+1]=lim;
    else len[i+1]=a.size()+len[i]+b.size()+len[i]+c.size();
  }
  bool flg=0;
  function<void(Int, Int&)> dfs=[&](Int n,Int& k){
    if(!n){
      if(k<(Int)base.size()){
	cout<<base[k];
	flg=1;
	return;
      }
      k-=base.size();
      return;
    }
    if(k<(Int)a.size()){
      cout<<a[k];
      flg=1;
      return;
    }
    k-=a.size();
    
    if(k>=len[n-1]) k-=len[n-1];
    else dfs(n-1,k);
    
    if(flg) return;
    if(k<(Int)b.size()){
      cout<<b[k];
      flg=1;
      return;
    }
    k-=b.size();
    
    if(k>=len[n-1]) k-=len[n-1];
    else dfs(n-1,k);
    
    if(flg) return;
    if(k<(Int)c.size()){
      cout<<c[k];
      flg=1;
      return;
    }
    k-=c.size();
  };
  
  while(q--){
    Int n,k;
    cin>>n>>k;
    k--;
    if(k>=len[n]){
      cout<<".";
      continue;
    }
    flg=0;
    dfs(n,k);
    assert(flg);
  }
  cout<<endl;
  return 0;
}