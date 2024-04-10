#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int N=1<<20;
vector<pair<int,int>>pytaj[N], dodaj[N];
ll tr[2*N];
void upd(int v, ll x) {
  v+=N;
  while(v) {
    tr[v]+=x;
    v/=2;
  }
}
ll cnt(int l, int r) {
  l+=N; r+=N;
  ll ans=tr[l];
  if(l!=r) ans+=tr[r];
  while(l/2!=r/2) {
    if(l%2==0) ans+=tr[l+1];
    if(r%2==1) ans+=tr[r-1];
    l/=2; r/=2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, m, ans=1;
  cin >> n >> m;
  while(n--) {
    int y, l, r;
    cin >> y >> l >> r;
    if(l==0 && r==1000000) ++ans;
    dodaj[l].pb({y, 1});
    dodaj[r+1].pb({y, -1});
  }
  while(m--) {
    int x, l, r;
    cin >> x >> l >> r;
    if(l==0 && r==1000000) ++ans;
    pytaj[x].pb({l, r});
  }
  rep(i, N) {
    for(auto j : dodaj[i]) upd(j.st, j.nd);
    for(auto j : pytaj[i]) ans+=cnt(j.st, j.nd);
  }
  cout << ans << '\n';
}