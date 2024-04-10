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
  int T[n];
  rep(i, n) cin >> T[i];
  pair<int,int>P[n-1];
  rep(i, n-1) P[i]={T[i]-T[i+1], i+1};
  sort(P, P+n-1);
  reverse(P, P+n-1);
  vector<int>ans;
  rep(i, n-1) ans.pb(P[i].nd);
  ans.pb(0);
  reverse(all(ans));
  for(auto i : ans) cout << i+1 << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}