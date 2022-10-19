#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;

pair<ll, ll> g[M]; // g[i] .. < i ^ 3
ll X;

pair<ll, ll> comb(pair<ll, ll> a, pair<ll, ll> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

ll cube(ll x) {
  return x * x * x;
}

ll root(ll x) {
  ll t = pow(x, 1.0 / 3);
  t -= 2;
  t = max<ll>(t, 0);
  assert(cube(t) <= x);

  while (cube(t + 1) <= x)
    ++t;
  return t;
}

pair<ll, ll> fun(ll x) {
  pair<ll, ll> ans(1, 1);
  pair<ll, ll> cur(0, 0);

  while (x > 0) {
    ll t = root(x);
    ans = max(ans, comb(cur, g[t]));
    
    x -= cube(t);
    cur = comb(cur, make_pair(1, cube(t)));
  }
  ans = max(ans, cur);

  return ans;
}

void pre() {
  g[1] = make_pair(0, 0);
  for (ll i = 2; i < M; ++i)
    g[i] = fun(cube(i) - 1);

  for (int i = 1; i < 100; ++i) {
    //cout << i << ": " << g[i].first << " " << g[i].second << endl;
  }
}

void read() {
  cin >> X;
}


void kill() {
  auto ans = fun(X);
  cout << ans.first << " " << ans.second << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  pre();
  read();
  kill();
}