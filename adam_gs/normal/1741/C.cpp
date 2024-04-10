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
  map<ll,ll>mp;
  ll T[n];
  rep(i, n) {
    cin >> T[i];
    if(i) T[i]+=T[i-1];
    mp[T[i]]=i;
  }
  ll mi=n;
  rep(k, n) {
    ll akt=-1, ma=0, krok=T[k], ile=1;
    while(akt!=n-1) {
      if(mp.find(T[k]*ile)==mp.end()) {
        akt=-1;
        break;
      }
      ma=max(ma, mp[T[k]*ile]-akt);
      akt=mp[T[k]*ile];
      ++ile;
    }
    if(akt==-1) continue;
    mi=min(mi, ma);
  }
  cout << mi << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}