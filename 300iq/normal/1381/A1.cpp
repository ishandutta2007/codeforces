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
    int last = n - 1;
    auto f = [&] (char c) {
      if (c == '0') return '1';
      else return '0';
    };
    vector <int> ans;
    for (int it = 0; it < n; it++) {
      if (a[last] == b[last]) {
        last--;
      } else {
        if (a[0] != a[last]) {
          ans.push_back(1);
          a[0] = f(a[0]);
        }
        ans.push_back(last + 1);
        reverse(a.begin(), a.begin() + last + 1);
        for (int i = 0; i <= last; i++) {
          a[i] = f(a[i]);
        }
        last--;
      }
    }
    cout << ans.size() << ' ';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
}