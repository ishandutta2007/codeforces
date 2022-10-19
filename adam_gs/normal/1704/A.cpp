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
  string a, b;
  cin >> n >> m >> a >> b;
  rep(i, m-1) {
    if(a[a.size()-i-1]!=b[b.size()-i-1]) {
      cout << "NO\n";
      return;
    }
  }
  int x=0, y=0;
  rep(i, n-m+1) if(a[i]=='0') x=1; else y=1;
  cout << ((b[0]=='0'&&x==0)||(b[0]=='1'&&y==0)?"NO":"YES") << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}