#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int val(string s) {
  int p=0;
  for(auto i : s) {
    if(i!='M') ++p;
    if(i=='S') p*=-1;
  }
  return p;
}
void solve() {
  string a, b;
  cin >> a >> b;
  int x=val(a), y=val(b);
  if(x==y) cout << "=\n";
  else if(x<y) cout << "<\n";
  else cout << ">\n";
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}