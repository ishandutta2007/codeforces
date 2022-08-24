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
    k++;
    string best = "";
    auto relax = [&] (int last_dig, int nines, int next, int rem) {
      string cur = "";
      cur += last_dig + '0';
      for (int i = 0; i < nines; i++) cur += '9';
      cur += next + '0';
      while (rem >= 9) {
        cur += '9';
        rem -= 9;
      }
      cur += rem + '0';
      while (cur.size() > 1 && cur.back() == '0') cur.pop_back();
      reverse(cur.begin(), cur.end());
      if (best.empty() || (cur.size() < best.size() || (cur.size() == best.size() && cur < best))) {
        best = cur;
      }
    };
    for (int last_dig = 0; last_dig < 10; last_dig++) {
      for (int nines = 0; 9 * nines <= n; nines++) {
        for (int next = 0; next < 9; next++) {
          int cur = last_dig + 9 * nines + next;
          int sum = 0;
          int dig = last_dig;
          for (int j = 0; j < k; j++) {
            sum += cur;
            cur++;
            dig++;
            if (dig == 10) {
              cur -= 9 * (nines + 1);
            }
          }
          if (sum <= n && (n - sum) % k == 0) {
            int rem = (n - sum) / k;
            relax(last_dig, nines, next, rem);
          }
        }
      }
    }
    if (best.empty()) cout << -1 << '\n';
    else cout << best << '\n';
  }
}