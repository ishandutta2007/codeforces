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
  int n, m, sx, sy, d;
  cin >> n >> m >> sx >> sy >> d;
  if((sx<=d+1 && (sy<=d+1 || n-sx<=d)) || (sy<=d+1 && (sx<=d+1 || m-sy<=d)) || (n-sx<=d && m-sy<=d)) cout << -1 << '\n';
  else cout << n+m-2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}