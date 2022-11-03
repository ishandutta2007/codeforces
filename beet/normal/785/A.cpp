#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  map<string,int> m;
  m["Tetrahedron"]=4;
  m["Cube"]=6;
  m["Octahedron"]=8;
  m["Dodecahedron"]=12;
  m["Icosahedron"]=20;
  int n;
  cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    ans+=m[s];
  }
  cout<<ans<<endl;
  return 0;
}