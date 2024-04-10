#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
const int LIM=3e5+7;
vector<pair<int,int>>G[LIM];
vector<pair<int,pair<ll,int>>>V[LIM];
pair<pair<int,int>,ll>kraw[LIM];
ll odl[LIM], lst[LIM], T[LIM];
int DFS(int x, int o, int k) {
  for(auto i : G[x]) if(i.st!=o) {
    k=DFS(i.st, x, k);
    if(k>0) {
      T[i.nd]=0;
      --k;
    }
  }
  return k;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  rep(i, m) {
    cin >> kraw[i].st.st >> kraw[i].st.nd >> kraw[i].nd;
    --kraw[i].st.st; --kraw[i].st.nd;
    V[kraw[i].st.st].pb({kraw[i].st.nd, {kraw[i].nd, i}});
    V[kraw[i].st.nd].pb({kraw[i].st.st, {kraw[i].nd, i}});
  }
  rep(i, n) odl[i]=INF;
  priority_queue<pair<ll,pair<int,int>>>q;
  q.push({0, {0, 0}});
  while(!q.empty()) {
    ll o=-q.top().st, p=q.top().nd.st, x=q.top().nd.nd; q.pop();
    if(odl[p]<=o) continue;
    odl[p]=o;
    lst[p]=x;
    for(auto i : V[p]) if(odl[i.st]==INF) q.push({-o-i.nd.st, {i.st, i.nd.nd}});
  }
  rep(i, n-1) {
    int p=lst[i+1];
    G[kraw[p].st.st].pb({kraw[p].st.nd, p});
    G[kraw[p].st.nd].pb({kraw[p].st.st, p});
    T[p]=1;
  }
  DFS(0, 0, n-k-1);
  vector<int>ans;
  rep(i, m) if(T[i]) ans.pb(i);
  cout << ans.size() << '\n';
  for(auto i : ans) cout << i+1 << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  //cin >> _;
  while(_--) solve();
}