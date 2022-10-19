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
const ll MOD=998244353;
vector<int>V[LIM];
ll T[LIM], tmp[LIM], in[LIM];
void solve() {
  ll n, m;
  cin >> n >> m;
  rep(i, n) {
    V[i].clear();
    cin >> T[i];
    in[i]=0;
  }
  rep(i, m) {
    int a, b;
    cin >> a >> b; --a; --b;
    V[a].pb(b);
    ++in[b];
  }
  rep(i, n) {
    rep(j, n) tmp[j]=T[j];
    bool ok=false;
    rep(j, n) if(T[j]) {
      ok=true;
      --tmp[j];
      for(auto l : V[j]) ++tmp[l];
    }
    rep(j, n) T[j]=tmp[j];
    if(!ok) {
      cout << i << '\n';
      return;
    }
  }
  rep(i, n) T[i]%=MOD;
  queue<int>q;
  rep(i, n) if(!in[i]) q.push(i);
  while(!q.empty()) {
    int p=q.front(); q.pop();
    if(!V[p].size()) {
      cout << (T[p]+n)%MOD << '\n';
      return;
    }
    for(auto i : V[p]) {
      --in[i];
      if(!in[i]) q.push(i);
      T[i]=(T[i]+T[p])%MOD;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}