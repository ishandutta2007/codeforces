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
    string s;
    cin >> s;
    int j = (int) s.size();
    int ans = 0;
    for (int i = (int) s.size() - 1; i >= 0; i--) {
      if (s[i] != '0') j = i;
      int val = 0;
      for (int x = j; x < j + 100 && x < (int) s.size(); x++) {
        val = val * 2 + s[x] - '0';
        if (val > (int) s.size()) break;
        if (val == x - i + 1) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}