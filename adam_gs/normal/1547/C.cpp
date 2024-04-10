#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
  int k, n, m;
  cin >> k >> n >> m;
  int a[n], b[m];
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  int la=0, lb=0;
  vector<int>ans;
  while(la<n || lb<m) {
    if(la<n) {
      if(a[la]<=k) {
        ans.pb(a[la]);
        if(a[la]==0) ++k;
        ++la;
      } else if(lb<m && b[lb]<=k) {
        ans.pb(b[lb]); 
        if(b[lb]==0) ++k;
        ++lb;
      } else {
        cout << -1 << '\n';
        return;
      }
    } else {
      if(b[lb]<=k) {
        ans.pb(b[lb]);
        if(b[lb]==0) ++k;
        ++lb;
      } else {
        cout << -1 << '\n';
        return;
      }
    }
  }
  for(auto i : ans) cout << i << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}