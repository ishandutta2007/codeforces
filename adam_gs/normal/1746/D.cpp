#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[LIM];
ll T[LIM], ile[LIM], ans;
ll DFS(int x) {
  ans+=ile[x]*T[x];
  ll p=0;
  if(V[x].size()) p=ile[x]/V[x].size();
  vector<ll>P;
  for(auto i : V[x]) {
    ile[i]=p;
    P.pb(DFS(i));
  }
  sort(all(P));
  if(V[x].size()) {
    rep(i, ile[x]%V[x].size()) {
      ans+=P.back(); P.pop_back();
    }
  }
  if(P.size()==0) return T[x];
  return P.back()+T[x];
}
void solve() {
  ans=0;
  int n, k;
  cin >> n >> k;
  rep(i, n) {
    V[i].clear();
    T[i]=ile[i]=0;
  }
  rep(i, n-1) {
    int a;
    cin >> a; --a;
    V[a].pb(i+1);
  }
  rep(i, n) cin >> T[i];
  ile[0]=k;
  DFS(0);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}