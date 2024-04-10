#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e3+7;
int T[LIM][LIM], F[LIM], kol[LIM], n;
vector<int>V[LIM];
int fnd(int x) {
  if(F[x]==x) return x;
  return F[x]=fnd(F[x]);
}
void uni(int a, int b, int c) {
  if(fnd(a)==fnd(b)) return;
  c^=kol[a]^kol[b];
  for(auto i : V[fnd(b)]) {
    kol[i]^=c;
    V[fnd(a)].pb(i);
  }
  F[fnd(b)]=a;
}
void solve() {
  cin >> n;
  rep(i, n) {
    V[i].clear();
    V[i].pb(i);
    kol[i]=0;
    F[i]=i;
  }
  rep(i, n) rep(j, n) cin >> T[i][j];
  rep(i, n) rep(j, n) {
    if(T[i][j]<T[j][i]) uni(i, j, 0);
    if(T[i][j]>T[j][i]) uni(i, j, 1);
  }
  rep(i, n) if(kol[i]) {
    rep(j, n) swap(T[i][j], T[j][i]);
  }
  rep(i, n) {
    rep(j, n) cout << T[i][j] << " ";
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}