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
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  if(max(l1, l2)<=min(r1, r2)) {
    cout << max(l1, l2) << '\n';
  } else {
    cout << l1+l2 << '\n';
  }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}