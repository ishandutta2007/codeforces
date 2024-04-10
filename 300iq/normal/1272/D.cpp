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
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector <int> dp_a(n), dp_b(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp_a[i] = 1, dp_b[i] = 1;
    if (i && a[i] > a[i - 1]) {
      dp_b[i] = max(dp_b[i], dp_b[i - 1] + 1);
      dp_a[i] = max(dp_a[i], dp_a[i - 1] + 1);
    }
    if (i >= 2 && a[i] > a[i - 2]) {
      dp_b[i] = max(dp_b[i], dp_a[i - 2] + 1);
    }
    ans = max(ans, dp_b[i]);
  }
  cout << ans << '\n';
}