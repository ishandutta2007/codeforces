#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=998244353;
void solve() {
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  pair<int,int>T[q];
  int A[n], B[m], ilea=0, ileb=0;
  rep(i, n) A[i]=0;
  rep(i, m) B[i]=0;
  rep(i, q) {
    cin >> T[i].st >> T[i].nd;
    --T[i].st; --T[i].nd;
  }
  ll ans=1;
  for(int i=q-1; i>=0; --i) {
    bool ok=true;
    if((A[T[i].st]==1 || ileb==m) && (B[T[i].nd]==1 || ilea==n)) ok=false;
    if(ok) ans=(ans*k)%MOD;
    if(A[T[i].st]==0) {
      A[T[i].st]=1;
      ++ilea;
    }
    if(B[T[i].nd]==0) {
      B[T[i].nd]=1;
      ++ileb;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}