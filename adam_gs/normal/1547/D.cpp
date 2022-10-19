#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
  int n;
  cin >> n;
  int T[n];
  rep(i, n) cin >> T[i];
  cout << "0 ";
  int lst=T[0];
  for(int i=1; i<n; ++i) {
    if((lst&T[i])==lst) {
      cout << "0 ";
      lst=T[i];
    } else {
      int p=(lst&T[i])^lst;
      cout << p << " ";
      lst=T[i]^p;
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}