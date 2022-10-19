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
  int n;
  cin >> n;
  int mi_x=0, ma_x=0, mi_y=0, ma_y=0;
  while(n--) {
    int x, y;
    cin >> x >> y;
    mi_x=min(mi_x, x);
    ma_x=max(ma_x, x);
    mi_y=min(mi_y, y);
    ma_y=max(ma_y, y);
  }
  cout << 2*(ma_x-mi_x+ma_y-mi_y) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}