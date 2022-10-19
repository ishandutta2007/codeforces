#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  string s;
  cin >> s;
  map<char,int>mp;
  for(auto i : s) {
    if(isupper(i)) {
      if(!mp[tolower(i)]) {
        cout << "NO\n";
        return;
      }
    } else mp[i]=1;
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}