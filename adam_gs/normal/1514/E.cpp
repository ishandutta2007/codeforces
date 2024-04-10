#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
bool kraw(int a, int b) {
  cout << 1 << " " << a << " " << b << endl;
  int x;
  cin >> x;
  return x;
}
void dc(vector<int>&V) {
  if(V.size()<2) return;
  vector<int>A, B;
  rep(i, V.size()/2) A.pb(V[i]);
  for(int i=V.size()/2; i<V.size(); ++i) B.pb(V[i]);
  dc(A);
  dc(B);
  int l1=0, l2=0;
  while(l1<A.size() || l2<B.size()) {
    if(l2==B.size() || l1<A.size() && kraw(A[l1], B[l2])) {
      V[l1+l2]=A[l1];
      ++l1;
    } else {
      V[l1+l2]=B[l2];
      ++l2;
    }
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int>V;
  rep(i, n) V.pb(i);
  dc(V);
  int kol[n];
  rep(i, n) {
    kol[i]=i;
    while(kol[i]) {
      cout << 2 << " " << V[i] << " " << kol[i] << " ";
      rep(j, kol[i]) cout << V[j] << " ";
      cout << endl;
      int x;
      cin >> x;
      if(!x) break;
      int p=kol[kol[i]-1];
      for(int j=p; j<=i; ++j) kol[j]=p;
    }
  }
  int ans[n][n];
  rep(i, n) rep(j, n) ans[i][j]=0;
  rep(i, n) rep(j, i+1) ans[V[j]][V[i]]=1;
  rep(i, n) rep(j, n) if(kol[i]==kol[j]) ans[V[i]][V[j]]=1;
  cout << 3 << endl;
  rep(i, n) {
    rep(j, n) cout << ans[i][j];
    cout << endl;
  }
  int x;
  cin >> x;
}
int main() {
  int _;
  cin >> _;
  while(_--) solve();
}