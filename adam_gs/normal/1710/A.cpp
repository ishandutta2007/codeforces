#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll T[k], ans1=0, ans2=0;
  bool ok1=false, ok2=false;
  rep(i, k) {
    cin >> T[i];
    ll a=T[i]/n, b=T[i]/m;
    if(a<2) a=0;
    if(b<2) b=0;
    if(a>2) ok1=true;
    if(b>2) ok2=true;
    ans1+=a;
    ans2+=b;
  }
  cout << ((ans1>=m&&(m%2==0||ok1))||(ans2>=n&&(n%2==0||ok2))?"Yes":"No") << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}