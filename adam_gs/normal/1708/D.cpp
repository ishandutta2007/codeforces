#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
vector<pair<int,int>>powt(vector<int>V) {
  vector<pair<int,int>>ans;
  int akt=1;
  sort(all(V));
  for(int i=1; i<V.size(); ++i) {
    if(V[i]!=V[i-1]) {
      ans.pb({V[i-1], akt});
      akt=0;
    }
    ++akt;
  }
  ans.pb({V.back(), akt});
  return ans;
}
void solve() {
  int n, lst;
  cin >> n >> lst; --n;
  vector<int>V;
  rep(i, n) {
    int a;
    cin >> a;
    V.pb(a-lst);
    lst=a;
  }
  vector<pair<int,int>>T=powt(V);
  while(T.size()>1) {
    sort(all(T));
    int ile=0;
    for(auto i : T) ile+=i.nd-1;
    vector<int>P;
    rep(i, T.size()-1) P.pb(T[i+1].st-T[i].st);
    vector<pair<int,int>>S=powt(P);
    if(ile) S.pb({0, ile});
    T=S;
  }
  if(T[0].nd>1) T[0].st=0;
  cout << T[0].st << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}