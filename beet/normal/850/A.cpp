#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int>  vec;
int dot(vec a,vec b){
  int res=0;
  for(int i=0;i<5;i++) res+=a[i]*b[i];
  return res;
}
vec sub(vec a,vec b){
  for(int i=0;i<5;i++) a[i]-=b[i];
  return a;
}
vec d[1001][1001];
signed main(){
  int n;
  cin>>n;
  vec v[n];
  for(int i=0;i<n;i++){
    v[i].resize(5);
    for(int j=0;j<5;j++) cin>>v[i][j];
  }
  // puts("a");
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      d[i][j]=sub(v[j],v[i]);
  vec ans;
  for(int i=0;i<n;i++){
    bool f=1;
    for(int j=0;j<n;j++){
      if(i==j) continue;
      for(int k=j+1;k<n;k++){
	f&=dot(d[i][j],d[i][k])<=0;
	if(!f) break;
      }
      if(!f) break;
    }
    if(f) ans.push_back(i+1);
  }
  cout<<ans.size()<<endl;
  for(int i:ans) cout<<i<<endl;
  return 0;
}