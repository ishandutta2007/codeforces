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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  auto f= [&] (int a, int b) {
    return a * (ll) a * (ll) b;
  };
  auto cost = [&] (int x, int t) {
    int val_a = x / t;
    int cnt_a = t - (x % t);
    int val_b = x / t + 1;
    int cnt_b = x % t;
    return f(val_a, cnt_a) + f(val_b, cnt_b);
  };
  vector <int> cur(n);
  ll sum = 0;
  set <pair <ll, int> > q;
  for (int i = 0; i < n; i++) {
    cur[i] = 1;
    sum += cost(a[i], 1);
    if (a[i] >= 2) {
      q.insert({cost(a[i], 2) - cost(a[i], 1), i});
    }
  }
  int tot = n;
  while (tot < k) {
    tot++;
    assert(!q.empty());
    int i = q.begin()->second;
    q.erase(q.begin());
    sum += cost(a[i], cur[i] + 1) - cost(a[i], cur[i]);
    cur[i]++;
    if (cur[i] + 1 <= a[i]) {
      q.insert({cost(a[i], cur[i] + 1) - cost(a[i], cur[i]), i});
    }
  }
  cout << sum << '\n';
}