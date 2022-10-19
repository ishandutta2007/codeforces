#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int INF=2e9+7;
void solve() {
  int n, k;
  cin >> n >> k;
  int T[n], a[n];
  rep(i, n) T[i]=INF;
  rep(i, k) cin >> a[i];
  rep(i, k) cin >> T[a[i]-1];
  int lewo[n], prawo[n];
  rep(i, n) {
    lewo[i]=T[i];
    if(i) lewo[i]=min(lewo[i], lewo[i-1]+1);
  }
  for(int i=n-1; i>=0; --i) {
    prawo[i]=T[i];
    if(i<n-1) prawo[i]=min(prawo[i], prawo[i+1]+1);
  }
  rep(i, n) cout << min(lewo[i], prawo[i]) << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}