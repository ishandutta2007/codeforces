#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
 
using namespace std;
 
typedef long long ll;
 
#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
const int N =50;
int dsu[N];
 
int get(int v) {
  if (v == dsu[v]) {
    return v;
  } else {
    return dsu[v] = get(dsu[v]);
  }
}
 
void uni(int u, int v) {
  dsu[get(u)] = get(v);
}
 
int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto solve = [&] () {
    int n;
    ll k;
    cin >> n >> k;
    vector <ll> fact(n + 1);
    fact[0] = 1;
    ll lim = k + (ll) (1e18);
    auto mul = [&] (ll a, ll b) {
      if (a * (long double) b <= lim)
        return a * b;
      else
        return lim;
    };
    for (int i = 1; i <= n; i++) {
      fact[i] = mul(fact[i - 1], i);
    }
    vector <ll> decomps(n + 1);
    vector <ll> values(n + 1);
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        values[i] = 1;
      } else {
        values[i] = fact[i - 2];
      }
    }
    decomps[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        decomps[i] += mul(decomps[j], values[i - j]);
        decomps[i] = min(decomps[i], lim);
      }
    }
    k--;
    if (decomps[n] <= k) {
      cout << -1 << '\n';
      return;
    }
    auto gen_cyclic = [&] (int len, ll id, int shift) {
      for (int i = 0; i < len; i++) {
        dsu[i] = i;
      }
      set <int> q;
      int pths = len - 1;
      vector <int> ans;
      for (int i = 0; i < len; i++) {
        if (i == 0) {
          q.insert(len - 1);
          uni(i, len - 1);
          ans.push_back(len - 1);
        } else {
          for (int j = 0; j < len; j++) {
            if (!q.count(j) && (get(i) != get(j) || i == len - 1)) {
              int go = pths;
              if (values[go] <= id) {
                id -= values[go];
              } else {
                pths--;
                ans.push_back(j);
                q.insert(j);
                uni(i, j);
                break;
              }
            }
          }
        }
      }
      for (int x : ans) {
        cout << shift + x + 1 << ' ';
      }
    };
    int x = 0;
    while (x < n) {
      for (int len = 1; len <= n - x; len++) {
        ll value = mul(values[len], decomps[n - x - len]);
        if (value <= k) {
          k -= value;
        } else {
          ll go = k / decomps[n - x - len];
          gen_cyclic(len, go, x);
          k %= decomps[n - x - len];
          x += len;
          break;
        }
      }
    }
    cout << '\n';
  };
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}