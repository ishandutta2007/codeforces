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
  int a, b;
  cin >> a >> b;
  int k, m;
  cin >> k >> m;
  vector <int> x, y;
  for (int i = 0; i < a; i++) {
    int l;
    cin >> l;
    x.push_back(l);
  }
  for (int i = 0; i < b; i++) {
    int l;
    cin >> l;
    y.push_back(l);
  }
  sort(x.begin(), x.end());
  sort(y.rbegin(), y.rend());
  if (x[k - 1] < y[m - 1]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}