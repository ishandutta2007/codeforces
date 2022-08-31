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
  n--;
  string a, b;
  cin >> a >> b;
  auto f= [&] (char c) {
    if (c == 'N') return 'S';
    if (c == 'S') return 'N';
    if (c == 'E') return 'W';
    if (c == 'W') return 'E';
    assert(0);
  };
  for (int i = 0; i < n; i++) {
    a[i] = f(a[i]);
  }
  reverse(a.begin(), a.end());
  string s = a + "$" + b;
  int j = 0;
  vector <int> p(s.size());
  for (int i = 1; i < (int) s.size(); i++) {
    while (j && s[i] != s[j]) {
      j = p[j - 1];
    }
    j += (s[i] == s[j]);
    p[i] = j;
  }
  if (j) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}