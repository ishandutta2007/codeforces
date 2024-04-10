#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, INF=1e9+7, LG=20;
set<pair<int,int>>S[LIM];
int F[LIM];
pair<int,int>nxt[LIM][LG];
int fnd(int x) {
  if(F[x]==x) return x;
  return F[x]=fnd(F[x]);
}
void uni(int a, int b, int x) {
  a=fnd(a); b=fnd(b);
  if(a==b) return;
  if(S[a].size()<S[b].size()) swap(a, b);
  for(auto i : S[b]) {
    auto it=S[a].lower_bound(i);
    if(it!=S[a].begin()) {
      --it;
      auto p=*it;
      if(p.nd+1==i.st) {
        nxt[p.nd][0]={i.nd, x};
        S[a].erase(it);
        i.st=p.st;
      }
    }
    it=S[a].lower_bound(i);
    if(it!=S[a].end()) {
      auto p=*it;
      if(i.nd+1==p.st) {
        nxt[i.nd][0]={p.nd, x};
        S[a].erase(it);
        i.nd=p.nd;
      }
    }
    S[a].insert(i);
  }
  S[b].clear();
  F[b]=a;
}
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  rep(i, n) {
    S[i].clear();
    S[i].insert({i, i});
    F[i]=i;
    nxt[i][0]={i, 0};
  }
  rep(i, m) {
    int a, b;
    cin >> a >> b; --a; --b;
    uni(a, b, i+1);
  }
  for(int j=1; j<LG; ++j) {
    rep(i, n) nxt[i][j]=nxt[nxt[i][j-1].st][j-1];
  }
  while(q--) {
    int l, r;
    cin >> l >> r; --l; --r;
    if(l==r) {
      cout << 0 << " ";
      continue;
    }
    for(int i=LG-1; i>=0; --i) if(nxt[l][i].st<r) l=nxt[l][i].st;
    cout << nxt[l][0].nd << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}