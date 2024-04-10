#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  int n;
  cin >> n;
  int T[n];
  vector<int>V;
  rep(i, n) cin >> T[i];
  V.pb(T[0]);
  rep(i, n-1) if(T[i+1]!=V.back()) V.pb(T[i+1]);
  bool ans=true;
  if(V.size()>2) rep(i, V.size()-2) if(V[i]>V[i+1] && V[i+1]<V[i+2]) ans=false;
  cout << (ans?"YES":"NO") << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}