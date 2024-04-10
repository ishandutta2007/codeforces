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
  string s;
  cin>>s;
  Int n=s.size();
  vector<Int> nx(n,-1);

  Int ans=0;
  set<Int> R,L,A,B;

  set<int> R1,R2,L1,L2;
  auto build=
    [&](){
      for(Int i=0;i<n;i++){
        if(s[i]=='R'){
          if(!L2.empty()){
            Int v=*L2.begin();L2.erase(v);
            nx[v]=i;
            R1.emplace(i);
          }else if(!L1.empty()){
            Int v=*L1.begin();L1.erase(v);
            nx[v]=i;
            R2.emplace(i);
          }else{
            A.emplace(i);
            R1.emplace(i);
          }
        }
        if(s[i]=='L'){
          if(!R2.empty()){
            Int v=*R2.begin();R2.erase(v);
            nx[v]=i;
            L1.emplace(i);
          }else if(!R1.empty()){
            Int v=*R1.begin();R1.erase(v);
            nx[v]=i;
            L2.emplace(i);
          }else{
            B.emplace(i);
            L1.emplace(i);
          }
        }
        chmax(ans,(Int)R1.size()+(Int)R2.size()+(Int)L1.size()+(Int)L2.size());
      }
    };
  build();
  for(int r:R1) R.emplace(r);
  for(int r:R2) R.emplace(r);
  for(int l:L1) L.emplace(l);
  for(int l:L2) L.emplace(l);

  const int DEBUG = 0;
  vector<Int> fr(n,-1),bk(n,-1);
  for(Int a:A){
    Int p=a;
    if(DEBUG){
      cout<<a<<":"<<s[a];
      while(~nx[p]) p=nx[p],cout<<s[p];
      cout<<":"<<p<<endl;
    }
    p=a;
    while(~nx[p]) p=nx[p];
    fr[p]=a;
    bk[a]=p;
  }
  for(Int b:B){
    Int p=b;
    if(DEBUG){
      cout<<b<<":"<<s[b];
      while(~nx[p]) p=nx[p],cout<<s[p];
      cout<<":"<<p<<endl;
    }
    p=b;
    while(~nx[p]) p=nx[p];
    fr[p]=b;
    bk[b]=p;
  }

  set<int> A1,A2,B1,B2;
  for(int r:R1) A1.emplace(fr[r]);
  for(int l:L2) A2.emplace(fr[l]);

  for(int l:L1) B1.emplace(fr[l]);
  for(int r:R2) B2.emplace(fr[r]);

  for(Int a:A){
    assert(~bk[a]);
    assert(fr[bk[a]]==a);
  }
  for(Int b:B){
    assert(~bk[b]);
    assert(fr[bk[b]]==b);
  }
  for(Int r:R){
    assert(~fr[r]);
    assert(bk[fr[r]]==r);
  }
  for(Int l:L){
    assert(~fr[l]);
    assert(bk[fr[l]]==l);
  }

  Int st=0,en=bk[0];
  while(1){
    if(DEBUG) cout<<st<<" "<<en<<endl;
    if(A1.count(st)) A1.erase(st);
    if(B1.count(st)) B1.erase(st);
    if(R1.count(en)) R1.erase(en);
    if(L1.count(en)) L1.erase(en);

    if(A2.count(st)) A2.erase(st);
    if(B2.count(st)) B2.erase(st);
    if(R2.count(en)) R2.erase(en);
    if(L2.count(en)) L2.erase(en);

    if(s[st]=='R'&&!L2.empty()){
      Int v=*L2.begin();L2.erase(v);
      nx[v]=st;
      st=fr[v];
      continue;
    }
    if(s[st]=='L'&&!R2.empty()){
      Int v=*R2.begin();R2.erase(v);
      nx[v]=st;
      st=fr[v];
      continue;
    }
    if(s[en]=='R'&&!B2.empty()){
      Int v=*B2.begin();B2.erase(v);
      nx[en]=v;
      en=bk[v];
      continue;
    }
    if(s[en]=='L'&&!A2.empty()){
      Int v=*A2.begin();A2.erase(v);
      nx[en]=v;
      en=bk[v];
      continue;
    }
    if(DEBUG) cout<<"UKU"<<endl;
    if(s[st]=='R'&&!L1.empty()){
      Int v=*L1.begin();L1.erase(v);
      nx[v]=st;
      st=fr[v];
      continue;
    }
    if(s[st]=='L'&&!R1.empty()){
      Int v=*R1.begin();R1.erase(v);
      nx[v]=st;
      st=fr[v];
      continue;
    }
    if(s[en]=='R'&&!B1.empty()){
      Int v=*B1.begin();B1.erase(v);
      nx[en]=v;
      en=bk[v];
      continue;
    }
    if(s[en]=='L'&&!A1.empty()){
      Int v=*A1.begin();A1.erase(v);
      nx[en]=v;
      en=bk[v];
      continue;
    }
    break;
  }
  if(DEBUG) return 0;

  cout<<ans-1<<endl;
  Int pos=st;
  Int len=0;
  while(~pos){
    len++;
    if(pos!=st) cout<<" ";
    cout<<pos+1;
    pos=nx[pos];
  }
  cout<<endl;
  assert(len==n);
  return 0;
}