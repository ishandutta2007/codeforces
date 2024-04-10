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

const int N = 71;

bool prime[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i= 2; i < N; i++) prime[i] = true;
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = i + i; j < N; j += i) {
        prime[j] = false;
      }
    }
  }
  vector <int> p;
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      p.push_back(i);
    }
  }
  int n;
  cin >> n;
  map <int, int> rofl;
  rofl[0]++;
  int mod = 1e9 + 7;
  map <int, int> lol;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int ans = 1;
    int val = 0;
    for (int i = 0; i < (int) p.size(); i++) {
      while (x % p[i] == 0) {
        val ^= (1 << i);
        x /= p[i];
      }
    }
    lol[val]++;
  }
  for (auto c : lol) {
    ll x= 1;
    for (int i= 1; i < c.second; i++) {
      x = x * 2 % mod;
    }
    auto mda = c.first;
    auto nrofl = rofl;
    for (auto &c : nrofl) {
      c.second = (c.second * (ll) x) % mod;
    }
    for (auto c : rofl) {
      int nmda = mda ^ c.first;
      nrofl[nmda] += (c.second * x) % mod;
      if (nrofl[nmda] >= mod) nrofl[nmda] -= mod;
    }
    rofl = nrofl;
  }
  cout << rofl[0] - 1 << endl;
}