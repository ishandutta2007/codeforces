#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
  int n;
  cin >> n;
  int T[n];
  bool ok=true;
  rep(i, n) {
    cin >> T[i];
    if(T[i]%T[0]!=0) ok=false;
  }
  cout << (ok?"YES":"NO") << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}