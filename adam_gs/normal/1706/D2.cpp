#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
int T[LIM], P[LIM], najm[LIM], mp[LIM];
void solve() {
  rep(i, LIM) {
    najm[i]=LIM;
    mp[i]=0;
  }
  int n, k, mi=LIM, ans=LIM;
  cin >> n >> k;
  rep(i, n) {
    cin >> P[i];
    T[P[i]]=1;
    mi=min(mi, P[i]);
  }
  for(int i=1; i<LIM; ++i) {
    if(!T[i]) continue;
    for(int j=2; j*j<=i+10; ++j) {
      if(i/(j-1)>i/j) {
        najm[i/(j-1)]=min(najm[i/(j-1)], i/j);
        mp[i/(j-1)]=max(mp[i/(j-1)], j);
      }
    }
    for(int j=1; j*j<=i+10; ++j) {
      najm[j]=min(najm[j], i/(i/j+1));
      mp[j]=max(mp[j], i/j+1);
    }
  }
  for(int i=LIM-1; i>=0; --i) {
    ans=min(ans, i-mi);
    mi=min(mi, najm[i]);
    if(mp[i]>k) {
      i=0;
      break;
    }
  }
  cout << ans << '\n';
  rep(i, n) T[P[i]]=0;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}