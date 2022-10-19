#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void rek(vector<int>&V, int n) {
  int x=0;
  while(x*x<n) ++x;
  int p=x*x-n;
  if(p) rek(V, p-1);
  for(int i=n; i>=p; --i) V.pb(i);
}
void solve() {
  int n;
  cin >> n;
  vector<int>V;
  rek(V, n-1);
  for(auto i : V) cout << i << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}