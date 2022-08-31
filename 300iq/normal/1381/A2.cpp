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
    string a, b;
    cin >> a >> b;
    for (auto &c : a) c -= '0';
    for (auto &c : b) c -= '0';
    int last = n - 1;
    auto f = [&] (int c) {
      return 1 - c;
    };
    vector <int> ans;
    int l = 0, r = n - 1;
    bool rev = false;
    bool flip = false;
    auto get_first = [&] () {
      if (!rev) return a[l] ^ flip;
      else return a[r] ^ flip;
    };
    auto get_last = [&] () {
      if (!rev) return a[r] ^ flip;
      else return a[l] ^ flip;
    };
    for (int it = 0; it < n; it++) {
      if (get_last() == b[last]) {
        last--;
        if (rev) l++;
        else r--;
      } else {
        if (get_first() != get_last()) {
          ans.push_back(1);
          if (rev) a[r] ^= 1;
          else a[l] ^= 1;
        }
        ans.push_back(last + 1);
        if (!rev) l++;
        else r--;
        flip ^= 1;
        rev ^= 1;
        last--;
      }
    }
    cout << ans.size() << ' ';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
}