#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=507;
int T[LIM][LIM], ans[2*LIM], akt;
vector<pair<int,int>>kraw;
void DFS(vector<int>V, int x) {
  int ma=0, li=0;
  for(auto i : V) for(auto j : V) ma=max(ma, T[i][j]);
  ans[x]=ma;
  vector<int>P[V.size()];
  int gdzie[V.size()];
  rep(i, V.size()) {
    bool ok=true;
    rep(j, i) if(T[V[i]][V[j]]!=ma) {
      gdzie[i]=gdzie[j];
      ok=false;
      break;
    }
    if(ok) {
      gdzie[i]=li;
      ++li;
    }
    P[gdzie[i]].pb(V[i]);
  }
  rep(i, li) if(P[i].size()==1) kraw.pb({P[i][0], x}); else {
    ++akt;
    kraw.pb({akt, x});
    DFS(P[i], akt);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  rep(i, n) rep(j, n) cin >> T[i][j];
  akt=n;
  vector<int>P;
  rep(i, n) {
    P.pb(i);
    ans[i]=T[i][i];
  }
  DFS(P, akt);
  cout << akt+1 << '\n';
  rep(i, akt+1) cout << ans[i] << " ";
  cout << '\n' << n+1 << '\n';
  for(auto i : kraw) cout << i.st+1 << " " << i.nd+1 << '\n';
}