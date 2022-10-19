#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2e6+7, MOD=998244353;
vector<int>pi, ile;
map<int,int>mp, mp2;
int cp[LIM], T[LIM], Z[LIM];
void solve() {
  int n;
  cin >> n;
  rep(i, n) {
    cin >> T[i];
    Z[i]=T[i];
    int x=sqrt(Z[i]);
    if(x*x==Z[i]) {
        int z=sqrt(x);
        if(z*z==x) {
          if(!mp[z]) {
            mp[z]=1;
            pi.pb(z);
            ile.pb(0);
          }
        } else {
        if(!mp[x]) {
         mp[x]=1;
         pi.pb(x);
         ile.pb(0);
        }
      }
      Z[i]=1;
    }
    if(Z[i]==1) continue;
    x=cbrt(Z[i]);
    if(x*x*x==Z[i]) {
      if(!mp[x]) {
        mp[x]=1;
        pi.pb(x);
        ile.pb(0);
      }
      Z[i]=1;
    }
  }
  rep(i, n) rep(j, n) if(Z[i]!=Z[j]) {
    int p=gcd(Z[i], Z[j]);
    if(p!=1) {
      int a=Z[i]/p, b=Z[i]/p;
      if(!mp[p]) {
        mp[p]=1;
        pi.pb(p);
        ile.pb(0);
      }
      if(!mp[a]) {
        mp[a]=1;
        pi.pb(a);
        ile.pb(0);
      }
      if(!mp[b]) {
        mp[b]=1;
        pi.pb(b);
        ile.pb(0);
      }
    }
  }
  bool ok=true;
  while(ok) {
    ok=false;
  rep(i, n) {
    Z[i]=T[i];
    rep(j, pi.size()) while(Z[i]%pi[j]==0) Z[i]/=pi[j];
    if(Z[i]!=T[i] && Z[i]!=1) {
      pi.pb(Z[i]);
      ile.pb(0);
      ok=true;
    }
  }
  }
  rep(i, n) {
    rep(j, pi.size()) {
      while(T[i]%pi[j]==0) {
        T[i]/=pi[j];
        ++ile[j];
      }
    }
    if(T[i]>1) {
      ++mp2[T[i]];
    }
  }
  int ans=1;
  for(auto i : ile) ans=(ans*(i+1))%MOD;
  for(auto i : mp2) {
    int a=i.nd+1;
    a=(a*a)%MOD;
    ans=(ans*a)%MOD;
  }
  cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}