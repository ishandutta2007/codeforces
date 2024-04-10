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

const int N = 1e7 + 7;

int prime[N];
int l[N], r[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) {
    if (!prime[i]) {
      prime[i] = i;
      for (int j = i + i; j < N; j += i) {
        prime[j] = i;
      }
    }
  }
  int n, m;
  cin >> n >> m;
  vector <int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int x : a) {
    while (x != 1) {
      l[prime[x]]++;
      x /= prime[x];
    }
  }
  vector <int> t;
  for (int x : b) {
    int ans = 1;
    while (x != 1) {
      if (l[prime[x]]) {
        r[prime[x]]++;
        l[prime[x]]--;
      } else {
        ans *= prime[x];
      }
      x /= prime[x];
    }
    t.push_back(ans);
  }
  vector <int> d;
  for (int x : a) {
    int ans = 1;
    while (x != 1) {
      if (r[prime[x]]) {
        r[prime[x]]--;
      } else {
        ans *= prime[x];
      }
      x /= prime[x];
    }
    d.push_back(ans);
  }
  cout << n << ' ' << m << '\n';
  for (int x : d) cout << x << ' ';
  cout << '\n';
  for (int x : t) cout << x << ' ';
  cout << '\n';
}