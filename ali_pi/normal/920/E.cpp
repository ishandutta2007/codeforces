#include <bits/stdc++.h>
using namespace :: std;
vector<unordered_set<int>> v;
set<int> s;


int r(int a) {
  s.erase(a);
  int x=1,y;
  auto it=s.begin();
  while(it!=s.end()) {
    while(it!=s.end() && v[a].count(*it)) it++;
    if (it==s.end()) break;
    y=*it;
    x+=r(y);
    it=s.upper_bound(y);
  }
  return x;
}

int main() {
  int n,m,a,b;cin>>n>>m;
  v=vector<unordered_set<int>>(n+1);
  vector<int> ans;
  for (int i=0;i<m;i++) {
    cin>>a>>b;
    v[a].insert(b);
    v[b].insert(a);
  }

  for (int i=1;i<=n;i++) s.insert(i);
  for (int i=1;i<=n;i++) {
    if (s.count(i)) {
      ans.push_back(r(i));
    }
  }
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<'\n';
  for (int i:ans) cout<<i<<' ';
}