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
  int n, m;
  cin >> n >> m;
  if((n%2==0 && m%2==1) || n>m) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  if(n%2==1) {
    rep(i, n-1) cout << 1 << " ";
    cout << m-n+1 << '\n';
  } else {
    rep(i, n-2) cout << 1 << " ";
    m-=n-2;
    cout << m/2 << " " << m/2 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}