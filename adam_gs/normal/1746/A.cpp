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
  int n, k;
  cin >> n >> k;
  int T[n];
  bool ok=false;
  rep(i, n) {
    cin >> T[i];
    if(T[i]) ok=true;
  }
  if(!ok) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}