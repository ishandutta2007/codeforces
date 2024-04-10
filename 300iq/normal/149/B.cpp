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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  string a = "", b = "";
  bool fl = false;
  for (auto c : s) {
    if (c == ':') {
      fl = true;
    } else{ 
      if (!fl) a += c;
      else b += c;
    }
  }
  auto dig = [&] (char c) {
    if ('0' <= c && c <= '9') {
      return c - '0';
    } else {
      return c - 'A' + 10;
    }
  };
  vector <int> ans;
  for (int t = 2; t <= 1000; t++) {
    bool bad = false;
    int x = 0;
    for (auto c : a) {
      if (dig(c) >= t) {
        bad = true;
      }
      if (x > 23) {
        bad = true;
        break;
      }
      x = x * t + dig(c);
    }
    int y = 0;
    for (auto c : b) {
      if (dig(c) >= t) {
        bad = true;
      }
      if (y > 59) {
        bad = true;
        break;
      }
      y = y * t + dig(c);
    }
    if (x <= 23 && y <= 59 && !bad) {
      ans.push_back(t);
    }
  }
  if (ans.size() >= 100) {
    cout << -1 << endl;
    return 0;
  }
  if (ans.empty()) {
    cout << 0 << endl;
    return 0;
  }
  for (int x : ans) cout << x << ' ';
  cout << endl;
}