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
  int n, s, t;
  cin >> n >> s >> t;
  int razem=s+t-n;
  s-=razem; t-=razem;
  cout << max(s, t)+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}