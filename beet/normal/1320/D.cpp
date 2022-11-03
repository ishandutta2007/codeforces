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


struct SuffixArray{
  string s;
  vector<int> sa,rev;

  SuffixArray(){}
  SuffixArray(const string &S):s(S){
    int n=s.size();
    s.push_back('$');
    sa.resize(n+1);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),
         [&](int a,int b){
           if(s[a]==s[b]) return a>b;
           return s[a]<s[b];
         });
    vector<int> cs(n+1,0),rs(n+1),cnt(n+1);
    for(int i=0;i<=n;i++) rs[i]=s[i];
    for(int len=1;len<=n;len*=2){
      for(int i=0;i<=n;i++){
        cs[sa[i]]=i;
        if(i>0 &&
           rs[sa[i-1]]==rs[sa[i]] &&
           sa[i-1]+len<=n &&
           rs[sa[i-1]+len/2]==rs[sa[i]+len/2]) cs[sa[i]]=cs[sa[i-1]];
      }
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),rs.begin());
      for(int i=0;i<=n;i++){
        int s1=rs[i]-len;
        if(s1>=0) sa[cnt[cs[s1]]++]=s1;
      }
      cs.swap(rs);
    }
    rev.resize(n+1);
    for(int i=0;i<=n;i++) rev[sa[i]]=i;
  }
  int operator[](int i) const{return sa[i];}

  bool lt_substr(string &t,int si,int ti){
    int sn=s.size(),tn=t.size();
    while(si<sn&&ti<tn){
      if(s[si]<t[ti]) return 1;
      if(s[si]>t[ti]) return 0;
      si++;ti++;
    }
    return si==sn&&ti<tn;
  }

  int lower_bound(string& t){
    int l=0,r=s.size();
    while(l+1<r){
      int m=(l+r)>>1;
      if(lt_substr(t,sa[m],0)) l=m;
      else r=m;
    }
    return r;
  }

  int upper_bound(string& t){
    t.back()++;
    int res=lower_bound(t);
    t.back()--;
    return res;
  }

  // O(|T|*log|S|)
  int count(string& T){
    return upper_bound(T)-lower_bound(T);
  }
};


struct LongestCommonPrefix{
  SuffixArray sa;

  vector<int> ht;
  vector< vector<int> > dat;
  LongestCommonPrefix(string &s):sa(s){
    int n=s.size();
    vector<int> lcp(n,0);

    int t=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
      int j=sa[sa.rev[i]-1];
      if(t>0) t--;
      for(;j+t<n&&i+t<n;t++){
        if(sa.s[j+t]!=sa.s[i+t]) break;
      }
      lcp[sa.rev[i]-1]=t;
    }

    int h=1;
    while((1<<h)<n) h++;
    dat.assign(h,vector<int>(n));
    ht.assign(n+1,0);
    for(int j=2;j<=n;j++) ht[j]=ht[j>>1]+1;

    for(int j=0;j<n;j++) dat[0][j]=lcp[j];
    for(int i=1,p=1;i<h;i++,p<<=1)
      for(int j=0;j<n;j++)
        dat[i][j]=min(dat[i-1][j],dat[i-1][min(j+p,n-1)]);
  }

  // a, b are indices for suffix array
  int query(int a,int b){
    assert(a!=b);
    if(a>b) swap(a,b);
    int l=b-a;
    return min(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }

  // a, b are indices for string
  int lcp(int a,int b){
    return query(sa.rev[a],sa.rev[b]);
  }
};

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  string s;
  cin>>s;

  vector<int> cs(n+1,0);
  for(int i=n-1;i>=0;i--)
    if(s[i]=='1') cs[i]=cs[i+1]+1;

  vector<int> zs;
  for(int i=0;i<n;i++)
    if(s[i]=='0') zs.emplace_back(i);
  zs.emplace_back(n);

  vector<int> sm(n+1,0);
  for(int i=0;i<n;i++)
    sm[i+1]=sm[i]+(s[i]=='1');

  vector<int> idx(n,-1);
  string t;
  for(int i=0;i<n;i++){
    if(s[i]=='0'){
      idx[i]=t.size();
      t+=s[i];
    }else{
      if(t.back()=='1'){
        t.pop_back();
      }else{
        t+=s[i];
      }
    }
  }
  // cout<<t<<endl;

  LongestCommonPrefix lcp(t);
  auto solve=
    [&](int x,int y,int l)->int{
      {
        int c=sm[x+l]-sm[x];
        int d=sm[y+l]-sm[y];
        // number of 1 differ
        if(c!=d) return 0;
        // all 1
        if(c==l) return 1;
      }
      {
        int c=min(cs[x],l);
        int d=min(cs[y],l);
        // begin differ
        if((c&1)!=(d&1)) return 0;
      }

      // 0s at the end
      int a=*--lower_bound(zs.begin(),zs.end(),x+l);
      int b=*--lower_bound(zs.begin(),zs.end(),y+l);
      assert(s[a]=='0');
      assert(s[b]=='0');
      assert(x<=a && a<x+l);
      assert(y<=b && b<y+l);

      {
        int c=min(cs[a+1],(x+l)-(a+1));
        int d=min(cs[b+1],(y+l)-(b+1));
        // end differ
        if((c&1)!=(d&1)) return 0;
      }

      // 0s at the begin
      int e=*lower_bound(zs.begin(),zs.end(),x);
      int f=*lower_bound(zs.begin(),zs.end(),y);

      // cout<<e<<" "<<f<<":"<<a<<" "<<b<<endl;
      // cout<<idx[e]<<" "<<idx[f]<<":"<<idx[a]<<" "<<idx[b]<<endl;
      // cout<<lcp.lcp(idx[e],idx[f])<<endl;

      // length differ
      if(idx[a]-idx[e]!=idx[b]-idx[f]) return 0;

      // same
      if(e==f) return 1;

      int len=idx[a]-idx[e]+1;
      return lcp.lcp(idx[e],idx[f])>=len;
    };

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int x,y,l;
    cin>>x>>y>>l;
    x--;y--;
    cout<<(solve(x,y,l)?"Yes":"No")<<"\n";
  }
  cout<<flush;
  return 0;
}