#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int que(int a, int b) {
  cout << "? " << a+1 << " " << b+1 << endl;
  int x;
  cin >> x;
  return x;
}
void solve() {
  int n;
  cin >> n;
  vector<int>V;
  rep(i, 1<<n) V.pb(i);
  while(V.size()>2) {
    vector<int>ans;
    for(int i=0; i<V.size(); i+=4) {
      int x=que(V[i], V[i+2]);
      if(x==0) {
        if(que(V[i+1], V[i+3])==1) ans.pb(V[i+1]); else ans.pb(V[i+3]);
      } else if(x==1) {
        if(que(V[i], V[i+3])==1) ans.pb(V[i]); else ans.pb(V[i+3]);
      } else {
        if(que(V[i+1], V[i+2])==1) ans.pb(V[i+1]); else ans.pb(V[i+2]);
      }
    }
    V=ans;
  }
  if(V.size()==2) if(que(V[0], V[1])==2) V[0]=V[1];
  cout << "! " << V[0]+1 << endl;
}
int main() {
  int _=1;
  cin >> _;
  while(_--) solve();
}