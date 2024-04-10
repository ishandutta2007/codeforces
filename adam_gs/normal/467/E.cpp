#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e5+7, INF=1e9+7;
int T[LIM], nxt[LIM], N=1;
pair<int,int>tr[4*LIM], nast[LIM];
vector<int>V[LIM], G;
map<int,int>mp;
void upd(int v, pair<int,int>x) {
  v+=N;
  tr[v]=x;
  v/=2;
  while(v) {
    tr[v]=min(tr[2*v], tr[2*v+1]);
    v/=2;
  }
}
pair<int,int>cnt(int l, int r) {
  if(l>r) return {INF, INF};
  l+=N; r+=N;
  pair<int,int>ans=min(tr[l], tr[r]);
  while(l/2!=r/2) {
    if(l%2==0) ans=min(ans, tr[l+1]);
    if(r%2==1) ans=min(ans, tr[r-1]);
    l/=2; r/=2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  while(N<n) N*=2;
  rep(i, 2*N) tr[i]={INF, INF};
  rep(i, n) cin >> T[i];
  for(int i=n-1; i>=0; --i) {
    if(mp[T[i]]) nxt[i]=mp[T[i]];
    else nxt[i]=INF;
    nast[i]={INF, INF};
    mp[T[i]]=i;
  }
  rep(i, n) if(nxt[i]<INF) V[nxt[i]].pb(i);
  for(int i=n-1; i>=0; --i) {
    for(auto j : V[i]) nast[j]=cnt(j+1, nxt[j]-1);
    for(auto j : V[i]) upd(j, {i, T[j]});
  }
  rep(i, n) {
    int akt=i;
    rep(j, 3) if(akt<INF) akt=nxt[akt];
    if(akt<INF) nast[i]=min(nast[i], {akt, T[i]});
  }
  int lst=-1;
  rep(i, n) if(nast[i].st<INF) {
    if(i>lst) {
      G.pb(T[i]);
      G.pb(T[nast[i].st]);
      G.pb(T[i]);
      G.pb(T[nast[i].st]);
      lst=nast[i].st;
    } else if(nast[i].st<lst) {
      G.pop_back();
      G.pop_back();
      G.pop_back();
      G.pop_back();
      G.pb(T[i]);
      G.pb(T[nast[i].st]);
      G.pb(T[i]);
      G.pb(T[nast[i].st]);
      lst=nast[i].st;
    }
  }
  cout << G.size() << '\n';
  for(auto i : G) cout << i << " ";
}