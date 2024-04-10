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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> a(n);
    vector <pair <pair <int, int>, ll > > ans;
    vector <pair <int, int> > need;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n) {
      cout << -1 << '\n';
      continue;
    }
    ll x = sum / n;
    int good = -1;
    vector <pair <int, int> > e;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] >= (i + 1)) {
        good = i;
        break;
      }
      e.push_back({(i + 1) - a[i], i});
    }
    sort(e.begin(), e.end());
    if (good != -1) {
      int i = good;
      ans.push_back({{i, 0}, 1});
      a[i] -= (i + 1);
      a[0] += (i + 1);
      for (int i = good; i > 0; i--) {
        ll need = (i + 1) - a[i] % (i + 1);
        ans.push_back({{0, i}, need});
        ans.push_back({{i, 0}, a[i] / (i + 1) + 1});
        a[0] += a[i];
        a[i] = 0;
      }
    }
    for (auto c : e) {
      if (a[0] >= c.first) {
        int i = c.second;
        ans.push_back({{0, i}, c.first});
        ans.push_back({{i, 0}, 1});
        a[0] += a[i];
        a[i] = 0;
      } else {
        break;
      }
    }
    bool bad = false;
    for (int i = 1; i < n; i++) {
      if (a[i] != 0 && a[i] != x) {
        bad = true;
      }
    }
    if (bad) {
      cout << -1 << '\n';
    } else {
      for (int i = 1; i < n; i++) {
        if (a[i] != x) {
          ans.push_back({{0, i}, x});
        }
      }
      cout << ans.size() << '\n';
      for (auto c : ans) {
        cout << c.first.first + 1 << ' ' << c.first.second + 1 << ' ' << c.second << '\n';
      }
    }
  }
}