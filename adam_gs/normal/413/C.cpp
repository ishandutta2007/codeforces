#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=107;
ll T[LIM], ok[LIM];
vector<ll>V;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  rep(i, n) cin >> T[i];
  rep(i, m) {
    int a;
    cin >> a; --a;
    ok[a]=1;
  }
  ll ans=0;
  rep(i, n) if(ok[i]) V.pb(T[i]); else ans+=T[i];
  sort(all(V));
  reverse(all(V));
  for(auto i : V) ans+=max(ans, i);
  cout << ans << '\n';
}