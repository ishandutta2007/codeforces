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
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum == 0) {
      cout << "NO\n";
    } else {
      int sum_pos = 0, sum_neg = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
          sum_pos += a[i];
        } else if (a[i] < 0) {
          sum_neg -= a[i];
        }
      }
      cout << "YES\n";
      if (sum_pos > sum_neg) {
        for (int i = 0; i < n; i++) if (a[i] > 0) cout << a[i] << ' ';
        for (int i = 0; i < n; i++) if (a[i] < 0) cout << a[i] << ' ';
        for (int i = 0; i < n; i++) if (a[i] == 0) cout << a[i] << ' ';
        cout << '\n';
      } else {
        for (int i = 0; i < n; i++) if (a[i] < 0) cout << a[i] << ' ';
        for (int i = 0; i < n; i++) if (a[i] > 0) cout << a[i] << ' ';
        for (int i = 0; i < n; i++) if (a[i] == 0) cout << a[i] << ' ';
        cout << '\n';
      }
    }
  }
}