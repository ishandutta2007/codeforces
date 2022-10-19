#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
vector<int>V[2*LIM], S[2*LIM], P[LIM];
int T[LIM], odw[2*LIM], kol[2*LIM], akt;
stack<int>sto;
void DFS(int x) {
  odw[x]=1;
  for(auto i : V[x]) if(!odw[i]) DFS(i);
  sto.push(x);
}
void DFS2(int x) {
  kol[x]=akt;
  for(auto i : S[x]) if(!kol[i]) DFS2(i);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  rep(i, n) cin >> T[i];
  rep(i, m) {
    int k;
    cin >> k;
    while(k--) {
      int a;
      cin >> a; --a;
      P[a].pb(i);
    }
  }
  rep(i, n) {
    if(!T[i]) {
      V[P[i][0]].pb(P[i][1]+m);
      V[P[i][1]].pb(P[i][0]+m);
      S[P[i][1]+m].pb(P[i][0]);
      S[P[i][0]+m].pb(P[i][1]);
      V[P[i][0]+m].pb(P[i][1]);
      V[P[i][1]+m].pb(P[i][0]);
      S[P[i][1]].pb(P[i][0]+m);
      S[P[i][0]].pb(P[i][1]+m);
    } else {
      V[P[i][0]].pb(P[i][1]);
      S[P[i][1]].pb(P[i][0]);
      V[P[i][0]+m].pb(P[i][1]+m);
      S[P[i][1]+m].pb(P[i][0]+m);
      V[P[i][1]].pb(P[i][0]);
      S[P[i][0]].pb(P[i][1]);
      V[P[i][1]+m].pb(P[i][0]+m);
      S[P[i][0]+m].pb(P[i][1]+m);
    }
  }
  rep(i, 2*m) if(!odw[i]) DFS(i);
  while(!sto.empty()) {
    int p=sto.top(); sto.pop();
    if(!kol[p]) {
      ++akt;
      DFS2(p);
    }
  }
  rep(i, m) if(kol[i]==kol[m+i]) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
}