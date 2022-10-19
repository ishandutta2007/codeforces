#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int>ans;
  rep(i, n) {
    int x=(r/(i+1))*(i+1);
    if(x<l) {
      cout << "NO\n";
      return;
    }
    ans.pb(x);
  }
  cout << "YES\n";
  for(auto i : ans) cout << i << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}