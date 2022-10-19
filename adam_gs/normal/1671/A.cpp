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
  string s;
  cin >> s;
  s="$"+s+"$";
  for(int i=1; i+1<s.size(); ++i) {
    if(s[i]!=s[i-1] && s[i]!=s[i+1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}