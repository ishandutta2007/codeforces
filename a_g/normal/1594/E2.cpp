#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

ll expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int k, n;
  cin >> k >> n;
  ll totalnodes = (1LL << k) - 1;
  ll ans = expmod(2, totalnodes-n, MOD);
  map<string, int> labels = {{"white", 0}, {"yellow", 0}, {"red", 1},
    {"orange", 1}, {"green", 2}, {"blue", 2}};
  set<ll, greater<ll>> marked;
  map<ll, int> fixednodes;
  while (n--) {
    ll v;
    string s;
    cin >> v >> s;
    fixednodes[v]=labels[s];
    ll u = v;
    while (u >= 1) {
      marked.insert(u);
      u >>=1;
    }
  }
  /*
  for (auto const & x: fixednodes) {
    cout << x.first << " " << x.second << endl;
  }
  */
  if (marked.size() == 0) {
    ans *= 3*expmod(2, totalnodes-1, MOD);
  }
  else {
    ans *= expmod(2, totalnodes-marked.size(), MOD);
  }
  ans %= MOD;
  map<ll, vector<ll>> labelingways;
  for (ll v: marked) {
    labelingways[v] = {1, 1, 1};
    if (marked.count(2*v) && marked.count(2*v+1)) {
      for (int i = 0; i < 3; i++) {
        labelingways[v][i] = 0;
        for (int j = 1; j < 3; j++) {
          for (int k = 1; k < 3; k++) {
            labelingways[v][i] += labelingways[2*v][(i+j)%3]*labelingways[2*v+1][(i+k)%3];
            labelingways[v][i] %= MOD;
          }
        }
      }
    }
    else if (marked.count(2*v+1)) {
      for (int i = 0; i < 3; i++) {
        labelingways[v][i] = labelingways[2*v+1][(i+1)%3] + labelingways[2*v+1][(i+2)%3];
        labelingways[v][i] %= MOD;
      }
    }
    else if (marked.count(2*v)) {
      for (int i = 0; i < 3; i++) {
        labelingways[v][i] = labelingways[2*v][(i+1)%3] + labelingways[2*v][(i+2)%3];
        labelingways[v][i] %= MOD;
      }
    }
    if (fixednodes.count(v)) {
      int i = fixednodes[v];
      for (int k = 1; k < 3; k++) {
        labelingways[v][(i+k)%3] = 0;
      }
    }
  }
  if (marked.size() > 0) {
    ans *= accumulate(labelingways[1].begin(), labelingways[1].end(), 0LL);
    ans %= MOD;
  }
  
  cout << ans << endl;
}