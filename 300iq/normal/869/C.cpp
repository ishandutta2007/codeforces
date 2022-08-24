#include <cmath>
#include <functional>
#include <fstream>
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

const int N = 5020;
const int mod = 998244353;

int comb[N][N];
int fact[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1;
  for (int i= 1; i < N; i++) {
    fact[i] = (fact[i - 1] * (ll) i) % mod;
  }
  comb[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i) comb[i][j] += comb[i - 1][j];
      if (i && j) comb[i][j] += comb[i - 1][j - 1];
      if (comb[i][j] >= mod) comb[i][j] -= mod;
    }
  }
  int a, b, c;
  cin >> a >> b >> c;
  auto solve = [&] (int a, int b) {
    int sum = 0;
    for (int k = 0; k <= min(a, b); k++) {
      ll val = (comb[a][k] * (ll) comb[b][k]) % mod;
      val = (val * (ll) fact[k]) % mod;
      sum += val;
      if (sum >= mod) sum -= mod;
    }
    return sum;
  };
  int ret = solve(a, b);
  ret = (ret * (ll) solve(b, c)) % mod;
  ret = (ret * (ll) solve(a, c)) % mod;
  cout << ret << '\n';
}