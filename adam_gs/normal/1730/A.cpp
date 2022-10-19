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
  int n, c;
  cin >> n >> c;
  vector<int>ile(200);
  rep(i, n) {
    int a;
    cin >> a;
    ++ile[a];
  }
  int ans=0;
  rep(i, 200) ans+=min(ile[i], c);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}