#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
void solve() {
  int n;
  cin >> n;
  int T[n], mi=INF, ans=0;
  rep(i, n) {
    cin >> T[i];
    mi=min(mi, T[i]);
  }
  rep(i, n) {
    int po=1, ko=INF;
    while(po<ko) {
      int sr=(po+ko)/2;
      if(2*mi<=(T[i]+sr-1)/sr) po=sr+1; else ko=sr;
    }
    ans+=po-1;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}