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
  int A[n], B[n];
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, n) {
    int po=0, ko=i;
    while(po<ko) {
      int sr=(po+ko)/2;
      if(B[sr]<A[i]) po=sr+1; else ko=sr;
    }
    cout << B[po]-A[i] << " ";
  }
  cout << '\n';
  int suf[n];
  suf[n-1]=n-1;
  for(int i=n-1; i; --i) {
    if(A[i]<=B[i-1]) suf[i-1]=suf[i];
    else suf[i-1]=i-1;
  }
  rep(i, n) cout << B[suf[i]]-A[i] << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}