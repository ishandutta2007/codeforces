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
  if(n==3) {
    cout << -1 << '\n';
    return;
  }
  vector<int>V;
  rep(i, n) V.pb(n-i-1);
  rep(i, n) if(V[i]==i) reverse(V.begin()+i, V.end());
  for(auto i : V) cout << i+1 << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}