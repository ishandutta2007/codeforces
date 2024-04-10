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
  int ile[n][2];
  rep(i, n) rep(j, 2) ile[i][j]=0;
  rep(i, n) {
    int a;
    cin >> a; --a;
    ile[a][i%2]=max(ile[a][i%2], ile[a][(i+1)%2]+1);
  }
  rep(i, n) cout << max(ile[i][0], ile[i][1]) << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}