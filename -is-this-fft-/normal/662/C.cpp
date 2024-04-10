#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;

void FST (vector<ll> &a, bool inv) { //size(a) == $2^x$
  for (ll n =(ll)a.size(), step = 1; step < n; step *= 2) {
    for (ll i = 0; i < n; i += 2 * step)
      for (ll j = i; j < i + step; j++) {
        ll &u = a[j], &v = a[j + step];
        tie(u, v) = make_pair(u + v, u - v);
      }
  }
  if (inv) {
    for (ll i = 0; i < (ll) a.size(); i++) {
      a[i] /= a.size();
    }
  }
}

vector<ll> conv (vector<ll> a, vector<ll> b) {
  FST(a, 0);
  FST(b, 0);
  for (ll i = 0; i < (ll) a.size(); i++) {
    a[i] *= b[i];
  }
  FST(a, 1);
  return a;
}

const ll MAX_W = 1e5;
const ll MAX_H = 22;

char grid [MAX_H][MAX_W];

int main () {
  ios::sync_with_stdio(false);

  int height, width;
  cin >> height >> width;

  for (ll i = 0; i < height; i++) {
    for (ll j = 0; j < width; j++) {
      cin >> grid[i][j];
      grid[i][j] -= '0';
    }
  }
  
  vector<ll> cnt (1 << height, 0);
  for (ll j = 0; j < width; j++) {
    ll cur = 0;
    for (ll i = 0; i < height; i++) {
      cur <<= 1;
      cur += grid[i][j];
    }
    cnt[cur]++;
  }

  vector<ll> score (1 << height);
  for (int i = 0; i < 1 << height; i++) {
    score[i] = min(__builtin_popcount(i), height - __builtin_popcount(i));
  }

  vector<ll> ans = conv(cnt, score);
  ll sol = height * width + 5;
  for (ll i = 0; i < 1 << height; i++) {
    sol = min(sol, ans[i]);
  }
  cout << sol << endl;
}