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

string smart(vector <int> a) {
  int n = (int) a.size();
    vector <int> suf(n);
    vector <int> vl(n, n), vr(n, -1);
    vector <int> ex(n);
    vector <int> cnt(n);
    for (int i = 0; i < n; i++) {
      vl[a[i]] = min(vl[a[i]], i);
      vr[a[i]] = max(vr[a[i]], i);
      ex[a[i]] = 1;
      cnt[a[i]]++;
    }
    for (int i = n - 2; i >= 0; i--) {
      vl[i] = min(vl[i], vl[i + 1]);
      vr[i] = max(vr[i], vr[i + 1]);
    }
    int last = n - 1;
    int lg = n - 1;
    for (int i = 0; i < n; i++) {
      if (cnt[i] != 1) {
        lg = i - 1;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!ex[i]) {
        last = i - 1;
        break;
      }
    }
    vector <int> good(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        good[i] = 1;
      } else {
        if (a[i] > a[i - 1]) {
          good[i] = good[i - 1];
        } else {
          good[i] = 0;
        }
      }
    }
    vector <int> goodsuf(n);
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) {
        goodsuf[i] = 1;
      } else {
        if (a[i] > a[i + 1]) {
          goodsuf[i] = goodsuf[i + 1];
        } else {
          goodsuf[i] = 0;
        }
      }
    }
    string ret = "";
    for (int k = 1; k <= n; k++) {
      if (k == 1) {
        ret += (last == n - 1) + '0';
        continue;
      }
      int need = n - k;
      int len = vr[need] - vl[need] + 1;
      if (len == k && last >= need && lg >= need - 1) {
        if (!vl[need] || good[vl[need] - 1]) {
          if (vr[need] == n - 1 || goodsuf[vr[need] + 1]) {
            ret += '1';
          } else {
            ret += '0';
          }
        } else {
          ret += '0';
        }
      } else {
        ret += '0';
      }
    }
    return ret;
}

string stupid(vector <int> a) {
  int n = (int) a.size();
  string go = "";
  for (int k = 1; k <= n; k++) {
    vector <int> ret;
    for (int i = 0; i + k - 1 < n; i++) {
      int mn = a[i];
      for (int j = i; j < i + k; j++) mn = min(mn, a[j]);
      ret.push_back(mn);
    }
    sort(ret.begin(), ret.end());
    bool bad = false;
    for (int i = 1; i < (int) ret.size(); i++) if (ret[i] != ret[i - 1] + 1) bad = true;
    if (ret[0] == 0 && !bad) go += '1';
    else go += '0';
  }
  return go;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  /*
  while (true) {
    int n = rnd() % 10 + 1;
    vector <int> a(n);
    for (int i = 0; i < n; i++) a[i] = rnd() % n;
    if (smart(a) != stupid(a)) {
      cout << n << endl;
      for (int x : a) cout << x << ' ';
      cout << endl;
      cout << smart(a) << ' ' << stupid(a) << endl;
      return 0;
    }
  }
  */
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    cout << smart(a) << '\n';
  }
}