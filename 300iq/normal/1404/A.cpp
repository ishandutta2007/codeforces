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
    vector <char> ans(k, '?');
    bool bad = false;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        if (ans[i % k] != '?' && ans[i % k] != s[i]) bad = true;
        ans[i % k] = s[i];
      }
    }
    if (bad) {
      cout << "NO\n";
    } else {
      int l = 0, r = 0;
      for (int i = 0; i < k; i++) {
        if (ans[i] == '?') {
          l--, r++;
        } else {
          if (ans[i] == '0') l++, r++;
          else l--, r--;
        }
      }
      if (l <= 0 && 0 <= r) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}