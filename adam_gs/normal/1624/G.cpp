#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
int F[LIM];
pair<int,pair<int,int>>T[LIM];
int fnd(int x) {
  if(F[x]==x) return x;
  return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
  if(fnd(a)==fnd(b)) return false;
  F[fnd(b)]=fnd(a);
  return true;
}
void solve() {
	int n, m;
  cin >> n >> m;
  rep(i, m) {
    cin >> T[i].nd.st >> T[i].nd.nd >> T[i].st;
    --T[i].nd.st; --T[i].nd.nd;
  }
  int ans=(1ll<<31ll)-1;
  for(int i=30; i>=0; --i) {
    rep(j, n) F[j]=j;
    int ile=0;
    rep(j, m) if((T[j].st|(ans-(1<<i)))<=ans-(1<<i)) {
      if(uni(T[j].nd.st, T[j].nd.nd)) ++ile;
    }
    if(ile==n-1) ans-=1<<i;
  }
  cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}