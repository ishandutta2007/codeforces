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

ll gcd(ll a, ll b) {
  if (b) return gcd(b, a% b);
  return a;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    ll k;
    cin >> n >> k;
    vector <ll> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    sort(x.begin(), x.end());
    ll g = 0;
    for (int i = 1; i < n; i++) g = gcd(g, x[i] - x[i - 1]);
    bool good = (x[0] - k) % g == 0;
    /*
    if (n == 1) {
      good = (x[0] == k);
    } else {
      ll g = x[0];
      for (int i = 1; i < n; i++) {
        g = gcd(g, x[i]);
      }
      good = (k % g == 0);
    }
    */
    cout << (good ? "YES" : "NO") << '\n';
  }
}