#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
struct RUP{
  static const int MAX_N = 1 << 17;
  int n;
  P dat[2*MAX_N-1];
  RUP(){}
  RUP(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++) dat[i].first=0,dat[i].second=0;
  }
  int query(int k){
    k+=n-1;
    P p=dat[k];
    while(k>0){
      k=(k-1)/2;
      p=max(p,dat[k]);
    }
    return p.second;
  }
  
  void update(int a,int b,P p,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b) {
      dat[k]=max(dat[k],p);
    }else{
      update(a,b,p,k*2+1,l,(l+r)/2);
      update(a,b,p,k*2+2,(l+r)/2,r);
    }
  }
  
  void update(int a,int b,P p){
    update(a,b,p,0,0,n);
  }
};

signed main(){
  int n,m;
  scanf("%lld %lld",&n,&m);
  //cout<<n<<m<<endl;
  
  int a[n][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      scanf("%lld",&a[i][j]); 

  RUP rup(n);
  for(int i=0;i<n;i++) rup.update(i,i+1,P(i,i));
  
  for(int j=0;j<m;j++){
    for(int i=0;i<n;i++){
      int k=i;
      while(k+1<n&&a[k][j]<=a[k+1][j]) k++;
      //cout<<i<<" "<<k<<endl;
      rup.update(i,k+1,P(k,k));
      i=k;
    }
  }
  
  int k;
  cin>>k;
  for(int i=0;i<k;i++){
    int l,r;
    cin>>l>>r;
    l--;r--;
    //cout<<l<<" "<<rup.query(l)<<" "<<r<<endl;
    if(rup.query(l)<r) puts("No");
    else puts("Yes");
  }
  
  return 0;
}