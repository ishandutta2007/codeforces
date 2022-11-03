#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int i,j,k;
  cin >> n;
  vector<int> r,l;
  string s;
  cin >> s;
  for(i=0;i<n;i++){
    cin >> k;
    if(s[i]=='R') r.push_back(k);
    else l.push_back(k);
  }
  int ans=-1;
  for(i=0;i<r.size();i++){
    if(lower_bound(l.begin(),l.end(),r[i])!=l.end()){
      j=distance(l.begin(),lower_bound(l.begin(),l.end(),r[i]));
      if(ans==-1) ans=(l[j]-r[i])/2;
      else ans=min(ans,(l[j]-r[i])/2);
    }
  }
  cout << ans << endl;
  return 0;
}