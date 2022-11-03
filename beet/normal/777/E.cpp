#include<bits/stdc++.h>
using namespace std;
#define int long long
struct RMQ{
  static const int MAX_N = 1 << 18;
  int n,dat[2*MAX_N-1];
  RMQ(){}
  RMQ(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    memset(dat,0,sizeof(dat));
  }
  void update(int k,int a){
    k+=n-1;
    dat[k]=max(dat[k],a);
    while(k>0){
      k=(k-1)/2;
      dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
  }
  int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b) return dat[k];
    else{
      int vl=query(a,b,k*2+1,l,(l+r)/2);
      int vr=query(a,b,k*2+2,(l+r)/2,r);
      return max(vl,vr);
    }
  }
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};
struct st{
  int a,b,h;
  st(){}
  st(int a,int b,int h):a(a),b(b),h(h){}
  bool operator<(const st &n)const{
    return b==n.b?a>n.a:b>n.b;
  }
};
signed main(){
  int n;
  cin>>n;
  vector<int> v;
  vector<st> s(n);
  for(int i=0;i<n;i++){
    //scanf("%lld %lld %lld",&(s[i].a),&(s[i].b),&(s[i].h));
    cin>>s[i].a>>s[i].b>>s[i].h;
    v.push_back(s[i].a);
    v.push_back(s[i].b);
  }
  sort(s.begin(),s.end());
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  map<int,int> m;
  int sz=v.size();
  for(int i=0;i<sz;i++) m[v[i]]=i;
  RMQ rmq(sz);
  for(int i=0;i<n;i++){
    //cout<<s[i].a<<" "<<s[i].b<<endl;
    int t=rmq.query(0,m[s[i].b]);
    rmq.update(m[s[i].a],t+s[i].h);
  }
  //for(int i=0;i<sz;i++) cout<<i<<":"<<rmq.query(i,i+1)<<endl;
  cout<<rmq.query(0,sz)<<endl;
  return 0;
}