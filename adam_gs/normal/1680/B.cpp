#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  int n, m, x=10, y=10;
  cin >> n >> m;
  string T[n];
  rep(i, n) {
    cin >> T[i];
    rep(j, m) if(T[i][j]=='R') {
      x=min(x, i);
      y=min(y, j);
    }
  }
  cout << (T[x][y]=='R'?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}