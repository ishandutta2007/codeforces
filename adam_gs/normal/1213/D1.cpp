#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[LIM];
void solve() {
  int n, k;
  cin >> n >> k;
  while(n--) {
    int a;
    cin >> a;
    int akt=0;
    V[a].pb(0);
    while(a) {
      a/=2;
      ++akt;
      V[a].pb(akt);
    }
  }
  int ans=LIM;
  rep(i, LIM) {
    sort(all(V[i]));
    if(V[i].size()<k) continue;
    int sum=0;
    rep(j, k) sum+=V[i][j];
    ans=min(ans, sum);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  //cin >> _;
  while(_--) solve();
}