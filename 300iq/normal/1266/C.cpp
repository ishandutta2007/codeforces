#include <cmath>
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
  int n, m;
  cin >> n >> m;
  vector <int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    arr[i] = i;
  }
  vector <int> brr(m + 1);
  for (int i = 1; i <= m; i++) {
    brr[i] = i;
  }
  if (n == 1 && m == 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (n == 1) {
    for (int i = 1; i <= m; i++) cout << i + 1 << ' ';
    cout << endl;
    return 0;
  } else {
    if (m == 1) {
      for (int i = 1; i <= n; i++) {
        cout << i + 1 << '\n';
      }
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int a = i, b = n + j;
      cout << a * b / __gcd(a, b) << ' ';
    }
    cout << '\n';
  }
}