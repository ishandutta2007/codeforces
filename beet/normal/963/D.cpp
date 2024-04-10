#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct SuffixArray{
  Int n,k;
  string S;
  vector<Int> sa,lcp;
  SuffixArray(){}
  SuffixArray(string& S):S(S){init();}
  void init(){
    n=S.length();
    S.push_back('$');
    build_sa();
  }
  void build_sa(){
    sa.clear();
    sa.resize(n+1,0);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),
	 [&](Int a,Int b){
	   if(S[a]==S[b]) return a>b;
	   return S[a]<S[b];
	 });
    vector<Int> c(n+1,0),r(n+1),cnt(n+1),s(n+1);
    for(Int i=0;i<=n;i++) r[i]=S[i];
    for(Int len=1;len<=n;len*=2){
      for(Int i=0;i<=n;i++){
	 c[sa[i]]=
	   i>0 &&
	   r[sa[i-1]]==r[sa[i]] &&
	   sa[i-1]+len<=n &&
	   r[sa[i-1]+len/2]==r[sa[i]+len/2] ?
	   c[sa[i-1]]:i;
      }
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),r.begin());
      for(Int i=0;i<=n;i++){
	Int s1=r[i]-len;
	if(s1>=0) sa[cnt[c[s1]]++]=s1;
      }
      c.swap(r);
    }
  }
  
  bool lt_substr(string &T,Int si=0,Int ti=0){
    Int sn=S.size(),tn=T.size();
    while(si<sn&&ti<tn){
      if(S[si]<T[ti]) return 1;
      if(S[si]>T[ti]) return 0;
      si++;ti++;
    }
    return si>=sn&&ti<tn;
  }
  
  Int lower_bound(string& T){
    Int low=0,high=n+1;
    while(low+1<high){
      Int mid=(low+high)/2;
      if(lt_substr(T,sa[mid],0)) low=mid;
      else high=mid;
    }
    return high;
  }
  
  Int upper_bound(string& T){
    T.back()++;
    Int res=lower_bound(T);
    T.back()--;
    return res;
  }
  
  // O(|T|*log|S|)
  Int count(string& T){
    return upper_bound(T)-lower_bound(T);
  }
};

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE

char buf[114514];
signed main(){
  string s;
  Int n;
  //cin>>s>>n;
  scanf("%s",buf);
  s=string(buf);
  scanf("%lld",&n);
  map<string, Int> idx;
  using P = pair<string, Int>;
  vector<P> v;
  for(Int i=0;i<n;i++){
    Int k;
    string m;
    //cin>>k>>m;
    scanf("%lld %s",&k,buf);
    m=string(buf);
    
    v.emplace_back(m,k);
    idx[m]=i;
  }

  sort(v.rbegin(),v.rend());
  
  SuffixArray sa(s);
  vector<Int> ord=sa.sa;

  const Int INF = 1e8;
  vector<Int> ans(n,INF);
  
  for(Int i=0;i<n;i++){
    Int k=v[i].second,len=v[i].first.size();
    Int x=sa.lower_bound(v[i].first);
    Int y=sa.upper_bound(v[i].first);

    sort(ord.begin()+x,ord.begin()+y);

    Int &res=ans[idx[v[i].first]];
    for(Int j=x;j+k-1<y;j++)
      chmin(res,ord[j+k-1]-ord[j]+len);
    if(res==INF) res=-1;
  }
  
  for(Int x:ans) printf("%lld\n",x);
  return 0;
}