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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int tot = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        tot++;
      }
    }
    if (k >= tot) {
      cout << 2 * n - 1 << '\n';
    } else {
      vector <int> ptr;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
          ptr.push_back(i);
        }
      }
      if (ptr.empty()) {
        cout << max(0, 2 * k - 1) << '\n';
      } else {
        vector <pair <int, int> > e;
        for (int i = 1; i < (int) ptr.size(); i++) {
          int l = ptr[i - 1], r = ptr[i];
          e.push_back({r - l - 1 , i - 1});
        }
        sort(e.begin(), e.end());
        for (auto c : e) {
          int vl = ptr[c.second] + 1;
          int vr = ptr[c.second + 1] - 1;
          for (int x = vl; x <= vr; x++) {
            if (k) {
              k--;
              s[x] = 'W';
            }
          }
        }
        int a = ptr[0], b = ptr.back();
        if (a < n - 1 - b) {
          for (int i = a - 1; i >= 0; i--) {
            if (k) {
              k--;
              s[i] = 'W';
            }
          }
          for (int i = b + 1; i < n; i++) {
            if (k) {
              k--;
              s[i] = 'W';
            }
          }
        } else {
          for (int i = b + 1; i < n; i++) {
            if (k) {
              k--;
              s[i] = 'W';
            }
          }
          for (int i = a - 1; i >= 0; i--) {
            if (k) {
              k--;
              s[i] = 'W';
            }
          }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) if (s[i] == 'W') ans++;
        for (int i = 1; i < n; i++) if (s[i] == 'W' && s[i - 1] == 'W') ans++;
        cout << ans << '\n';
      }
    }
  }
}