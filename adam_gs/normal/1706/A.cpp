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
  string s;
  rep(i, m) s+="B";
  while(n--) {
    int a;
    cin >> a; --a;
    a=min(a, (int)s.size()-a-1);
    if(s[a]=='A') s[s.size()-a-1]='A';
    else s[a]='A';
  }
  cout << s << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}