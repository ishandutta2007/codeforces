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
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] != '-') {
        rotate(s.begin(), s.begin() + i, s.end());
        break;
      }
    }
    bool a = false, b = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '<')a = true;
      if (s[i] == '>') b = true;
    }
    if (!a || !b) {
      cout << n << '\n';
    } else {
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
          int j = i;
          while (j < n && s[j] == '-') j++;
          ans += j - i + 1;
          i = j - 1;
        }
      }
      cout << ans << '\n';
    }
  }
}