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
    map <char, int> cnt;
    for (auto c : s) cnt[c]++;
    for (int ans = n; ans >= 1; ans--) {
      int grab = ans + 1;
      for (int i = 1; i <= ans; i++) {
        if ((i * k) % ans == 0) {
          grab = i;
          break;
        }
      }
      int sum = 0;
      for (auto z : cnt) {
        sum += z.second - z.second % grab;
      }
      if (sum >= ans) {
        cout << ans << '\n';
        break;
      }
    }
  }
}