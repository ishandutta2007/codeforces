#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1000000007LL;
typedef vector<int> arr;
typedef vector<arr> mat;
inline arr mul(mat a,arr& b,int mod){
  arr res(b.size(),0);
  for(int i=0;i<(int)b.size();i++)
    for(int j=0;j<(int)a[i].size();j++)
      (res[i]+=a[i][j]*b[j])%=mod;
  return res;
}
inline mat mul(mat& a,mat& b,int mod){
  mat res(a.size(),arr(b[0].size(),0));
  for(int i=0;i<(int)a.size();i++)
    for(int j=0;j<(int)b[0].size();j++)
      for(int k=0;k<(int)b.size();k++)
	(res[i][j]+=a[i][k]*b[k][j])%=mod;
  return res;
}
mat base;
inline mat mat_pow(mat a,int n,int mod){
  mat res(base);
  while(n){
    if(n&1) res=mul(a,res,mod);
    a=mul(a,a,mod);
    n>>=1;
  }
  return res;
}

typedef pair<int,int> P;
signed main(){
  int n,k;
  cin>>n>>k;
  int a[n],b[n],c[n];
  for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
  //cout<<c[0]+1<<endl;
  arr ans(c[0]+1,0);
  ans[0]=1;
  for(int i=0;i<n;i++){
    int t=min(b[i],k)-a[i];
    //cout<<t<<endl;
    mat m(c[i]+1,arr(c[i]+1,0));
    base=mat(m);
    for(int j=0;j<c[i]+1;j++){
      if(j) m[j][j-1]=1;
      m[j][j]=base[j][j]=1;
      if(j+1<c[i]+1) m[j][j+1]=1;
    }
    m=mat_pow(m,t,MOD);
    while((int)ans.size()>c[i]+1) ans.pop_back();
    while((int)ans.size()<c[i]+1) ans.push_back(0);
    //cout<<"ans: ";for(int j=0;j<c[i]+1;j++) cout<<ans[j]<<" ";cout<<endl;
    ans=mul(m,ans,MOD);
  }
  cout<<ans[0]<<endl;
  return 0;
}