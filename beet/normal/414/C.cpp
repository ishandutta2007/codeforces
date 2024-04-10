#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
  vector<int> v;
  int klr,rev,d;
  node(int a){
    v.push_back(a);
    klr=rev=d=0;
  }
  node(node& l,node& r){
    d=l.d+1;
    for(int i:l.v) v.push_back(i);
    for(int i:r.v) v.push_back(i);
    sort(v.begin(),v.end());
    klr=rev=0;
    for(int i:r.v){
      auto latte=upper_bound(l.v.begin(),l.v.end(),i);
      klr+=(int)(l.v.end()-latte);
    }
    for(int i:l.v){
      auto latte=upper_bound(r.v.begin(),r.v.end(),i);
      rev+=(int)(r.v.end()-latte);
    }
    //cout<<d<<":"<<klr<<endl;
  }
};
int a[1LL<<20],q[1LL<<20];
signed main(){
  int n,m;
  scanf("%lld",&n);
  for(int i=0;i<(1LL<<n);i++) scanf("%lld",a+i);
  scanf("%lld",&m);
  for(int i=0;i<m;i++) scanf("%lld",q+i);
  vector<node> v[n+1];
  for(int i=0;i<(1LL<<n);i++) v[0].push_back(node(a[i]));
  for(int i=0;i<n;i++)
    for(int j=0;j<(int)v[i].size()/2;j++)
      v[i+1].push_back(node(v[i][j*2],v[i][j*2+1]));
  int tmp[2][n+1];
  int flg[n+1];
  memset(tmp,0,sizeof(tmp));
  memset(flg,0,sizeof(flg));
  for(int i=0;i<=n;i++){
    for(int j=0;j<(int)v[i].size();j++){
      tmp[0][i]+=v[i][j].klr;
      tmp[1][i]+=v[i][j].rev;
    }
    //cout<<tmp[0][i]<<" "<<tmp[1][i]<<endl;
  }
  for(int i=0;i<m;i++){
    for(int j=q[i];j>=0;j--) flg[j]=!flg[j];
    int ans=0;
    for(int j=0;j<=n;j++) ans+=tmp[flg[j]][j];
    //for(int j=0;j<=n;j++) cout<<ans<<"+"<<tmp[flg[j]][j]<<endl;
    printf("%lld\n",ans);
  }
  return 0;
}