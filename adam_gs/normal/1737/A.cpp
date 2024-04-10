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
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ile[26];
  rep(i, 26) ile[i]=0;
  rep(i, s.size()) ++ile[s[i]-'a'];
  rep(i, k) {
    int akt=0, lst;
    rep(j, n/k) {
      if(akt==-1) {
        int ma=0;
        rep(l, 26) ma=max(ma, ile[l]);
        for(int l=25; l>=0; --l) if(ile[l]==ma || (ile[l] && l>=lst)) {
          --ile[l];
          break;
        }
      } else if(ile[akt]) {
        --ile[akt]; ++akt;
      } else {
        cout << char('a'+akt);
        lst=akt;
        akt=-1;
        int ma=0;
        rep(l, 26) ma=max(ma, ile[l]);
        for(int l=25; l>=0; --l) if(ile[l]==ma || (ile[l] && l>=lst)) {
          --ile[l];
          break;
        }
      }
    }
    if(akt!=-1) cout << char('a'+akt);
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}