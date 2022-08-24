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
  int k;
  cin >> k;
  int x = 0;
  while ((1 << x) <= k) x++;
  int n = 3;
  vector <vector <int> > a(n, vector <int> (n));
  a[0][0] = k + (1 << x);
  a[0][1] = k;
  a[0][2] = k;
  a[1][0] = (1 << x);
  a[1][1] = (1 << x);
  a[1][2] = k + (1 << x);
  a[2][2] = k;
  cout << n << ' ' << n << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}