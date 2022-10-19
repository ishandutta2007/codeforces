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
  int T[m];
  vector<int>V;
  rep(i, m) {
    cin >> T[i];
  }
  sort(T, T+m);
  rep(i, m) if(i) V.pb(T[i]-T[i-1]-1);
  V.pb(T[0]-1+n-T[m-1]);
  sort(all(V));
  reverse(all(V));
  int akt=0, sum=0;
  for(auto i : V) {
    i-=2*akt;
    if(i<=0) break;
    ++sum;
    i-=2;
    ++akt;
    if(i>0) {
      sum+=i;
      ++akt;
    }
  }
  cout << n-sum << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}